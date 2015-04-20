#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

vector<pair<int, int> > gr[5010];
pair<int, int> rast[5010];
int pr[5010];
set<pair<int, int> > st;

int main(){
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		rast[i].second = 1000000000;
		rast[i].first = -1;
		cin >> pr[i];
		if (pr[i] == 1) {
			rast[i].first = i;
			rast[i].second = 0;
			st.insert(make_pair(0, i));
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, rs;
		cin >> u >> v >> rs;
		gr[u].push_back(make_pair(v, rs));
		gr[v].push_back(make_pair(u, rs));
	}
	while (!st.empty()) {
		int v = (*st.begin()).second;
		st.erase(st.begin());
		for (int i = 0; i < gr[v].size(); i++) {
			int nv = gr[v][i].first,
				rst = gr[v][i].second;
			if (rast[v].second + rst < rast[nv].second) {
				rast[nv].second = rast[v].second + rst;
				rast[nv].first = rast[v].first;
				st.insert(make_pair(rast[nv].second, nv));
			}
		}
	}
	int ans = 1000000000;
	int ukx = -1, uky = -1;
	for (int i = 1; i <= n; i++) {
		if (pr[i] == 2) {
			if (rast[i].second < ans) {
				ans = rast[i].second;
				ukx = rast[i].first;
				uky = i;
			}
		}
	}
	if (ans == 1000000000) {
		cout << -1;
	} else {
		cout << ukx << " " << uky << " " << ans;
	}
	return 0;
}





















/*
ll a[100010];
ll n, k;

bool f(long long m) {
	long long uk = 0;
	for (long long i = 0; i < n; i++) {
		if (a[i] - uk >= m) {
			uk = a[i];
			continue;
		}
		if (uk + m < k) {
			uk = uk + m;
		} else {
			return 0;
		}
	}
	return 1;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ll l = 0, r = 1000000000;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		r = min(r, a[i]);
	}
	r++;
	sort(a + 0, a + n);
	//reverse(a + 0, a + n);
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (f(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l;
	return 0;
}
	
	
	
	
	
	
	
	
	/*
	freopen("input.txt", "r", stdin);
	//freopen("sochi.out", "w", stdout);
	ll n, d;
	cin >> n >> d;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll uk = n + 1;// укакзатель на первое >= 3d
	ll x = n + 1;// укакзатель на первое >= d, <= 3d
	bool b = 1, bb = 1;
	if (n == 1) {
		cout << a[1];
		return 0;
	}
	if (a[n] < d) {
		cout << a[n];
		return 0;
	}	
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] >= 3 * d) {
			uk = i;
			break;
		}
		if (a[i] >= d && b) {
			x = i;
			b = 0;
		}
	}	
	if (uk > n) {
		ll v = n - x + 1;
		if (v >= 2) {
			cout << max(a[n] - d + a[n - 1] - d, a[n]);
			return 0;
		}
		if (v == 1) {
			cout << a[n];
		return 0;
		}
	}
	if (x > n) {
		for (ll i = uk; i <= n; i++) 
			ans += a[i] - d - d;
		ans += d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	for (ll i = uk; i <= n; i++) 
		ans += a[i] - d - d;
	if (uk - x >= 2) {
		ans += a[uk - 1] - d + a[uk - 2] - d;
		cout << max(ans, a[n]);
		return 0;
	}
	if (uk - x == 1) {
		ans += a[uk - 1] - d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	//if (uk - x == 0) {
}
	
	
	/*if (x == 0) {
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = 1; i <= n -2; i++)
			ans += a[i] - d- d;
		cout << ans;
		return 0;
	}
	if (uk - x >= 2)
		p = a[uk - 1], k = a[uk - 2];
	if (uk - x == 1 || n - x == 0) {
		p = a[x];
		o = 2;
	}
	if (uk - x == 0)
		b = 0;
	if (b) {
		if (n - uk == 0) {
			cout << a[n];
			return 0;
		}
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = uk; i <= n - 2; i++)
			ans += a[i] - d - d;
		cout << ans; 
		return 0;
	}
	if (uk == 0) {
		if (o == 2) {
			cout << p;
			return 0;
		}
		cout << a[n] - d + a[n - 1] - d;
		return 0;
	}
	if (o == 2) {
		ans += p - d;
		ans += a[n] - d;
		for (ll i = uk; i <= n - 1; i++) 
			ans += a[i] - d - d;
		cout << ans;
		return 0;
	}
	ans += p - d + k - d;
	for (ll i = uk; i <= n; i++)
		ans += a[i] - d - d;
	cout << ans;
	return 0;
}*/