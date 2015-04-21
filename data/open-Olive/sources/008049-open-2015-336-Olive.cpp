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


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n;
	P.resize(n);
	C.resize(n);
	forn(i, n){
		cin >> P[i];
		P[i]--;
	}
	int q = 0, a = -2, b = -2, er;
	er = q;
	
	vector<int> W(n + 1);
	vector<int> L(n + 1);

	forn(i, n){
		int c = 0;
		for(int j = i + 1; j < n; j++){
			if(P[i] > P[j]){
				int z = 0;
				z += c - C[j] + W[n] - W[P[j]];
				if(q > z)
					q = z, a = i, b = j;
			}
			else
				c++;
		}
		L[P[i]] = 1;
		forn(j, n){
			W[j + 1] = W[j] + L[j];
		}
		if(times > 1.95)
			break;
	}
	cout << a + 1 << ' ' << b + 1;
}