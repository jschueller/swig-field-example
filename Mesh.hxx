#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX

#include <stdexcept>
#include <iostream>

namespace OT {
    
  class Object
  {
  public:
    Object() {}

    virtual ~Object() {}

    inline virtual
    bool operator ==(const Object & /*other*/) const
    {
      std::cout << "Object operator =="<<std::endl;
      return true;
    }

    virtual std::string __repr__() const {return "Object"; }

    inline virtual
    bool operator !=(const Object & other) const
    {
      std::cout << "Object operator !="<<std::endl;
      return !operator==(other);
    }
  };

  class Distribution : public Object
  {
  public:
    Distribution() : Object() {}

    std::string __repr__() const override {return "Distribution"; }
    
    /** Comparison operator */
// #ifndef SWIG
    using Object::operator ==;
// #endif
    bool operator ==(const Distribution & other) const
    {
      std::cout << "Distribution operator == this="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      if (this == &other) return true;
      // Compare both this to other and other to this to ensure symmetry
      return equals(other) && other.equals(*this);
    }
    
  protected:
    using Object::operator !=;
  public:
    bool operator !=(const Distribution & other) const
    {
      std::cout << "Distribution operator != this="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      return !operator==(other);
    }
    protected:
    virtual bool equals(const Distribution & /*other*/) const {throw std::runtime_error("notyet"); }
  };
  
  class Uniform : public Distribution
  {
  public:
    Uniform(double a = 0., double b = 1.) : Distribution(), a_(a), b_(b) {}

    using Distribution::operator ==;
    bool operator ==(const Uniform & other) const
    {
      if (this == &other) return true;
      return a_ == other.a_ && b_ == other.b_;
    }
    
    std::string __repr__() const override {return "Uniform";}
    
  protected:
    bool equals(const Distribution & other) const override
    {
      std::cout << "Uniform equals="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      const Uniform* p_other = dynamic_cast<const Uniform*>(&other);
      return p_other && (*this == *p_other);
    }

  private:
    double a_ = 0.;
    double b_ = 1.;
  };
  
  class Gumbel : public Distribution
  {
  public:
    Gumbel(double beta = 0., double gamma = 1.) : Distribution(), beta_(beta), gamma_(gamma) {}

    using Distribution::operator ==;
    bool operator ==(const Gumbel & other) const
    {
      if (this == &other) return true;
      // Compare both this to other and other to this to ensure symmetry
      return beta_ == other.beta_ && gamma_ == other.gamma_;
    }

    std::string __repr__() const override {return "Gumbel";}
  protected:
    bool equals(const Distribution & other) const override
    {
      std::cout << "Gumbel equals="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      const Gumbel* p_other = dynamic_cast<const Gumbel*>(&other);
      return p_other && (*this == *p_other);
    }
  private:
    double beta_ = 0.;
    double gamma_ = 1.;
  };

}

#endif
