#include <iostream>
#include <fstream>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("abcd.in");
	ofstream fout("abcd.out");
	int l, tmp, a, b, c, d;
	fin >> l;
	for (int i = 0; i < l; i++){
		fin >> tmp;
		a = tmp / 1000;
		b = (tmp % 1000) / 100;
		c = (tmp % 100) / 10;
		d = tmp % 10;
		if (( ((a * 10) + b)*((a * 10) + b) + ((c * 10) + d)*((c * 10) + d)) % 7 == 1){
			fout << "YES" << endl;
		}
		else{
			fout << "NO" << endl;
		}
	}
	fout.close();
	return 0;
}