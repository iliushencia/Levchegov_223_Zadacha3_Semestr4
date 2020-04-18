#ifndef CCOMPLEXVECTOR1_H
#define CCOMPLEXVECTOR1_H
#include "complexvector.hpp"

class CCompexVectorHori :public CCompexVector{
	public:
	CCompexVectorHori(int l, const string& path) : CCompexVector(l, path) {}
	CCompexVectorHori() : CCompexVector() {}
	CCompexVectorHori(const CCompexVector& copy) : CCompexVector(copy) {}
	virtual bool output(const string& path) ;
	using CCompexVector::operator = ;
};

#endif // CCOMPLEXVECTOR1_H
