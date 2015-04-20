
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("dunes.in");
	ofstream fout("dunes.out");
	int pc;//kolichestvo poriviv
	int uc;//kol-vo uchastkov
	fin >> pc;
	fin >> uc;
	vector<int> fp(pc);
	vector<int> lp(pc);
	vector<int> sp(pc);
	vector<int> u(uc);
	int tu,tr;
    for (int i = 0; i < pc; i++){
		fin >> fp[i];
		fin >> lp[i];
		fin >> sp[i];
	}
	for (int i = 0; i < uc; i++){
		fin>>u[i];
	}

	for (int i = 0; i < uc; i++){
		tu = u[i];
		tr = 0;
		for (int j = 0; j < pc; j++){
			if (fp[j] <= tu && lp[j] >= tu){
				if ((tu - fp[j]) % 2 == 0){
					tr += sp[j];
				}else{
					tr -= sp[j];
				}
			}
		}
		fout << tr<<endl;
	}
    fout.close(); 
}