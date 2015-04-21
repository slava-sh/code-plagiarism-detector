#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

vector <ll> del;

bool was[100000][12];

ll ans[100000][12];

ll N, M;
int K;

ll go(ll N, int K){
	if (!K) return (N + 1) / 2;
	if (was[N][K]) return ans[N][K];
	was[N][K] = 1;

	ans[N][K] = inf;
	
	ll M = N;
	for(ll i = 1; i * i <= M; i++){
		ans[N][K] = min(ans[N][K], ((i + 1) / 2) * go(N / i, K - 1));
		ans[N][K] = min(ans[N][K], ((N / i + 1) / 2) * go(i, K - 1));
	}

	return ans[N][K];
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%lld%d", &N, &K);
	printf("%lld", go(N, K));

	return 0;
}