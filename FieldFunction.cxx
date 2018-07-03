
#include "FieldFunction.hxx"

namespace OT {

FieldFunction::FieldFunction() :p_impl_(new FieldFunctionImplementation)
{}

FieldFunction::FieldFunction(FieldFunctionImplementation * p_impl_) : p_impl_(p_impl_)
{}

// FieldFunction::FieldFunction() :p_impl_(new FieldFunctionImplementation(*other.p_impl_))
// {}

}

