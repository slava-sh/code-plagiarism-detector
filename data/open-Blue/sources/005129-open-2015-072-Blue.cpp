#include <iostream>
#include <string>

using namespace std;

const int MAXN = 20000;
string s;
int p[MAXN], l, n;

int main() {
	cin >> l >> s;
	n = s.length();
	for (int i = 1; i < n; ++i) {
		int cur = p[i - 1];
		while (cur > 0 && s[i] != s[cur])
			cur = p[cur - 1];
		if (s[i] == s[cur])
			++cur;
		p[i] = cur;
	}
	if (p[n - 1] * 2 < n || n - p[n - 1] > l)
		cout << 2 << endl << 'a' << endl << 'b' << endl;
	else {
		cout << 1 << endl;
		for (int i = 0; i < n - p[n - 1]; ++i)
			cout << s[i];
		cout << endl;
	}
	cin >> n;
	return 0;
}