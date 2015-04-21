#include <iostream>
#include <string>
#include <set>

using namespace std;

const int MAXN = 20001;
const long long MOD = 1000000007;
const long long X = 5;
string s;
int p[MAXN], l, n;
long long h[MAXN], x[MAXN];
set <char> st;

int main() {
	cin >> l >> s;
	n = s.length();
	if (n == 1 || l >= n) {
		cout << s.length() << endl << s << endl;
		cin >> n;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		st.insert(s[i]);
	for (int i = 1; i < n; ++i) {
		int cur = p[i - 1];
		while (cur > 0 && s[i] != s[cur])
			cur = p[cur - 1];
		if (s[i] == s[cur])
			++cur;
		p[i] = cur;
	}
	if (p[n - 1] * 2 >= n && n % (n - p[n - 1]) == 0 && n - p[n - 1] <= l) {
		cout << 1 << endl;
		for (int i = 0; i < n - p[n - 1]; ++i)
			cout << s[i];
		cout << endl;
		return 0;
	}
	x[0] = 1;
	for (int i = 1; i <= n; ++i)
		x[i] = x[i - 1] * X % MOD;
	h[0] = s[0] - 'a';
	for (int i = 1; i < n; ++i)
		h[i] = (h[i - 1] * X % MOD + s[i] - 'a') % MOD;
	for (int l1 = 1; l1 <= l; ++l1) {
		long long curh = h[l1 - 1];
		int p = l1 - 1;
		while (true) {
			long long ph = (h[p + l1] - h[p] * x[l1] + MOD) % MOD;
			if (ph == curh)
				p += l1;
			else {
				for (int l2 = 1; l2 <= l; ++l2) {
					long long curh2 = (h[p + l2] - h[p] * x[l2] + MOD) % MOD;
					int p2 = p + l2;
					while (true) {
						if (p2 == n - 1) {
							cout << 2 << endl;
							for (int i = 0; i < l1; ++i)
								cout << s[i];
							cout << endl;
							for (int i = p + 1; i <= p + l2; ++i)
								cout << s[i];
							cout << endl;
							cin >> n;
							return 0;
						}
						long long ph1 = -1, ph2 = -1;
						if (p2 + l1 < n)
							ph1 = (h[p2 + l1] - h[p2] * x[l1] + MOD) % MOD;
						if (p2 + l2 < n)
							ph2 = (h[p2 + l2] - h[p2] * x[l2] + MOD) % MOD;
						if (ph1 == curh)
							p2 += l1;
						if (ph2 == curh2)
							p2 += l2;
						if (ph1 != curh && ph2 != curh2)
							break;
					}
				}
				break;
			}
		}
	}
	cout << st.size() << endl;
	for (set <char>::iterator cur = st.begin(); cur != st.end(); ++cur)
		cout << *cur << endl;
	cin >> n;
	return 0;
}