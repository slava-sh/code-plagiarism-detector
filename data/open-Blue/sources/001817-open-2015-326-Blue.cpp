#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

string s;
ll l;
ll n;

vector<ll> path;
ll mn = 1e15;
vector<string> mns;

void dfs(ll i) {
	if (i == s.length()) {
		set<string> used;
		for (ll j = 1; j < path.size(); ++j) {
			used.insert(s.substr(path[j-1], path[j]-path[j-1]));
		}
		if (used.size() < mn) {
			mn = used.size();
			mns.clear();
			for (auto it = used.begin(); it != used.end(); ++it) {
				mns.push_back(*it);
			}
		}
		return;
	} 
	for (ll j = i+1; j <= s.length(); ++j) {
		if (j-path.back()>l) {
			break;
		}
		path.push_back(j);
		dfs(j);
		path.pop_back();
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> l;
	cin >> ws >> s;
	n = s.length();

	if (s.length()<=l) {
		cout << 1 << endl << s << endl;
		return 0;
	}

	set<char> z;
	for (ll i = 0; i < s.length(); ++i) {
		z.insert(s[i]);
	}
	if (z.size() == 1) {
		cout << z.size() << endl;
		for (auto it = z.begin(); it != z.end(); ++it) {
			cout << *it << endl;
		}
		return 0;
	}

	for (ll j = 1; j*j<=n; ++j) {
		if (n % j == 0) {
			ll len = n/j;
			if (len <= l) {
				bool ok = true;
				for (ll k = 0; k < n; ++k) {
					if (s[k%len] != s[k]) {
						ok = false;
						break;
					}
				}
				if (ok) {
					cout << 1 << endl;
					cout << s.substr(0, len) << endl;
					return 0;
				}
			}
		}
	}
	/*
	path.push_back(0);
	dfs(0);

	cout << mn << endl;
	for (ll i = 0; i < mns.size(); ++i) {
		cout << mns[i] << endl;
	}*/
	
	return 0;
}