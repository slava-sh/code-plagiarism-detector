#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

struct Point {
	ld x, y;
	Point(ld=0, ld=0);
	Point operator-(const Point &) const;
	ld len() const;
};

Point::Point(ld x, ld y): x(x), y(y) 
{}

Point Point::operator-(const Point &p) const {
	return Point(x - p.x, y - p.y);
}

ld Point::len() const {
	return sqrt(x*x + y*y);
}

vector <int> z_func(const string &str) {
	int n = str.size();
	vector <int> z(n);
	z[0] = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i, z[i - l]);
		while (i + z[i] < n && str[z[i]] == str[z[i] + i])
			++z[i];
		if (i + z[i] > r) {
			l = i;
			r = i + z[i];
		}
	}
	return z;
}
const int MaxN = 20002;

int L;
set <string> dict_pref[MaxN],
	dict_suf[MaxN];

set<string> calc(const string &str) {
	set <string> ans;
	if (str.size() == 0)
		return ans;
	vector <int> z = z_func(str);
	int n = str.size();
	vector <set <string> > dict_suf(n + 1);
	set <string> d2;
	for (int i = 0, i2 = n - 1; i < n; ++i, --i2) {
		d2.insert(str.substr(i2, 1));
		if (i < L && i) {
			dict_suf[i2].insert(str.substr(i2, i + 1));
		} else {
			dict_suf[i2] = d2;
		}
	}
	bool was = 0;
	for (int per = 1; per <= min(L, n); ++per) {
		int cur = per;
		set <string> dict;
		while (cur < n && z[cur] >= per)
			cur += per;
		dict.insert(str.substr(0, per));
		dict.insert(dict_suf[cur].begin(), dict_suf[cur].end());
		if (!was || dict.size() < ans.size()) {
			was = 1;
			ans = dict;
		}
	}
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d\n", &L);
	string str;
	getline(cin, str);
	int n = str.size();
	if (L >= n) {
		cout << 1 << endl;
		cout << str << endl;
		return 0;
	}
	set <string> ans;
	ans.insert("a");
	ans.insert("b");
	ans.insert("c");
	int csAns = 3;
	for (int i = 0; i < n; ++i) {
		set <string> cur = calc(str.substr(0, i));
		set <string> cur2 = calc(str.substr(i));
		cur.insert(cur2.begin(), cur2.end());
		if (cur.size() < ans.size())
			ans = cur;
	}
	cout << ans.size() << endl;
	for (set<string>::iterator it = ans.begin(); it != ans.end(); ++it)
		cout << *it << endl;

}