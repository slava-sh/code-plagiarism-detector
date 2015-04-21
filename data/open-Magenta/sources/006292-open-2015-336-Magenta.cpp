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
	cout.flush();
	cin >> c;
	cout.flush();
	if(c == 'Y')
		exit(0);

}

void F(){
	forn(i, 20){
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

void F2(int h, int w){
	forn(i, h){
		forn(j, w - i + 1){
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

void F3(int s){
	for(int i = 0; i < s + 5; i++){
		if(i % 301 == 0)
			Q('U');
		Q('L');
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	F();
	fornn(i, 1, 2001){
		bool fl = 1;
		fornn(j, 2, i){
			if(i % j == 0){
				fl = 0;
				break;
			}
		}
		if(fl){
			F2(i, 2001 / i);
			Q('L');
		}
	}
	//F();
}