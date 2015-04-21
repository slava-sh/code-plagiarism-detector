#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define local
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 200010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



//ll dp[N][2], t[N][2];

int main(){
#ifdef local
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	ll n, m, K, D, C, i, k, a, b, pa, pb;
	cin >> n >> K >> C >> D;
	scanf("%lld %lld", &pa, &pb);
	ll ans = (pb - pa) * D;
	for (i = 1; i < n; i++){
		scanf("%lld %lld", &a, &b);
		ans += (b - a) * D;
		if (C > (a - pb) * D){
			ans += (a - pb) * D;
		}
		else {
			ans += C;
		}
		pb = b;
	}

	cout << ans;
	
	/*int a, b, pa, pb;
	scanf("%d %d", &pa, &pb);
	t[0][0] = t[0][1] = 1;
	dp[0][0] = dp[0][1] = (pb - pa) * D;

	for (i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (b - pb) * D;
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (b - a) * D + C;
		pa = a;
		pb = b;
	}

	for (i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		if (dp[i - 1][0] < dp[i - 1][1]){
			t[i][0] = t[i - 1][0];
		}
		else {
			t[i][0] = t[i - 1][1];
		}
		dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + (b - pb) * D;
		ll d0 = dp[i - 1][0] + (b - a) * D + (t[i - 1][0] == K ? C : 0),
			d1 = dp[i - 1][1] + (b - a) * D + (t[i - 1][1] == K ? C : 0);
		dp[i][1] = min(d1, d0);
		if (d0 < d1){
			t[i][1] = t[i - 1][0] + 1;
		}
		else {
			t[i][1] = t[i - 1][1] + 1;
		}
		if (t[i][1] > K){
			t[i][1] -= K;
		}
		pa = a;
		pb = b;
	}*/

	return 0;
}