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
int main() {
	vector<CCompexVector*> res = {};
	vector<string> paths;
	int count = 0;
	string check = "", path="data.txt";
	ifstream input(path);
	if(input){
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
	}
	CCompexVectorVert A;
	//auto start = chrono::system_clock::now();
	A = *res[0] + *res[1];
	A.output("datadata.txt");
	//auto end = std::chrono::system_clock::now();
	//int elapsed_ms = static_cast<int>(chrono::duration_cast<chrono::milliseconds>(end - start).count());
	//std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";

	for (int i =0; i<count; i++){
		if(res[i]->output(paths[i])) continue;
		check = "error";
	}
	if (check=="") {cout<<"check all the output files"<<endl<<"Press any key to continue"<<endl;}
	else {cout<<check<<endl<<"Press any key to continue"<<endl;}
	cin >> check; //для того чтобы консолька не закрывалась
	return 0;
}

