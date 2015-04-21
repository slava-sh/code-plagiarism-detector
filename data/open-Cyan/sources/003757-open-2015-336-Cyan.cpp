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

ll a, b, n;

struct po{
	ll x, y;
	po(){};
	po(ll _x, ll _y){
		x = _x;
		y = _y;;
	}
};

ll vec(po a, po b, po c){
	a.x -= b.x, a.y -= b.y, c.x -= b.x, c.y -= b.y;
	return a.x * c.y - a.y * c.x;
}

vector<vector<po> > T;

void ex(int a, int b){
	cout << "No\n";
	cout << a + 1 << ' ' << b + 1;
	exit(0);
}

void F(int a, int b){
	ll q, w = 0;
	int l = 0;
	forn(i, T[a].size()){
		while(1){
			if(T[b][l].x <= T[a][i].x && T[a][i].x <= T[b][l + 1].x)
				break;
			l++;
		}
		ll q = vec(T[b][l + 1], T[b][l], T[a][i]);
		if(q != 0){
			if(w != 0 && (w < 0) != (q < 0))
				ex(a, b);
			w = q;
		}
	}
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	

	cin >> a >> b >> n;
	T.resize(n);
	forn(i, n){
		int l;
		cin >> l;
		forn(j, l + 1){
			ll x, y;
			cin >> x >> y;
			po t(x, y);
			T[i].push_back(t);
		}
	}
	forn(i, n){
		forn(j, n){
			if(i != j){
				F(i, j);
			}
		}
	}
	cout << "Yes";
}