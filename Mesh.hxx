#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX

namespace OT {
  class Mesh
  {
  public:
    Mesh() : nVertices_(0) {}
    int getNVertices() const {return nVertices_;}
  private:
    int nVertices_;
  };
}

#endif
