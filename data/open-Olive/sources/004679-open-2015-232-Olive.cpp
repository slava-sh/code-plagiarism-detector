#include <iostream>
#include <fstream>

using namespace std;

int a, b; 
int m[1000001];
int lower[5002][5002];
int upper[5002][5002];

int low(int a, int l, int r){
	return lower[a][r] - lower[a][l - 1];
}

int up(int a, int l, int r){
	return upper[a][r] - upper[a][l - 1];
}

int main(){
	cin >> a;
	for(int i = 1; i <= a; ++i)
		cin >> m[i];
	for(int i = 1; i <= a; ++i)
		for(int q = 1; q <= a; ++q){
			upper[i][q] = upper[i][q - 1];
			lower[i][q] = lower[i][q - 1];
			if(m[q] > m[i]) upper[i][q]++;
			if(m[q] < m[i]) lower[i][q]++;
		}
	int max_ = 0;
	int a1 = -1, a2 = -1;
	for(int i = 1; i <= a; ++i)
		for(int q = i + 1; q <= a; ++q)
			if(m[i] > m[q] && max_ < low(i, i, q) + up(q, i, q))
				max_ = low(i, i, q) + up(q, i, q), a1 = i, a2 = q;
	cout << a1 << ' ' << a2 << "\n";

	return 0;
}