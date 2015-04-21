#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

int xcoord, ycoord;
int t = 1;
int cnt = 0;

int res[6001][6001];
int turn[6001][6001];
ld maxerror = 0;

void go(int x, int y);

void maketurn(char ch){
	t++;
	cout << ch;
	char res = 'N';
	cout << endl;
	cin >> res;
	if(res == 'N'){
		return;
	}
	exit(0);
}

void go(int x, int y){
	while(xcoord < x){
		maketurn('R');
		xcoord++;
	}
	while(ycoord < y){
		maketurn('D');
		ycoord++;
	}
	while(xcoord > x){
		maketurn('L');
		xcoord--;
	}
	while(ycoord > y){
		maketurn('U');
		ycoord--;
	}
}

int main(){
#ifdef _DEBUG
	freopen("peak.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	//cerr << "newer version" << endl;
	const int mult = 27;
	for(int med = 0;; med++){
		assert(xcoord == ycoord && xcoord == med);
		if(med & 1){
			while(ycoord > 0){
				go(xcoord + mult, ycoord);
				go(xcoord, ycoord - 1);
			}
			go(xcoord + mult * 2 + 1, ycoord);
			go(xcoord - mult, ycoord);
			while(ycoord != med + 1){
				go(xcoord, ycoord + 1);
				go(xcoord - mult, ycoord);
			}
		} else {
			while(xcoord > 0){
				go(xcoord, ycoord + mult);
				go(xcoord - 1, ycoord);
			}
			go(xcoord, ycoord + mult * 2 + 1);
			go(xcoord, ycoord - mult);
			while(xcoord != med + 1){
				go(xcoord + 1, ycoord);
				go(xcoord, ycoord - mult);
			}
		}
	}
	return 0;
}