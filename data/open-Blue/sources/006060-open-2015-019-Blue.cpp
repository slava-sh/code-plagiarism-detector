#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

set <string> st[1013][1013];
string s;
int l;

set <string> f (int ll, int rr) {
	if (st[ll][rr].size() != 0) return st[ll][rr];
	if (rr - ll <= l) {
		string s1;
		for (int i = ll; i < rr; i++) {
			s1 += s[i];
		}
		st[ll][rr].insert(s1);
		return st[ll][rr];
	}
	for (int i = ll + 1; i < rr; i++) {
		set <string> ans;
		set <string> l1 = f(ll, i),
					 r1 = f(i, rr);
		for (set <string> ::iterator it = l1.begin(); it != l1.end(); ++it) {
			ans.insert(*it);
		}
		for (set <string> ::iterator it = r1.begin(); it != r1.end(); ++it) {
			ans.insert(*it);
		}
		if (st[ll][rr].size() == 0 || st[ll][rr].size() > ans.size()) {
			st[ll][rr] = ans;
		}
	}
	return st[ll][rr];
}

int main () {
	cin >> l >> s;
	f(0, s.size());
	cout << st[0][s.size()].size() << endl;
	for (set <string> ::iterator it = st[0][s.size()].begin(); it != st[0][s.size()].end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}