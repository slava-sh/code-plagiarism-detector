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

int x, y;

void Q(char c){
	cout.flush();
	cout << c << "\n";
	cin >> c;
	cout.flush();
	if(c == 'Y' || c == 'E')
		exit(0);

}

void F(){
	forn(i, 2001){
		forn(j, i){
			Q('U');
		}
		forn(j, i){
			Q('L');
		}
		i++;
		forn(j, i){
			Q('D');
		}
		forn(j, i){
			Q('R');
		}
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	F();
}