#ifndef __FACTORYVERT_HPP_INCLUDED__
#define __FACTORYVERT_HPP_INCLUDED__

#include "Factory.hpp"

  class FactoryVert : public Factory {
  public:
		CCompexVector* Create() {
      return new CCompexVectorVert();
    }
	    CCompexVector* Create(unsigned int l, const string& line) {
	    	return new CCompexVectorVert(l,line);
	    }
		CCompexVector* Create(const CCompexVector& copy) {
			return new CCompexVectorVert(copy);
		}
    FactoryVert() = default;
    ~FactoryVert() = default;
  };



#endif // __FACTORYVERT_HPP_INCLUDED__
