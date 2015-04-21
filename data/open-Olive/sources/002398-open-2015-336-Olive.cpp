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

vector<int> P, C;
int n;

int F(vector<int> &T){
	int q = 0;
	forn(i, n){
		forn(j, i){
			if(T[i] < T[j])
				q++;
		}
	}
	return q;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	P.resize(n);
	C.resize(n);
	forn(i, n){
		cin >> P[i];
	}
	int q = infi, a = -1, b = -1;
	
	forn(i, n){
		forn(j, i){
			swap(P[i], P[j]);
			int t = F(P);
			if(q > t)
				q = t, a = i, b = j;
			swap(P[i], P[j]);
		}
	}
	cout << a + 1 << ' ' << b + 1;
}