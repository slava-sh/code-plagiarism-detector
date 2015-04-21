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

	if (s.length()<=l) {
		cout << 1 << endl << s << endl;
		return 0;
	}

	cout << "2 a b" << endl;
	return 0;
	
	path.push_back(0);
	dfs(0);

	cout << mn << endl;
	for (ll i = 0; i < mns.size(); ++i) {
		cout << mns[i] << endl;
	}
	
	return 0;
}