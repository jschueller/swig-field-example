#ifndef OPENTURNS_FIELDFUNCTION_HXX
#define OPENTURNS_FIELDFUNCTION_HXX

#include "FieldFunctionImplementation.hxx"

namespace OT {
  class FieldFunction
  {
  public:
    FieldFunction();
    FieldFunction(FieldFunctionImplementation * p_impl);
//     FieldFunction(const FieldFunction & other);
  protected:
    FieldFunctionImplementation * p_impl_;
  };
}

#endif
