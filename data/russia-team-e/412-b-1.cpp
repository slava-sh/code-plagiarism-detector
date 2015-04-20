#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#include<queue>
#include<string>
#include<map>

#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define next next_asjkdh
using namespace  std;

int main(void) {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n, rr;
	scanf("%d %d", &n, &rr);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	ll l, r;
	l = 0;
	r = 0;
	ll ans = 0;
	for (l = 0; l < n; ++l) {
		while ((r < n) && (a[r] - a[l] <= rr)) {
			r++;
		}
		if (r < n)
			ans  += (ll)n - r;
		if (r >= n) {
			cout << ans << endl;
			return 0;
		}

	}
}