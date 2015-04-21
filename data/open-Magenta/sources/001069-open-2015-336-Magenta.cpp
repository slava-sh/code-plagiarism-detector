#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)
const int infi = 1e9 + 7;
const ll mod = 1e9 + 7;

void F(int h, int w){
	forn(i, h){
		forn(j, w){
			cout.flush();
			cout << "U\n";
			char c;
			cin >> c;
			cout.flush();
			if(c == 'Y' || c == 'E')
				exit(0);
		}
		cout.flush();
		cout << "L\n";
		char c;
		cin >> c;
		cout.flush();
		if(c == 'Y' || c == 'E')
			exit(0);

	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for(int i = 1; i < 21; i++){
		F(i, 301 / i + 1);
		F(301 / i + 1, i);
	}

}