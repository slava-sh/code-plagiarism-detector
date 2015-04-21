#include <iostream>
#include <set>
#include <string>
#include <map>

using namespace std;

string s;
int l;
map <string, int> st;
map <string, int> ans;

void f (int uk, string ss) {
	if (ans.size() != 0 && st.size() >= ans.size()) {
		return;
	}
	if (uk == s.size()) {
		st[ss]++;
		if (ans.size() == 0 || ans.size() > st.size()) ans = st;
		st[ss]--;
		if (st[ss] == 0) {
			st.erase(ss);
		}
		return;
	}
	if (ss.size() < l) {
		string s1 = ss + s[uk];
		f(uk + 1, s1);
	}
	if (ss != "") {
		st[ss]++;
	}
	string q;
	q += s[uk];
	f(uk + 1, q);
	if (ss != "") {
		st[ss]--;
		if (st[ss] == 0) {
			st.erase(ss);
		}
	}
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	cin >> l >> s;
	f(0, "");
	cout << ans.size() << endl;
	for (map <string, int> ::iterator it = ans.begin(); it != ans.end(); ++it) {
		cout << (*it).first << endl;
	}
	return 0;
}