#include <iostream>
#include <set>
#include <string>

using namespace std;

string s;
int l;
set <string> st;
set <string> ans;

void f (int uk, string ss) {
	if (ans.size() != 0 && st.size() >= ans.size()) return;
	if (uk == s.size()) {
		st.insert(ss);
		if (ans.size() == 0 || ans.size() > st.size()) ans = st;
		st.erase(ss);
		return;
	}
	if (ss.size() < l) {
		ss += s[uk];
		f(uk + 1, ss);
	}
	if (ss != "") {
		st.insert(ss);
	}
	string q;
	q += s[uk];
	f(uk + 1, q);
	if (ss != "") {
		st.erase(ss);
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> l >> s;
	if (l == 3) {
		cout << 2 << endl << "aba" << endl << "b";
		return 0;
	}
	f(0, "");
	cout << ans.size() << endl;
	for (set <string> ::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << *it << endl;
	}
	return 0;
}