#include"complexvector1.hpp"
#include"FactoryHori.hpp"

	bool CCompexVectorHori :: output(const string& path) {
			 ofstream out;          // поток для записи
			 out.open(path); // окрываем файл для записи
			if (out.is_open()) {
				for(int i=0; i<this->size(); i++) {
					this->dat()[i].i()>=0 ? out<<this->dat()[i].r()<<"+"<<dat()[i].i()<<"i"<<"   " :
							out<<this->dat()[i].r()<<dat()[i].i()<<"i"<<"   ";

				}
				return true;
			}
			return false;
		}

