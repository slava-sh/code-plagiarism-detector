#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <utility>

#define pb(x) push_back(x)
#define fi first
#define se second
#define mp make_pair
#define FNAME "numbers"

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAX_N = 200;

int n, m;
string reg[MAX_N][MAX_N];
string c[MAX_N];
int k[MAX_N];
string s;

int len(ll x) {
	int res = 0;
	do {
		++res;
		x /= 10;
	} while (x);
	return res;	
}

string toString(int x) {
	string res = "";
	do {
		res = char(x % 10) + res;
		x /= 10;
	} while(x);
	return res;
}

void print(string s) {
	if (s.length() == 3)
		cout << s;
	else if (s.length() == 4) {
		cout << s[0] << s[1] << "-" << s[2] << s[3];
	} else if (s.length() == 5) {
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4];
	} else if (s.length() == 6) {
		cout << s[0] << s[1] << "-" << s[2] << s[3] << "-" << s[4] << s[5];
	} else {
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4] << "-" << s[5] << s[6];
	}
}

bool ok(int x) {
//	cout << s << " " << x << " " << s.substr(0, c[x].length()) << endl;
	if (s.substr(0, c[x].length()) != c[x])
		return 0;
//	for (int i = 0;i < k[x];++i)
//		cout << reg[x][i] << " ";
//	cout << endl;	
	for (int i = 3;i <= 5;++i) {
		string cur = s.substr(c[x].length(), i);
//		cout << i << " " << s.substr(c[x].length(), i) << endl;
		int l = 0, r = k[x];
		while (r - l > 1) {
			int m = (l + r) >> 1;
			if (cur >= reg[x][m])
				l = m;
			else
				r = m;
		}
//		cout << "bs" << reg[x][l] << endl;
		if (cur == reg[x][l] && s[c[x].length() + reg[x][l].length()] != '0') {
			cout << "+" << c[x] << "(" << reg[x][l] << ")";
			print(s.substr(c[x].length() + reg[x][l].length(), 
				s.length() - c[x].length() - reg[x][l].length()));
			cout << endl;
			return 1;
		}
	}
	return 0;
}

void solve() {
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0;i < n;++i) {
		cin >> c[i] >> k[i];
		for (int j = 0;j < k[i];++j)
			cin >> reg[i][j];
		sort(reg[i], reg[i] + k[i]);
	}
	cin >> m;
	for (int i = 0;i < m;++i) {
		cin >> s;
//		cout << s << endl;
		if (s.length() < 11) {
			cout << "Incorrect\n";
			continue;
		}
		bool b = 0;
		for (int j = 0;j < n;++j)
			if (ok(j)) {
				b = 1;
				break;
			}
		if (!b) {
			cout << "Incorrect\n";
			continue;
		}
	}
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
