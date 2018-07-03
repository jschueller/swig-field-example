#include <Python.h>
#include "swig_runtime.hxx"
#include "PythonFieldFunction.hxx"
#include <iostream>

namespace OT {
PythonFieldFunction::PythonFieldFunction()
: pyObj_(0)
{}

PythonFieldFunction::PythonFieldFunction(PyObject * pyCallable)
: pyObj_(pyCallable)
{
  Py_XINCREF(pyCallable);

  PyObject * inputMesh = PyObject_CallMethod(pyObj_, const_cast<char *>("getInputMesh"), const_cast<char *>("()"));
  std::cout << "inputMesh="<<inputMesh<<" none="<<Py_None<< std::endl;
  void * ptr = 0;
  if (SWIG_IsOK(SWIG_ConvertPtr(inputMesh, &ptr, SWIG_TypeQuery("OT::Mesh *"), 0)))
  {
    inputMesh_ = *reinterpret_cast< OT::Mesh * >(ptr);
  }
  else
  {
    throw;
  }
  Py_XDECREF(inputMesh);
}

}

