#include <iostream>
#include <fstream>


using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("chess.in");
	ofstream fout("chess.out");
	int j, n;
	fin >> n;
	int *a = new int(n);
	for (int i = 0; i < n; i++)
		fin >> a[i];
	for (int i = 0; i < n; i++){
		if (a[i] < i + 1){
			fout << i<<"\n";
			j = i;
			break;
		}
	}
	for (int i = 0; i < j; i++)
		fout << i + 1 << " " << i + 1 << '\n';
	fout.close();
	return 0;
}