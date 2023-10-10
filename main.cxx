#include "Mesh.hxx"

int main() {
  OT::Uniform d1(2,5);
  OT::Gumbel d2(3,4);
std::cout << (d1 == d2)<<std::endl;
std::cout << (d1 != d2)<<std::endl;
std::cout << "OK"<<std::endl;
  return 0;
}
