#include"complexvector0.hpp"
#include"FactoryVert.hpp"


	bool CCompexVectorVert :: output(const string& path) {
		 ofstream out;          // поток для записи
		 out.open(path); // окрываем файл для записи
		if (out.is_open()) {
			for(long long unsigned int i=0; i<this->size(); i++) {
				this->dat()[i].i()>=0 ? out<<this->dat()[i].r()<<"+"<<dat()[i].i()<<"i"<<endl :
						out<<this->dat()[i].r()<<dat()[i].i()<<"i"<<endl;

			}
			return true;
		}
		return false;
	}
/*
CCompexVector&  operator + (const CCompexVector& a,const CCompexVector& b) {
FactoryVert factory;
auto res = factory.Create(a);
int size = 0;
auto start = chrono::system_clock::now();
if (a.size() >= b.size()) {
auto res = factory.Create(a);
size = b.size();
ptrdiff_t i = 0;
for (i = 0; i < size; ++i) {
res->add(i, a);
res->add(i, b);
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
} else {
auto res = factory.Create(b);
size = a.size();
ptrdiff_t i = 0;
for (i = 0; i < size; ++i) {
	res->add(i, a);
	res->add(i, b);
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
}

CCompexVector&  operator - (const CCompexVector& a, const CCompexVector& b) {

	FactoryVert factory;
	auto* res = factory.Create();
	if(a.size()>=b.size()){
			for(int i=0; i<b.size(); i++){
				res->push_back(a.dat()[i]-b.dat()[i]);
			}
			for(int i=b.size(); i<a.size(); i++){
				res->push_back(a.dat()[i]);
			}
		
	} else {
			for(int i=0; i<a.size(); i++){
				res->push_back(a.dat()[i]-b.dat()[i]);
			}
			for(int i=a.size(); i<b.size(); i++){
				res->push_back(0-b.dat()[i]);
			}
		
}
	return *res;
}

*/

///*
CCompexVector&  operator + (const CCompexVector& a,const CCompexVector& b) {
FactoryVert factory;
auto res = factory.Create();
int size = 0;
omp_set_num_threads(4);
auto start = chrono::system_clock::now();
if (a.size() >= b.size()) {
auto res = factory.Create(a);
size = b.size();
ptrdiff_t i = 0;
#pragma omp parallel for shared(res, a, b, size) private(i)
for (i = 0; i < size; ++i) {
res->add(i, a);
res->add(i, b);
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
} else {
auto res = factory.Create(b);
size = a.size();
ptrdiff_t i = 0;
#pragma omp parallel for shared(res, a, b, size) private(i)
for (i = 0; i < size; ++i) {
res->add(i, a);
res->add(i, b);
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
}
auto end = std::chrono::system_clock::now();
int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
return *res;
}


CCompexVector&  operator - (const CCompexVector& a, const CCompexVector& b) {

FactoryVert factory;
auto* res = factory.Create();
if(a.size()>=b.size()){
ptrdiff_t i = 0;
omp_set_num_threads(4);
#pragma omp parallel for shared(res, a, b) private(i)
for(i=0; i<b.size(); i++){
res->push_back(a.dat()[i]-b.dat()[i]);
}
omp_set_num_threads(4);
#pragma omp parallel for shared(res, a, b) private(i)
for(i=b.size(); i<a.size(); i++){
res->push_back( a.dat()[i]);
}

} else {
ptrdiff_t i = 0;
omp_set_num_threads(4);
#pragma omp parallel for shared(res, a, b) private(i)
for(i=0; i<a.size(); i++){
res->push_back(a.dat()[i]-b.dat()[i]);
}
omp_set_num_threads(4);
#pragma omp parallel for shared(res, a, b) private(i)
for(i=a.size(); i<b.size(); i++){
res->push_back(0-b.dat()[i]);
}

}
return *res;
}
//*/