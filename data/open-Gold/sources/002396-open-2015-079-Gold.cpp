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

const ll inf = (ll) 1 << 61;
const ld eps = 1e-9;

ll ans[5000][5000];

int a[10000], b[10000];

int N, K, D, C;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%d%d%d%d", &N, &K, &C, &D);
	forn(i, N) scanf("%d%d", &a[i + 1], &b[i + 1]);

	for(int i = 2; i <= N; i++){
		for (int j = 0; j < K - 1; j++)
			ans[i][j] = min(ans[i - 1][j] + (a[i] - b[i - 1])  * ((ll) D), ans[i - 1][j + 1]);
		ans[i][K - 1] = min(ans[i - 1][0] + C, ans[i - 1][K - 1] + (a[i] - b[i - 1])  * ((ll) D));
	}

	ll Q = 0;
	forn(i, N) Q += (b[i + 1] - a[i + 1]) * ((ll) D);

	ll answer = inf;
	
	forn(i, K) answer = min(answer, ans[N][i]);
	printf("%lld", answer + Q);

	return 0;
}