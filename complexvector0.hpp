#ifndef CCOMPLEXVECTOR0_H
#define CCOMPLEXVECTOR0_H
#include "complexvector.hpp"
#include"complexvector1.hpp"
#include "omp.h"
#include<chrono>

class CCompexVectorVert :public CCompexVector{
	public:
	CCompexVectorVert(int l, const string& path) : CCompexVector(l, path) {}
	CCompexVectorVert() : CCompexVector() {}
	CCompexVectorVert(const CCompexVector& copy):CCompexVector( copy) {}
	virtual bool output(const string& path);
	using CCompexVector::operator = ;
	//CCompexVectorVert essense();
};

CCompexVector& operator + (const CCompexVector& a,const CCompexVector& b) ;

CCompexVector& operator - (const CCompexVector& a, const CCompexVector& b) ;


#endif // CCOMPLEXVECTOR0_H

