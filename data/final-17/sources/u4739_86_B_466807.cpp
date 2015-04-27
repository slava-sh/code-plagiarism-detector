#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:16777216")
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#define FOR(i,a,n) for(int i=(a);i<(n);i++)
#define REP(i,n) FOR(i, 0, n)
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define lint long long
#define PII pair <int,int>
#define PDD pair <double,double>
#define VI vector <int>
#define VII vector < PII >
#define X first
#define Y second
#define sz(a) (int)(a.size())
using namespace std;

const int DIM = 1100;
int n, m;
char s[DIM][DIM];
int a[DIM][DIM];
int cnt;
VII pos[DIM*DIM];
char us[DIM][DIM];

bool good(int i, int j){
	return (0 <= i && i < n && 0 <= j && j < m);
}
int getc(int i, int j){
	return ++cnt;
}
bool one(int x, int y){
	for (int i = -1; i <= 1; i += 2){
		if (good(x+i, y) && a[x+i][y] == 0) return false;
	}
	for (int i = -1; i <= 1; i += 2){
		if (good(x, y+i) && a[x][y+i] == 0) return false;
	}
	return true;
}
void fill(int i, int j, int c){
	if (good(i, j) && a[i][j] == 0 && one(i, j)) {
		a[i][j] = c;
		pos[c].pb(mp(i, j));
	}
}
bool check(int x, int y, int col){
	for (int i = -1; i <= 1; i += 2){
		int nx = x+i;
		int ny = y;
		if (good(nx, ny) && a[nx][ny] == col) return true;
	}
	for (int i = -1; i <= 1; i += 2){
		int nx = x;
		int ny = y+i;
		if (good(nx, ny) && a[nx][ny] == col) return true;
	}
	return false;
}
void solve(){
	REP(i, n){
		REP(j, m){
			if (s[i][j] == '#') a[i][j] = -1;
		}
	}
	REP(i, n){
		REP(j, m){
			if (a[i][j] == 0){
				int c = getc(i, j);
				a[i][j] = c;
				pos[c].pb(mp(i, j));
				if (good(i, j+1) && a[i][j+1] == 0){
					a[i][j+1] = c;
					pos[c].pb(mp(i, j+1));
					fill(i, j+2, c);
					fill(i+1, j, c);
					fill(i+1, j+1, c);
				} else if (good(i+1, j) && a[i+1][j] == 0){
					a[i+1][j] = c;
					pos[c].pb(mp(i+1, j));
					fill(i, j+1, c);
					fill(i+1, j-1, c);
					fill(i+2, j, c);
					fill(i+1, j+1, c);
				} else {
					printf("-1\n");
					return;
				}
			}
		}
	}
	REP(i, n){
		REP(j, m){
			if (a[i][j] != -1 && !us[i][j]){
				int hc = a[i][j];
				REP(nc, 10){
					bool g = 1;
					REP(k, sz(pos[hc])){
						if (check(pos[hc][k].X, pos[hc][k].Y, nc)){
							g = 0;
							break;
						}
					}
					if (g){
						REP(k, sz(pos[hc])){
							a[pos[hc][k].X][pos[hc][k].Y] = nc;
							us[pos[hc][k].X][pos[hc][k].Y] = 1;
						}
						break;
					}
				}

			}
		}
	}
	REP(i, n){
		REP(j, m){
			if (a[i][j] == -1) printf("#");
			else printf("%d", a[i][j]);
		}
		printf("\n");
	}
}
int main(){
//	freopen("t.in", "r", stdin);
	scanf("%d%d", &n, &m);
	REP(i, n){
		scanf("%s", s[i]);
	}
	solve();
	return 0;
}

