#ifndef OPENTURNS_MESH_HXX
#define OPENTURNS_MESH_HXX

#include <stdexcept>
#include <iostream>

namespace OT {
  
  typedef bool Bool;
  
  class PersistentObject
  {
  public:
    PersistentObject() {}

    virtual ~PersistentObject() {}

    inline virtual
    Bool operator ==(const PersistentObject & /*other*/) const
    {
      std::cout << "PersistentObject operator =="<<std::endl;
      return true;
    }

    virtual std::string __repr__() const {return "PersistentObject"; }

    inline virtual
    Bool operator !=(const PersistentObject & other) const
    {
      std::cout << "PersistentObject operator !="<<std::endl;
      return !operator==(other);
    }
  };

  class DistributionImplementation : public PersistentObject
  {
  public:
    DistributionImplementation() : PersistentObject() {}

    std::string __repr__() const override {return "DistributionImplementation"; }
    
    /** Comparison operator */
#ifndef BUGHEREDROPME___SWIG
  protected:
    using PersistentObject::operator ==;
  public:
#endif
    Bool operator ==(const DistributionImplementation & other) const
    {
      std::cout << "DistributionImplementation operator == this="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      if (this == &other) return true;
      // Compare both this to other and other to this to ensure symmetry
      return equals(other) && other.equals(*this);
    }
    
  protected:
    using PersistentObject::operator !=;
  public:
    Bool operator !=(const DistributionImplementation & other) const
    {
      std::cout << "DistributionImplementation operator != this="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      return !operator==(other);
    }
    protected:
    virtual Bool equals(const DistributionImplementation & /*other*/) const {throw std::runtime_error("notyet"); }
  };
  
  class Uniform : public DistributionImplementation
  {
  public:
    Uniform(double a = 0., double b = 1.) : DistributionImplementation(), a_(a), b_(b) {}

    using DistributionImplementation::operator ==;
    Bool operator ==(const Uniform & other) const
    {
      if (this == &other) return true;
      return a_ == other.a_ && b_ == other.b_;
    }
    
    std::string __repr__() const override {return "Uniform";}
    
  protected:
    Bool equals(const DistributionImplementation & other) const override
    {
      std::cout << "Uniform equals="<<this->__repr__() << " other=" << other.__repr__()<<std::endl;
      const Uniform* p_other = dynamic_cast<const Uniform*>(&other);
      return p_other && (*this == *p_other);
    }

  private:
    double a_ = 0.;
    double b_ = 1.;
  };
  
  class Gumbel : public DistributionImplementation
  {
  public:
    Gumbel(double beta = 0., double gamma = 1.) : DistributionImplementation(), beta_(beta), gamma_(gamma) {}

    using DistributionImplementation::operator ==;
    Bool operator ==(const Gumbel & other) const
    {
      if (this == &other) return true;
      // Compare both this to other and other to this to ensure symmetry
      return beta_ == other.beta_ && gamma_ == other.gamma_;
    }

    std::string __repr__() const override {return "Gumbel";}
  protected:
    Bool equals(const DistributionImplementation & other) const override
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
