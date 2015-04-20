#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("merlin.in");
	ofstream fout("merlin.out");
	int l;
	int r = 0, tr=0;
	int tmp=0, curmax;
	fin >> l;
	vector<int> s(l);
	for (int i = 0; i < l; i++){
		fin>>s[i];
	}
	sort(s.begin(), s.end());
	curmax = s[s.size() - r - 1];
	for (int i = 0; i < s.size() - r; i++){
		tr += curmax - s[i];
	}
	while (tmp < tr){
		r++;
		tmp += s[s.size() - r];
		tr = 0;
		curmax = s[s.size() - r-1];
		for (int i = 0; i < s.size() - r; i++){
			tr += curmax - s[i];
		}
	}
	fout << r;
	fout.close();
	return 0;
}