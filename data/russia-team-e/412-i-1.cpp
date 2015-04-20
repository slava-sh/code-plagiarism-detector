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
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);

	int n, d;
	scanf("%d %d", &n, &d);
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	vector <bool> used(n, false);
	ll ans = 0;
	bool f = false;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= 3 * d) {
			ans += (ll)a[i] - 2ll * (ll)d;
			used[i] = true;
			f = true;
		}
	}
	int m1 = -1, m2 = -1;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			if (a[i] >= m1) {
				m2 = m1;
				m1 = a[i];
				continue;
			}
			if (a[i] > m2)
				m2 = a[i];
		}
	}
	//cout << m1 << ' ' << m2;
	if (f) {
		if(m2 <= d)
			ans += max(m1 - d, d) + d;
		else
			ans += max(m1 - d, d) + max(m2 - d, d);
	} else {
		if(m2 <= d)
			ans = m1;
		else ans = m1 + m2 - 2 * d;
	}
	cout << ans;
	return 0;
}