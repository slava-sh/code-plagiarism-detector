#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

string format(string a) {
	switch (a.length()) {
	case 3: return a; break;
	case 4: return a.substr(0, 2) + '-' + a.substr(2, 2); break;
	case 5: return a.substr(0, 3) + '-' + a.substr(3, 2); break;
	case 6: return a.substr(0, 2) + '-' + a.substr(2, 2) + '-' + a.substr(4, 2); break;
	case 7: return a.substr(0, 3) + '-' + a.substr(3, 2) + '-' + a.substr(5, 2); break;
	}
	return "";
}

bool check(string a) {
	if (a.length() == 0)
		return false;
	if (a[0] == '0') {
		return false;
	}
	return true;
}

int main() {
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);

	map<string, string> s;
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string code;
		int k;
		cin >> ws >> code >> ws >> k;
		for (int j = 0; j < k; j++) {
			string key;
			cin >> ws >> key;
			if (check(code) && check(key))
				s.insert(make_pair(code+key, '+'+code+'('+key+')'));
		}
	}
	ll m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string b, ans;
		bool found = false;
		cin >> ws >> b;
		for (int j = 0; j <= 11; j++) {
			string s1 = b.substr(0, j),
				s2 = b.substr(j, b.length() - j);
			if (s.find(s1) != s.end() && s2.length() >= 3 && s2.length() <= 7 && s1.length() > 0) {
				if (check(format(s2))) {
					ans = s.find(s1)->second+format(s2);
					cout << ans << endl;
					found = true;
					break;
				}
			}
		}
		if (!found) {
			cout << "Incorrect" << endl;
		}
	}
	return 0;
}