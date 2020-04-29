#include<iostream>
#include<chrono>
#include"complexvector.hpp"
#include"complexnumber.h"
#include"complexvector1.hpp"
#include"complexvector0.hpp"
#include"Factory.hpp"
#include"FactoryHori.hpp"
#include"FactoryVert.hpp"
#include<vector>
#include<string>

bool autotest1();
bool autotest2();

int main() {

	cout << "Test1: ";
	if (autotest1()) {
		cout << "done" << endl;
	}
	else {
		cout << "error" << endl;
		string check;
		cin >> check;
		return -1;
	}
	cout << "Test2: ";
	if (autotest2()) {
		cout << "done" << endl;
	}
	else {
		cout << "error" << endl;
		string check;
		cin >> check;
		return -1;
	}

	vector<CCompexVector*> res = {};
	vector<string> paths = {};
	int count = 0;
	string check = "", path="data.txt";
	ifstream input(path);
	if(input.is_open()){
		string line;
		while (getline(input, line)) {
			string type = "", path = "";
			int l = 0;
			stringstream ss(line);
			ss >> type >> l >> path;
			paths.push_back(path);
			if (type=="vert"){
				FactoryVert fucc;
				res.push_back(fucc.Create(l,line));
				count++;
			} else if (type=="hori") {
				FactoryHori fucc;
				res.push_back(fucc.Create(l,line));
				count++;
			}
		}
		(*res[0] + *res[1]).output("test.txt");
	} else {
		cout << "Error! Cannot open " << path << endl;
		return -1;
	}

	for (int i =0; i<count; i++){
		if(res[i]->output(paths[i])) continue;
		check = "error";
	}
	if (check=="") {cout<<"check all the output files"<<endl<<"Press any key to continue"<<endl;}
	else {cout<<check<<endl<<"Press any key to continue"<<endl;}
	cin >> check; //для того чтобы консолька не закрывалась
	return 0;
}

