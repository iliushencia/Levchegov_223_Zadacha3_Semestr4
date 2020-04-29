#include<iostream>
#include<string>
#include<vector>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"Factory.hpp"
#include"FactoryHori.hpp"
#include"FactoryVert.hpp"
using namespace std;

bool autotest1() {
	ofstream in;          // поток для записи
	in.open("test1.txt");
	in << "hori 5 none.txt 1+1i 2+2i 3+3i 4+4i 5+5i" << endl << "vert 5 none.txt -1-1i -2-2i -3-3i -4-4i -5-5i";
	in.close();
	vector<CCompexVector*> res = {};
	vector<string> paths = {};
	int count = 0;
	string check = "", path = "test1.txt";
	ifstream input(path);
	if (input.is_open()) {
		string line;
		while (getline(input, line)) {
			string type = "", path = "";
			int l = 0;
			stringstream ss(line);
			ss >> type >> l >> path;
			paths.push_back(path);
			if (type == "vert") {
				FactoryVert fucc;
				res.push_back(fucc.Create(l, line));
				count++;
			}
			else if (type == "hori") {
				FactoryHori fucc;
				res.push_back(fucc.Create(l, line));
				count++;
			}
		}
		(*res[0] + *res[1]).output("test1.txt");

	}
	ifstream out("test1.txt");
	string line;
	while (getline(out, line)) {
		if (line == "0+0i") continue;
		return false;
	}
	return true;
}