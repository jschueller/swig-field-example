#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX

namespace OT {
  class Mesh
  {
  public:
    Mesh();
    int getNVertices() const;
  private:
    int nVertices_;
  };
}

#endif
