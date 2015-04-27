#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <utility>

using namespace std;

#define int64 long long int
#define uint64 unsigned long long int
#define mp(a, b) make_pair(a, b)
#define all(a) a.begin(), a.end()
#define _say(a) cout << #a << " = " << a << "\n";

int64 MOD = 1000000007;
int64 PW = 7;

int l, i;
vector <int64> hsh;
vector <int64> pw;
vector <int64> dp;
string s;

inline int64 get(int p, int l) {
	if (p) {
		--p;
		int64 hh = (hsh[p + l] - hsh[p] + MOD) % MOD;
		++p;
		return (hh*pw[s.length() - p]) % MOD;
	} else {
		int64 hh = hsh[l - 1];
		return (hh*pw[s.length() - p]) % MOD;
	}
}

inline bool cmp(int x1, int x2, int l1, int l2) {
	if (x1 > x2) {
		swap(x1, x2);
		swap(l1, l2);
	}
	int64 h1 = get(x1, l1);
	int64 h2 = get(x2, l2);
	h1 = (h1 * pw[x2 - x1]) % MOD;
	return h1 == h2;
}

int main() {
	ios_base::sync_with_stdio(false);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");
	cin >> l;
	cin >> s;
	hsh.resize(s.length());
	pw.resize(s.length() + 1);
	pw[0] = 1;
	hsh[0] = s[0] - 'a' + 1;
	for (i = 1; i < (int)s.length(); ++i) {
		pw[i] = (pw[i - 1] * PW) % MOD;
		hsh[i] = (hsh[i - 1] +  pw[i]*(s[i] - 'a' + 1)) % MOD;
	}
	pw[i] = (pw[i - 1] * PW) % MOD;

	/// Can 1?
	for (int len = 1; len <= (int)l; ++len) {
		if (((int)s.length()) % len == 0) {
			int64 hh = get(0, len);
			bool can = true;
			for (int i = 0; i < s.length(); i += len) {
				int64 hhh = get(i, len);
				if (hhh != hh) {
					i = s.length();
					can = false;
				}
			}
			if (can) {
				cout << 1 << "\n";
				cout << s.substr(0, len);
				return 0;
			}
		}
	}
	/// Can 2?
	dp.assign(s.length() + 1, 0);
	for (int len = 1; len <= (int)l; ++len) {
		int64 hh = get(0, len);
		pair <int, int> s1, s2;
		s1 = mp(0, len);
		int si;
		for (int i = 0; i < s.length(); i += len) {
			int64 hhh = get(i, len);
			if (hhh != hh) {
				si = i;
				i = s.length();
			}
		}
		for (int len2 = 1; len2 <= (int)l; ++len2) {
			int64 h2 = get(si, len2);
			s2 = mp(si, len2);
			dp[0] = 1;

			for (int i = 1; i <= s.length(); ++i) {
				dp[i] = false;
				if (i >= len) {
					if (dp[i - len] && (get(i - len, len) == hh)) {
						dp[i] = true;
					}
				}
				if ((!dp[i])&&(i >= len2)) {
					if (dp[i - len2] && (get(i - len2, len2) == h2)) {
						dp[i] = true;
					}
				}
			}

			if (dp[s.length()]) {
				cout << 2 << "\n";
				cout << s.substr(s1.first, s1.second) << "\n" << s.substr(s2.first, s2.second) < "\n";
				return 0;
			}
		}
	}
	cout << "3\na\nb\nc";
	return 0;
}