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

int a[110000];
int r[7000][7000];
int N;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d", &N);
	forn(i, N) scanf("%d", &a[i]);

	//forn(i, N) a[i]--;

	forn(i, N) r[0][i + 1] = 1;
	r[0][ a[0] ]--;
	
	forn(i, N){
		forn(j, N)
			r[i + 1][j + 1] = r[i][j + 1];
		r[i + 1][ a[i + 1] ]--;
	}

	forn(i, N){
		forn(j, N - 1) r[i][j + 2] += r[i][j + 1];
	}

	/*forn(i, N){
		forn(j, N) printf("%d ", r[i][j + 1]);
		printf("\n");
	}*/

	int mn = 0, mni = -2, mnj = -2;
	forn(i, N){
		for(int j = i + 1; j < N; j++)
			if (a[i] > a[j]){
			if (r[i][ a[j] - 1] - r[i][ a[i] - 1 ] + r[j][ a[i] - 1 ] - r[j][ a[j] - 1 ] - 1 < mn){
				mn = r[i][ a[j] - 1 ] - r[i][ a[i]- 1 ] + r[j][ a[i] - 1] - r[j][ a[j] - 1 ] - 1;
				mni = i; mnj = j;
			}
		}
	}

	printf("%d %d", mni + 1, mnj + 1);
	

	return 0;
}