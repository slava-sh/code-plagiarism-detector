#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

void turn(char ch){
	cout << ch << endl;
	char res;
	cin >> res;
	if(res == 'N'){
		return;
	}
	exit(0);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	int fi1 = 1, fi2 = 2;
	for(int i = 1;;i++){
		for(int j = 0; j < fi1; j++){
			turn('U');
		}
		turn('R');
		fi2 += fi1;
		fi1 = fi2 - fi1;
	}
	return 0;
}