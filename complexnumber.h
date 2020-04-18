#include<iostream>
#include<string>
#include<sstream>
#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
//#pragma once
using namespace std;
class Complex {
public:
	Complex();
	Complex(int re, int im);
	Complex(int re);
	int r() const ;
	int i() const ;
	Complex& operator = (const Complex& a);
private:
	int real;
	int imag;
};

Complex operator + (const Complex& a, const Complex& b);

Complex operator - (const Complex& a, const Complex& b);

Complex operator * (const Complex& a, const Complex& b);

#endif // COMPLEXNUMBER_H
