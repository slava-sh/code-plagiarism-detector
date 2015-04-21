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

int gl;

void F3(int s){
	fornn(i, gl, s){
		forn(j, i + 1){
			Q('R'), x++;
		}
		forn(j, i + 1){
			Q('D'), y--;
		}
		Q('R');
		x++;
		i++;
		gl++;
		forn(j, i + 1){
			Q('U'), y++;
		}
		forn(j, i + 1){
			Q('L'), y--;
		}
		Q('U');
		y++;
		gl++;
	}
}

void dis(){
	while(y != 0){
		if(y < 0)
			Q('U'), y++;
		else
			Q('D'), y--;
	}
	while(x != 0){
		if(x < 0)
			Q('R'), x++;
		else
			Q('L'), x--;
	}
}

void go(int xx, int yy){
	while(y != yy){
		if(y < yy)
			Q('U'), y++;
		else
			Q('D'), y--;
	}
	while(x != xx){
		if(x < xx)
			Q('R'), x++;
		else
			Q('L'), x--;
	}
}

void F4(int h, int w){
	forn(i, h){
		if(i % 2){
			forn(i, w){
				Q('R');
				x++;
			}
		}
		else{
			forn(i, w){
				Q('L');
				x--;
			}
		}
		Q('U');
		y++;
	}
}

void F5(int h, int w){
	forn(i, h){
		if(i % 2){
			forn(i, w){
				Q('U');
				y++;
			}
		}
		else{
			forn(i, w){
				Q('D');
				y--;
			}
		}
		Q('R');
		x++;
	}
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int xp = 0, yp = 1, s = 300;
	for(int i = 10; i < 1000; i++){
		go(xp, yp);
		y++;
		F3(i);
		xp = x, yp = y;
		dis();
		F4(s / i + 1, i + 1);
		dis();
		F5(s / i + 1, i + 1);
		s *= 1.3;
	}
}