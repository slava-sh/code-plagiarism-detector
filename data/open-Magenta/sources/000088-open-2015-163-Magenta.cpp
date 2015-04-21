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
	for(int i = 1;;i++){
		char c1, c2;
		if(i & 1){
			c1 = 'R';
			c2 = 'U';
		} else {
			c1 = 'L';
			c2 = 'D';
		}
		for(int j = 0; j < i; j++){
			turn(c1);
		}
		for(int j = 0; j < i; j++){
			turn(c2);
		}
	}
	return 0;
}