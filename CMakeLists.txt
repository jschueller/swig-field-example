cmake_minimum_required (VERSION 3.1.0)

if (NOT DEFINED CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Build type")
endif ()


project(field-example)

set (CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_library (OT SHARED FieldFunction.cxx FieldFunctionImplementation.cxx Mesh.cxx)

install (TARGETS OT DESTINATION lib)



find_package (PythonInterp REQUIRED)
find_package (PythonLibs REQUIRED)
if (NOT DEFINED PYTHON_SITE_PACKAGES)
  set(PYTHON_SITE_PACKAGES lib/python${PYTHON_VERSION_MAJOR}.${PYTHON_VERSION_MINOR}/site-packages)
endif ()

find_package (SWIG REQUIRED)
include (${SWIG_USE_FILE})

add_custom_command (OUTPUT  ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMAND ${SWIG_EXECUTABLE}
                     ARGS -python -c++ ${CMAKE_SWIG_FLAGS} -external-runtime ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx
                     COMMENT "Swig header")
add_custom_target (generate_swig_runtime DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/swig_runtime.hxx)


set_property(SOURCE openturns.i PROPERTY CPLUSPLUS ON)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PYTHON_INCLUDE_DIRS})
# set_property(SOURCE Mesh.i PROPERTY CPLUSPLUS ON)
# set_property(SOURCE FieldFunction.i PROPERTY CPLUSPLUS ON)
swig_add_library (openturns LANGUAGE python SOURCES openturns.i PythonFieldFunction.cxx)
add_dependencies (${SWIG_MODULE_openturns_REAL_NAME} generate_swig_runtime)
target_link_libraries (${SWIG_MODULE_openturns_REAL_NAME} OT)

install (TARGETS ${SWIG_MODULE_openturns_REAL_NAME} DESTINATION ${PYTHON_SITE_PACKAGES})
install (FILES ${CMAKE_CURRENT_BINARY_DIR}/openturns.py DESTINATION ${PYTHON_SITE_PACKAGES})