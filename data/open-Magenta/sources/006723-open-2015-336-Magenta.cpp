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

void F3(int s){
	forn(i, s){
		forn(j, i + 1){
			Q('R');
		}
		forn(j, i + 1){
			Q('D');
		}
		Q('R');
		i++;
		forn(j, i + 1){
			Q('U');
		}
		forn(j, i + 1){
			Q('L');
		}
		Q('U');
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	Q('U');
	F3(300);
	
}