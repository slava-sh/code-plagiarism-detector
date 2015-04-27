#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, a[N], x[N], t[N];
bool in[N], f[N];

int main() {
	memset(f, true, sizeof(f));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		char s[10];
		scanf("%s%d", s, x+i);
		t[i] = s[0] == '+' ? 1 : -1;
		if (t[i] < 0 && !in[x[i]]) t[0]++;
		in[x[i]] = t[i] > 0;
	}
	a[0] = t[0];
	for (int i = 1; i <= m; ++i) {
		a[i] = a[i-1] + t[i];
	}
	vector<int> u;
	for (int i = 1; i <= m; ++i) {
		if (t[i] > 0) {
			if (a[i-1]) f[x[i]] = false;
		} else {
			if (a[i]) f[x[i]] = false;
		}
		if (f[x[i]]) {
			for (; !u.empty(); u.pop_back()) {
				f[u.back()] = false;
			}
			f[x[i]] = true;
		}
		u.push_back(x[i]);
	}
	u.clear();
	for (int i = m; i; --i) {
		if (t[i] < 0 && !a[i]) {
			for (; !u.empty(); u.pop_back()) {
				if (u.back() != x[i]) f[u.back()] = false;
			}
		}
		u.push_back(x[i]);	
	}
	vector<int> v;
	for (int i = 1; i <= n; ++i) if (f[i]) v.push_back(i);
	printf("%d\n", (int)v.size());
	for (size_t i = 0; i < v.size(); ++i) {
		if (i) putchar(' ');
		printf("%d", v[i]);
	}
}