#include "complexnumber.h"

	Complex::Complex(){
		real=0;
		imag=0;
	}
	Complex::Complex(int re, int im){
		real=re;
		imag=im;
	}
	Complex::Complex(int re){
		real=re;
		imag=0;
	}
	int Complex::r() const { return real;}
	int Complex::i() const { return imag;}
	Complex& Complex::operator = (const Complex& a){
		this->real=a.r();
		this->imag=a.i();
		return *this;
	}

Complex operator + (const Complex& a, const Complex& b){
	Complex res (a.r()+b.r(),a.i()+b.i());
	return res;
}

Complex operator - (const Complex& a, const Complex& b){
	Complex res (a.r()-b.r(),a.i()-b.i());
	return res;
}

Complex operator * (const Complex& a, const Complex& b){
	Complex res (a.r()*b.r()-a.i()*b.i(),a.r()*b.i()+a.i()*b.r());
	return res;
}

