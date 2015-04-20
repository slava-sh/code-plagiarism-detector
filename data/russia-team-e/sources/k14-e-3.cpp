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

int n, m;
map < string, int > ind;
int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		cin >> n;
		for (int i = 1; i <= n; i++) {
				string x = "";
				int p, k;
				cin >> p >> k;
				while (p) {
					x += char(p % 10 + '0');
					p /= 10;
				}
				reverse(x.begin(),x.begin());
			for (int j = 1; j <= k; j++) {
				string y = "";
				int p;
				cin >> p;
				while (p) {
					y += char(p % 10 + '0');
					p /= 10;
				}
				reverse(y.begin(),y.begin());
				string s = x + y;
				ind[s] = x.sz;
			}
		}
		cin >> m;
		for (int u = 1; u <= m; u++) {
			string s, cur = "", ans = "";
			cin >> s;
			bool ok = 0, cor = 1;
			for (int i = 0; i < s.sz; i++) {
				cur += s[i];
				int k = ind[cur];
				if (k) {
				    int l1 = 0, r1 = k - 1;
					int l2 = k, r2 = i;
					int l3 = i + 1, r3 = s.sz;
					if (s[l1] == '0' || s[l2] == '0' || s[l3] == '0')
						cor = 0;
					ok = 1;
					ans += '+';
					for (int j = l1; j <= r1; j++)
						ans += s[j];
					ans += '(';
					for (int j = l2; j <= r2; j++)
						ans += s[j];
					ans += ')';
					int range = s.sz - cur.sz;
					if (range == 3) {
						ans += s[l3];
						ans += s[l3 + 1];
						ans += s[l3 + 2];
					}
					else if (range == 4) {
						ans += s[l3];
						ans += s[l3 + 1];
						ans += '-';
						ans += s[l3 + 2];
						ans += s[l3 + 3];
					}
					else if (range == 5) {
						ans += s[l3];
						ans += s[l3 + 1];
						ans += s[l3 + 2];
						ans += '-';
						ans += s[l3 + 3];
						ans += s[l3 + 4];
					}
					else if (range == 6) {
						ans += s[l3];
						ans += s[l3 + 1];
						ans += '-';
						ans += s[l3 + 2];
						ans += s[l3 + 3];
						ans += '-';
						ans += s[l3 + 4];
						ans += s[l3 + 5];
					}
					else if (range == 7) {
						ans += s[l3];
						ans += s[l3 + 1];
						ans += s[l3 + 2];
						ans += '-';
						ans += s[l3 + 3];
						ans += s[l3 + 4];
						ans += '-';
						ans += s[l3 + 5];
						ans += s[l3 + 6];
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
