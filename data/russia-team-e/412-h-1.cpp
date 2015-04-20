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
int tmp;
set<pair<ll, int> > st;
int main(void) {
    freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<ll> d(n);
	vector<int> a(n);
	vector<bool> second(n);
	vector<bool> used(n);
	vector<vector<pair<int, ll> > > v(n);
	
	for (int i = 0; i < n; ++i) {
		cin >> tmp;
		d[i] = 1000000000000000LL;
		a[i] = -1;
		if (tmp == 2)
			second[i] = true;
		else second[i] = false;
		if (tmp == 1) {
			d[i] = 0;
			a[i] = i + 1;
			st.insert(mp(0, i));
		}
	}
	int t1, t2, t3;
	for (int i = 0; i < m; ++i) {
		cin >> t1 >> t2 >> t3;
		t1--;
		t2--;
		v[t1].pb(mp(t3, t2));
		v[t2].pb(mp(t3, t1));
	}
	int cur;
	while (!st.empty()) {
		cur = st.begin()->second;
		st.erase(st.begin());
		if (used[cur]) 
			continue;
		used[cur] = true;
		for (int i = 0; i < v[cur].size(); ++i) {
			if (d[cur] + v[cur][i].first < d[v[cur][i].second]) {
				d[v[cur][i].second] = d[cur] + v[cur][i].first;
				a[v[cur][i].second] = a[cur];
				st.insert(mp(d[v[cur][i].second], v[cur][i].second));
			}
		}
	}
	ll mina = 1000000000000000LL;
	int ansy = -1;
	for (int i = 0; i < n; ++i) {
		if (second[i] && (d[i] < mina)) {
			mina = d[i];
			ansy = i;
		}
	}
	if (ansy == -1) {
		cout << ansy << endl;
		return 0;
	}
	cout << a[ansy] << " " << ansy + 1 << " " <<  mina << endl;
	return 0;
}