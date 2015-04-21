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
int v1x, v1y, v2x, v2y;

int x[500][500], y[500][500], l[1000];


ll vect(int x1, int y1, int x2, int y2){
	return ((ll) x1 * y2) - ((ll)x2 * y1); 
}

int A, B, N;

bool per(int i1, int j1, int i2, int j2){
	v1x = x[i1][j1 + 1] - x[i1][j1], v1y = y[i1][j1 + 1] - y[i1][j1];

	v2x  = x[i2][j2] - x[i1][j1]; v2y = y[i2][j2] - y[i1][j1];

	v1 = vect(v1x, v1y, v2x, v2y);

	v2x  = x[i2][j2 + 1] - x[i1][j1]; v2y = y[i2][j2 + 1] - y[i1][j1];

	v2 = vect(v1x, v1y, v2x, v2y);
	

	if (!v1 || !v2) return false;
	if (v1 > 0 && v2 > 0 ||
		v1 < 0 && v2 < 0) return false;



	v1x = x[i2][j2 + 1] - x[i2][j2], v1y = y[i2][j2 + 1] - y[i2][j2];

	v2x  = x[i1][j1] - x[i2][j2]; v2y = y[i1][j1] - y[i2][j2];

	v1 = vect(v1x, v1y, v2x, v2y);

	v2x  = x[i1][j1 + 1] - x[i2][j2]; v2y = y[i1][j1 + 1] - y[i2][j2];

	v2 = vect(v1x, v1y, v2x, v2y);
	

	if (!v1 || !v2) return false;
	if (v1 > 0 && v2 > 0 ||
		v1 < 0 && v2 < 0) return false;

	return true;
}


bool check(int a, int b){
	int i = 0, j = 0;
	while (i < l[a] && j < l[b]){
		if (per(a, i, b, j)) return true;

		if (x[a][i + 1] < x[b][j + 1]) i++;
		else j++;
	}
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d%d", &A, &B);
	
	scanf("%d", &N);
	forn(i, N){
		scanf("%d", &l[i]);
		forn(j, l[i] + 1) scanf("%d%d", &x[i][j], &y[i][j]);
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