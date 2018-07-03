// SWIG file Mesh.i

%{
#include "Mesh.hxx"
%}

%include Mesh.hxx

namespace OT { %extend Mesh { Mesh(const Mesh & other) { return new OT::Mesh(other); } } }
