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
const ld eps = 1e-5;

ll v1, v2;
ll v1x, v1y, v2x, v2y;

ll x[500][500], y[500][500], l[1000];


ll vect(ll x1, ll y1, ll x2, ll y2){
	return ((ll) x1 * y2) - ((ll)x2 * y1); 
}

ll A, B, N;

ll a1, a2, b1, b2, c1, c2;

bool per(int i1, int j1, int i2, int j2){
	a1 = y[i1][j1 + 1] - y[i1][j1]; 
	b1 = x[i1][j1] - x[i1][j1 + 1];
	c1 = -(x[i1][j1] * y[i1][j1 + 1] - x[i1][j1 + 1] * y[i1][j1]);

	a2 = y[i2][j2 + 1] - y[i2][j2]; 
	b2 = x[i2][j2] - x[i2][j2 + 1];
	c2 = -(x[i2][j2] * y[i2][j2 + 1] - x[i2][j2 + 1] * y[i2][j2]);

	ld d = a1 * b2 - a2 * b1;

	if (d == 0) return false;

	ld xp = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1 + 0.0);

	if (abs(xp - x[i1][j1]) < eps ||
		abs(xp - x[i1][j1 + 1]) < eps) return false;


	if (abs(xp - x[i2][j2]) < eps ||
		abs(xp - x[i2][j2 + 1]) < eps) return false;

	if (xp < x[i1][j1 + 1] && xp > x[i1][j1] &&
		xp < x[i2][j2 + 1] && xp > x[i2][j2]) return true;

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
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			for(int k = 0; k < l[i]; k++){
				for(int z = 0; z < l[j]; z++)
					if (per(i, k, j, z)){
						printf("No\n%d %d", i + 1, j + 1);
						return 0;
					}
			}
		}
	}
	
	printf("Yes");
	
	/*forn(i, N){
		for(int j = i + 1; j < N; j++)
			if (check(i, j)){
				printf("No\n%d %d", i + 1, j + 1);
				return 0;
			}
	}

	printf("Yes");*/

	return 0;
}