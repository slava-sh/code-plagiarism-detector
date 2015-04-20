#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long li;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const li INF = 1e15;

/*struct nd {
	int mx1, mx2;
	int pr;
} g[200005];

vector<int> a[200005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(a[v][i], v);
			if (g[to].mx1 > g[v].mx1) {
				g[v].mx2 = g[v].mx1;
				g[v].mx1 = g[to].mx1;
			}
		}
	}
}*/

/*vector< pair<li, li> > a[5005];
pair<li, li> ans[5005];*/

int main() {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n, m, i, j, j1, h, a1, a2, o, t;
	vector<string> c2[105];
	string c1[105], s, s1, s2;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> c1[i];
		cin >> m;
		for (j = 0; j < m; j++) {
			cin >> s;
			c2[i].pb(s);
		}
	}
	cin >> m;
	for (i = 0; i < m; i++) {
		t = 0;
		cin >> s;
		s1.clear();
		for (j = 0; j < s.length(); j++) {
			s1.pb(s[j]);
			for (h = 0; h < n; h++)
				if (s1 == c1[h])
					break;
			if (h == n)
				continue;
			a1 = h;
			s2.clear();
			j1 = j + 1;
			for (; j1 < s.length(); j1++) {
				s2.pb(s[j1]);
				for (h = 0; h < c2[a1].size(); h++)
					if (s2 == c2[a1][h])
						break;
				if (h == c2[a1].size())
					continue;
				a2 = h;
				j1++;
				o = s.length() - j1;
				if (o < 3 || o > 7 || s[j1] == '0')
					continue;
				cout << "+" << c1[a1] << '(' << c2[a1][a2] << ')';
				if (o == 3) {
					for (; j1 < s.length(); j1++)
						cout << s[j1];
				} else if (o == 4) {
					cout << s[j1] << s[j1 + 1] << '-' << s[j1 + 2] << s[j1 + 3];
				} else if (o == 5) {
					cout << s[j1] << s[j1 + 1] << s[j1 + 2] << '-' << s[j1 + 3] << s[j1 + 4];
				} else if (o == 6) {
					cout << s[j1] << s[j1 + 1] << '-' << s[j1 + 2] << s[j1 + 3] << '-' << s[j1 + 4] << s[j1 + 5];
				} else {
					cout << s[j1] << s[j1 + 1] << s[j1 + 2] << '-' << s[j1 + 3] << s[j1 + 4]
					<< '-' << s[j1 + 5] << s[j1 + 6];
				}
				t = 1;
				break;
			}
			if (j1 == s.length())
				continue;
			break;
		}
		if (t == 0)
			cout << "Incorrect";
		cout << "\n";
	}
	/*li n, m, t[5005], u[5005], i, j, x, y, c;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> t[i];
	for (i = 0; i < m; i++) {
		cin >> x >> y >> c;
		x--;
		y--;
		a[x].pb(mp(y, c));
		a[y].pb(mp(x, c));
	}
	for (i = 0; i < n; i++) {
		u[i] = 0;
		ans[i] = mp(INF, -1);
	}
	for (i = 0; i < n; i++) {
		if (t[i] == 2) {
			u[i] = 1;
			ans[i] = mp(0, i);
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < a[i].size(); j++) {
			if (u[a[i][j].fs]) {
				if (ans[i].fs > ans[a[i][j].fs].fs + a[i][j].sc) {
					ans[i] = mp(ans[a[i][j].fs].fs + a[i][j].sc, ans[a[i][j].fs].sc);
				}
			}
		}
		u[i] = 1;
	}
	li aans = INF, ians, jans;
	for (i = 0; i < n; i++) {
		if (t[i] == 1) {
			if (aans > ans[i].fs) {
				aans = ans[i].fs;
				ians = i;
				jans = ans[i].sc;
			}
		}
	}
	if (aans == INF) {
		cout << -1;
	} else {
		cout << ians + 1 << ' ' << jans + 1 << ' ' << aans;
	}*/
	/*int n, i, x, y, s1, s2;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(s1);*/
	return 0;
}
/*
6 7
1 0 1 2 2 0
1 3 3
1 2 4
2 3 3
2 4 2
1 6 5
3 5 6
5 6 1

2
7 3
981
3517
812
351 3
34712
1234
963
8
79818266456
35196328463
78122472557
01234567890
73517960326
35134712239
35112342013
78120203040
*/