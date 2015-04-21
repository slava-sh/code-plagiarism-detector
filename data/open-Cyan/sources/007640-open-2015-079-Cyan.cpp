#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

ll v1, v2;
ll v1x, v1y, v2x, v2y;

ll x[500][500], y[500][500], l[1000];


ll vect(ll x1, ll y1, ll x2, ll y2){
	return ((ll) x1 * y2) - ((ll)x2 * y1); 
}

ll A, B, N;


int pos(int i1, int j1, int i2, int j2){
	ll vx1 = x[i1][j1 + 1] - x[i1][j1], vy1 = y[i1][j1 + 1] - y[i1][j1];

	ll vx2 = x[i2][j2] - x[i1][j1], vy2 = y[i2][j2] - y[i1][j1];

	if (vx1 * vy2 - vx2 * vy1 < 0) return -1;
	if (vx1 * vy2 - vx2 * vy1 > 0) return 1;
	else return 0;
}


bool check(int a, int b){
	int i = 0, j = 0;

	int v = 0;

	forn(i, l[a]){
		while (x[b][j] <= x[a][i + 1] && j <= l[b]){
			
			if (!v && pos(a, i, b, j)) v = pos(a, i, b, j);

			if (pos(a, i, b, j) && pos(a, i, b, j) != v) return true;
			j++;
		}
	}

	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%lld%lld", &A, &B);
	
	scanf("%lld", &N);
	forn(i, N){
		scanf("%lld", &l[i]);
		forn(j, l[i] + 1) scanf("%lld%lld", &x[i][j], &y[i][j]);
	}
	
	forn(i, N){
		for(int j = i + 1; j < N; j++)
			if (check(i, j)){
				printf("No\n%d %d", i + 1, j + 1);
				return 0;
			}
	}

	printf("Yes");

	return 0;
}