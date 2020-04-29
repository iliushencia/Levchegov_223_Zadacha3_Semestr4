#include "complexvector.hpp"

	CCompexVector::CCompexVector(int l, const string& line) {
			len=0;
			data = new Complex[l];
			int re=0, im=0;
			char sign = ' ';
			stringstream ss(line);
			string num = "";
			ss>>num>>num>>num;
			for (int i=0; i<l; i++) {
			ss>>num;
			stringstream nn(num);
			nn>>re>>sign>>im;
			if(sign=='-') im=-im;
			Complex num (re,im);
			data[len]=num;
			len++;
			}
	}

	CCompexVector::CCompexVector() {
		len=0;
		data = new Complex;
	}

	CCompexVector::~CCompexVector() {
		delete[] data;
	}

	void CCompexVector::push_back(const Complex& num) {
		Complex* old = data;
		data = new Complex [len+1];
		for (int i = 0; i<len; i++){
			data[i]=old[i];
		}
		data[len]=num;
		len++;
		delete[] old;
	}
	CCompexVector& CCompexVector::operator = (const CCompexVector& a) {
		this->len=a.len;
		this->data=a.data;
		return *this;
	}
	int CCompexVector::size() const {
		return len;
	}
	Complex* CCompexVector::dat() const {
		return data;
	}

Complex operator * (const CCompexVector& a, const CCompexVector& b) {
	Complex res=0;
	if(a.size()>=b.size()){
		for(int i=0; i<b.size(); i++){
			res=res+a.dat()[i]*b.dat()[i];
		}
	} else {
		for(int i=0; i<a.size(); i++){
			res=res+a.dat()[i]*b.dat()[i];
		}
	}
	return res;
}

CCompexVector::CCompexVector(const CCompexVector& copy) {
	data = new Complex [copy.size()];
	len = copy.size();
}
void CCompexVector:: add(int i, const CCompexVector& a) {
	data[i] = data[i] + a.dat()[i];
}

void CCompexVector::sub(int i, const CCompexVector& a) {
	data[i] = data[i] - a.dat()[i];
}