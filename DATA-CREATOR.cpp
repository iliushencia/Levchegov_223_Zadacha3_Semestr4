#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
	string vert = "vert", hori = "hori";
	cout<<"How much vectors do you need?"<<endl;
	int N=0;
	cin>>N;
	cout<<"How much elements should be in every vector?"<<endl;
	int n = 0;
	cin>>n;
	ofstream out;          // поток для записи
	out.open("data.txt");
	if (out.is_open()) {
		for (int i=0; i<N; i++) {
			string res = vert;
			int temp = rand()%2;
			if (temp==1) res = hori;
			out<<res<<" "<<n<<" "<<"data"<<i<<".txt ";
			for (int j=0; j<n; j++) {
				string sign1="", sign2="+";
				int temp1 = rand()%2;
				int temp2 = rand()%2;
				if (temp1==0) sign1 = "-";
				if (temp2==0) sign2 = "-";
				out<<sign1<<rand()%100<<sign2<<rand()%100<<"i ";
			}
			out<<endl;
		}
	}
	return 0;
}
