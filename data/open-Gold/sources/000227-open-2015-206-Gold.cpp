#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

int n, k, c, d;
ll cur;
int newCnt;
int a[200500], b[200500];
int cnt[200500][2];
ll dp[200500][2];
                     
int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%d%d%d%d", &n, &k, &c, &d);
	for (int i = 1; i <= n; i++) scf("%d%d", &a[i], &b[i]);
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j < 2; j++) dp[i][j] = (ll)1e18, cnt[i][j] = 0;
	dp[0][0] = dp[0][1] = 0LL;
	cnt[0][0] = cnt[0][1] = k;
	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			cur = dp[i - 1][0] + 1LL * d * (a[i] - b[i - 1]) + 1LL * d * (b[i] - a[i]);
			dp[i][0] = cur;
			cnt[i][0] = cnt[i - 1][0];
			dp[i][1] = cur;
			cnt[i][1] = cnt[i - 1][0];
		}
		cur = dp[i - 1][1] + 1LL * d * (b[i] - a[i]);
		newCnt = cnt[i - 1][1];
		if (newCnt == 0) {
			newCnt = k - 1;
			cur += (1LL * c);
		} else --newCnt;
		if (dp[i][0] > cur) {
			dp[i][0] = cur;
			cnt[i][0] = newCnt;
		}
		if (dp[i][0] == cur) cnt[i][0] = max(cnt[i][0], newCnt);
		if (dp[i][1] > cur) {
			dp[i][1] = cur;
			cnt[i][1] = newCnt;
		}
		if (dp[i][1] == cur) cnt[i][1] = max(cnt[i][1], newCnt);
	}
	cout << min(dp[n][0], dp[n][1]);
	puts("");
	return 0;
}