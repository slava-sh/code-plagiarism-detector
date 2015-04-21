#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define forn(i, n) for(int i = 0; i < n; i++)

const int inf = 1 << 30;
const ld eps = 1e-9;

map <pair <ll, int>, int> S;

ll N, M;
int K;

map <pair <ll, int>, int> :: iterator it;

void update(ll N, int K, int val){
	it = S.find( mp(N, K) );
	if (it->second > val) it->second = val;
}

ll go(ll N, int K){
	if (!K) return (N + 1) / 2;

	it = S.find( mp(N, K) );
	if (it != S.end()) return it->second;
	else S.insert(mp( mp(N, K), inf));

	for(ll i = 1; i * i <= N; i++)
	if (N % i == 0){ 
		update(N, K, ((i + 1) / 2) * go(N / i, K - 1));
		update(N, K, ((N / i + 1) / 2) * go(i, K - 1));
	}

	return S.find(mp(N, K))->second;
}


int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	scanf("%lld%d", &N, &K);
	printf("%lld", go(N, K - 1));

	return 0;
}