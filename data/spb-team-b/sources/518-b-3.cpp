#include <iostream>
#include <fstream>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int n;
	fin >> n;
	
	for (int i = 0; i < n; i++){
		int a;
		fin >> a;
		if (a < i+1){
			n = i;
			fout << n<<'\n';
		}
	}
	for (int i = 0; i < n; i++){
		fout << i + 1 << " " << i + 1 << '\n';
	}
	fout.close();
	return 0;
}