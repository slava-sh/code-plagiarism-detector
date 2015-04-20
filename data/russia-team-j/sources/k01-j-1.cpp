#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define INF 2e9
#define mod 1000000007
#define fi first
#define se second
#define fname "travel"
#define re return

typedef long long ll;

int n, m, k, xx, yy, x, y, res =INF;
char c[551][551];

bool has(int i, int j) {
	if(c[i - 1][j] == 'T' || c[i + 1][j] == 'T' || c[i][j - 1] == 'T' || c[i][j + 1] == 'T')  re 1;
	re 0;
}

int main() {
	
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> m >> n >> k;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if(c[i][j] == 'V') x = i, y = j;
		}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(c[i][j] == 'T') {
				int dist = abs(i - x) + abs(j - y)+2*(k-1);
				if(has(i, j)) dist -= k + 1;
				if(dist < res) {
					res = dist;
					xx = i;
					yy = j;	
				} 
			}

	if(yy > y) for(int i = 1; i <= yy - y; i++) cout << "E";
	else
	for(int i = 1; i <= y - yy; i++) cout << "W";
	if(xx > x) for(int i = 1; i <= xx - x; i++) cout << "N";
	else
	for(int i = 1; i <= x - xx; i++) cout << "S";
	k--;      

	 	if(has(xx, yy)) {
	 		if(c[xx - 1][yy] == 'T') {
	 		 	for(int i = 1; i <= k / 2; i++) cout << "NS";
	 			if(k & 1) cout << "N";
	 		}
	 		if(c[xx + 1][yy] == 'T') {
	 		 	for(int i = 1; i <= k / 2; i++) cout << "SN";
	 			if(k & 1) cout << "S";
	 		}	
	 	
	 		if(c[xx][yy + 1] == 'T') {
	 		 	for(int i = 1; i <= k / 2; i++) cout << "EW";
	 			if(k & 1) cout << "E";
	 		}
	 		if(c[xx][yy - 1] == 'T') {
	 		 	for(int i = 1; i <= k / 2; i++) cout << "WE";
	 			if(k & 1) cout << "W";
	 		}
	 		}
	 		else {
	 		if(xx > 1) {
	 		 	for(int i = 1; i <= k; i++) cout << "NS";
	 			//if(k & 1) cout << "N";
	 		}
	 		if(xx < n) {
	 		 	for(int i = 1; i <= k; i++) cout << "SN";
	 			///if(k & 1) cout << "S";
	 		}	
	 	
	 		if(yy < m) {
	 		 	for(int i = 1; i <= k; i++) cout << "EW";
	 			//if(k & 1) cout << "E";
	 		}
	 		if(yy > 1) {
	 		 	for(int i = 1; i <= k; i++) cout << "WE";
	 			//if(k & 1) cout << "W";
	 		}
	 		
	 		}
	 		re 0;
	}


	
