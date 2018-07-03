// SWIG file FieldFunctionImplementation.i

%{
#include "FieldFunctionImplementation.hxx"
%}

%include FieldFunctionImplementation.hxx

namespace OT { %extend FieldFunctionImplementation {

FieldFunctionImplementation(const FieldFunctionImplementation & other) { return new OT::FieldFunctionImplementation(other); } 

} }
