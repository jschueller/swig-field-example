// SWIG file FieldFunction.i

%{
#include "FieldFunction.hxx"
#include "PythonFieldFunction.hxx"
%}

%include FieldFunction.hxx

namespace OT { %extend FieldFunction { 

FieldFunction(const FieldFunction & other) { return new OT::FieldFunction(other); } 

FieldFunction(PyObject * pyObj)
{
  void * ptr = 0;
  if (SWIG_IsOK(SWIG_ConvertPtr(pyObj, &ptr, SWIGTYPE_p_OT__FieldFunction, 0)))
  {
    throw;// OT::InvalidArgumentException(HERE) << "Argument should be a pure python object";
  }
  return new OT::FieldFunction(new OT::PythonFieldFunction(pyObj));
}


} }
