#ifndef OPENTURNS_PYTHONFIELDFUNCTION_HXX
#define OPENTURNS_PYTHONFIELDFUNCTION_HXX

#include "Python.h"
#include "FieldFunctionImplementation.hxx"

namespace OT {
  class PythonFieldFunction : public FieldFunctionImplementation
  {
  public:
    PythonFieldFunction();

    explicit PythonFieldFunction(PyObject * pyCallable);

  private:
    PyObject * pyObj_;
  };
}

#endif
