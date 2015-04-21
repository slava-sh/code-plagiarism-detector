#pragma comment(linker, "/STACK:16777216")

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

vector<long long> p;
vector<long long> p2;

long long dfs(long long depth, long long k) {
	if (depth == k)
		return 1;
	return dfs(depth + 1, k) * ((p[depth] + 1) / 2);
}

//vector<set<pair<int, int> > > g;
//vector<set<pair<int, int> > > g2;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//#define FILE_NAME ""
	//	freopen(FILE_NAME ".in", "r", stdin);
	//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	long long n, k;
	cin >> n >> k;

	for (long long i = 2; i * i <= n; ++i)
		while (n % i == 0) {
			n /= i;
			p2.push_back(i);
		}
	if (n != 1) {
		p2.push_back(n);
	}
	long long ans = numeric_limits<long long>::max();
	for (int i = 0; i < 1000000; ++i) {
		//swap(p2[rand() % p2.size()], p2[rand() % p2.size()]);
		p = p2;
		random_shuffle(p.begin(), p.end());
		while (p.size() > k) {
			p[rand() % (p.size() - 1)] *= p.back();
			p.pop_back();
		}
		while (p.size() < k)
			p.push_back(1);
		ans = min(ans, dfs(0, k));
	}
	cout << ans;

	/*int l;
	cin >> l;
	string a;
	cin >> a;
	vector<int> p(a.size());
	p[0] = 0;
	for (int i = 1, k = 0; i < a.size(); ++i) {
		while (k > 0 && a[i] != a[k])
			k = p[k - 1];
		if (a[i] == a[k])
			++k;
		p[i] = k;
	}
	if (a.size() - p[a.size() - 1] != 0 && a.size() % (a.size() - p[a.size() - 1]) == 0 && a.size() - p[a.size() - 1] <= l) {
		cout << 1 << "\n";
		for (int i = 0; i < a.size() - p[a.size() - 1]; ++i)
			cout << a[i];
	}
	else {
		cout << 2 << "\n";
		cout << "a\n";
		cout << "b\n";
	}*/
	/*for (int i = 1; i <= l; ++i) {
		vector<int> b(a.size(), 0);
		for (int k = 0; k < i; ++k)
			b[k] = 1;
		for (int j = i; j < a.size();) {
			bool flag = true;
			for (int k = 0; k < i; ++k)
				if (a[k] != a[j + k]) {
					flag = false;
					break;
				}
			if (flag) {
				for (int k = 0; k < i; ++k)
					b[j + k] = 1;
				j += i;
			}
			else
				++j;
		}
	}*/


	/*int n, m, d;
	scanf("%d%d%d", &n, &m, &d);
	//cin >> n >> m >> d;
	g2.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v, t;
		//cin >> u >> v >> t;
		scanf("%d%d%d", &u, &v, &t);
		--u;
		--v;
		g2[u].insert(make_pair(t, v));
		g2[v].insert(make_pair(t, u));
	}
	int q;
	//cin >> q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		g = g2;
		int a, b;
		//cin >> a >> b;
		scanf("%d%d", &a, &b);
		--a, --b;
		queue<pair<pair<int, int>, int> > Q;
		for (set<pair<int, int> >::iterator j = g[a].begin(); j != g[a].end();) {
			Q.push(make_pair(make_pair(j->second, j->first), 1));
			g[a].erase(j++);
		}
		//set<pair<int, int> > S;
		bool flag = true;
		while (!Q.empty()) {
			int v = Q.front().first.first;
			int t = Q.front().first.second;
			int tm = Q.front().second;
			Q.pop();
			if (v == b) {
				cout << tm << "\n";
				flag = false;
				break;
			}
			//if (S.find(make_pair(v, t)) != S.end())
			//	continue;
			//S.insert(make_pair(v, t));
			set<pair<int, int> >::iterator last = g[v].upper_bound(make_pair(t + d + 1, 0));
			for (set<pair<int, int> >::iterator j = g[v].lower_bound(make_pair(t - d, 0)); j != last;) {
				//cout << j->first << " ";
				if (abs(j->first - t) <= d) {
					Q.push(make_pair(make_pair(j->second, j->first), tm + 1));
					g[v].erase(j++);
				}
				else {
					++j;
				}
			}
			//cout << endl;
		}
		if (flag) {
			cout << -1 << "\n";
		}
	}*/

	/*long long n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << (n + 1) / 2;
		return 0;
	}

	if (k == 2) {
		for (long long i = 2; i * i <= n; ++i)
			while (n % i == 0) {
				n /= i;
				p.push_back(i);
			}
		if (n != 1) {
			p.push_back(n);
		}
		long long ans = -1;
		for (int i = 0; i < (1 << p.size()); ++i) {
			long long a = 1, b = 1;
			for (int j = 0; j < p.size(); ++j)
				if ((1 << j) & i)
					a *= p[j];
				else
					b *= p[j];
			long long cur = ((a + 1) / 2) * ((b + 1) / 2);
			if (ans == -1 || cur < ans)
				ans = cur;
		}
		cout << ans;
		return 0;
	}

	cout << 2;*/

	/*while (p.size() > k) {
		p[k - 1] *= p.back();
		p.pop_back();
	}
	reverse(p.begin(), p.end());
	while (p.size() < k)
		p.push_back(1);
	cout << dfs(0, k);*/

	return 0;
}