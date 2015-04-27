#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
	int m, k;
	cin >> m >> k;
	vector <int> a(k);
	m--;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}

	vector <int> t(m);
	vector <int> r(m);

	for (int i = 0; i < m; i++) {
		cin >> t[i] >> r[i];
		--t[i];
	}

	int first = 0;
	int cnt_any = 0;
	vector <int> cnt(k);
	while (first < m && r[first] != 1) {
		if (t[first] == -1) ++cnt_any;
		else ++cnt[t[first]];
		++first;
	}

	vector <int> cnt_next(k);
	for (int i = first; i < m; i++) {
		if (t[i] != -1) ++cnt_next[t[i]];
	}

	vector <char> ans(k);
	int least = -1;
	for (int i = 0; i < k; i++) {
		ans[i] = cnt_next[i] == 0 && cnt[i] + cnt_any >= a[i];
		if (ans[i]) {
			int our_cnt = a[i] - cnt[i];
			if (least == -1 || our_cnt < a[least] - cnt[least]) {
				least = i;
			}
		}
	}
	if (least != -1) {
		cnt_any -= a[least] - cnt[least];
		for (int i = first; i < m; i++) {
			if (t[i] == -1) ++cnt_any;
			else ++cnt[t[i]];
		}
	}

	for (int i = 0; i < k; i++) {
		if (!ans[i] && least != -1) {
			ans[i] = cnt[i] + cnt_any >= a[i];
		}
		cout << (ans[i] ? "Y" : "N");
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
