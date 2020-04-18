#ifndef __FACTORY_HPP_INCLUDED__
#define __FACTORY_HPP_INCLUDED__

#include <memory>
#include "complexvector.hpp"



  class Factory {
  public:
    virtual CCompexVector* Create() = 0;
    virtual CCompexVector* Create(unsigned int l, const string& line) = 0;
	virtual CCompexVector* Create(const CCompexVector& copy) = 0;

    Factory() = default;
    virtual ~Factory() = default;
  };



#endif // __FACTORY_HPP_INCLUDED__
