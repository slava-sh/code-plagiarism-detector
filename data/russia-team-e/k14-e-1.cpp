#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "numbers."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()

const int MAXN = 100500;
const int INF = 1 << 30;

int n, test;
map < string, int > ind;
int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			string x;
			int k; 
			cin >> x >> k;
			for (int j = 1; j <= k; j++) {
				string y;
				cin >> y;
				string s = x + y;
				ind[s] = x.sz;
			}
		}
		cin >> test;
		for (int u = 1; u <= test; u++) {
			string s, cur = "", ans = ""; 
			cin >> s;
			bool ok = 0, cor = 1;
			for (int i = 0; i < s.sz; i++) {
				cur += s[i];
				int k = ind[cur];
				if (k!=0) {
					if (s[0] == '0') cor = 0;
					ok = 1;
					ans += '+';
					for (int j = 0; j < ind[cur]; j++)
						ans += s[j];
					ans += '(';
					for (int j = k; j < cur.sz; j++) ans += cur[j];
					if (s[k] == '0') cor = 0;
					ans += ')';
					int last = s.sz - cur.sz, l = cur.sz, r = s.sz - 1;
					if (s[l] == '0') cor = 0;
					if (last == 3) {
						for (int j = l; j <= r; j++)  ans += s[j];
					}
					if (last == 4) {
						for (int j = l; j <= (l + r) / 2; j++)  ans += s[j];
						ans += '-';
						for (int j = (l + r) / 2 + 1; j <= r; j++)  ans += s[j];
					}
					if (last == 5) {
						for (int j = l; j <= (l + r) / 2; j++)
							ans += s[j];
						ans += '-';
						for (int j = (l + r) / 2 + 1; j <= r; j++)
							ans += s[j];
					}
					if (last == 6) {
						int d = (r - l + 1) / 3;
						for (int j = l; j <= l + d - 1; j++)
							ans += s[j];
						ans += '-';
						for (int j = l + d; j <= l + d + d - 1; j++)
							ans += s[j];
						ans += '-';
						for (int j = l + d + d; j <= r; j++)
							ans += s[j];
					}
					if (last == 7) {
						int d = (r - l) / 3;
						for (int j = l; j <= l + d; j++)
							ans += s[j];
						ans += '-';
						for (int j = l + d + 1; j <= l + d + d; j++)
							ans += s[j];
						ans += '-';
						for (int j = l + d + d + 1; j <= r; j++)
							ans += s[j];
					}
					break;
				}
			}
			if (ok == 1 && cor == 1)
					cout << ans << endl;
				else
					cout << "Incorrect" << endl;
		}
	return 0;
}
