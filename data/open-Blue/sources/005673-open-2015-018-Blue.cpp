#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int> > zs;

vector<int> z(string s) {
	vector<int> ret;
	int n = s.length();
	ret.resize(n);
	ret[0] = 0;
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			ret[i] = min(r - i + 1, ret[i - l]);
		while (i + ret[i] < n && s[ret[i]] == s[i + ret[i]])
			++ret[i];
		if (i + ret[i] - 1 > r) {
			l = i;
			r = i + ret[i] - 1;
		}
	}
	return ret;
}

int n;

bool candel(int st, int len1, int len2, int p) {
	if (st > n) return false;
	if (st == n) return true;
	bool res = false;
	if (zs[0][st] >= len1) {
		res = res | candel(st + len1, len1, len2, p);
	}
	if (zs[p][st - p] >= len2) {
		res = res | candel(st + len2, len1, len2, p);
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int us[3];
	us[0] = 0;
	us[1] = 0;
	us[2] = 0;
	int l;
	cin >> l;
	string s;
	string ts;
	cin >> s;
	ts = s;
	n = ts.size();

	while (s.size() > 0) {
		zs.push_back(z(s));
		reverse(s.begin(), s.end());
		s.pop_back();
		reverse(s.begin(), s.end());
	}

	for (int len = 1; len <= l; ++len) {
		bool isOk = true;
		int pos = len;
		while (pos < n) {
			if (zs[0][pos] < len) {
				isOk = false;
				break;
			}
			pos += len;
		}

		if (isOk) {
			cout << 1 << endl;
			for (int i = 0; i < len; ++i) {
				cout << ts[i];
			}
			cout << endl;
			return 0;
		}
	}

	for (int i = 0; i < (int)ts.size(); ++i) {
		us[ts[i] - 'a'] = true;
	}
	int cou = us[0] + us[1] + us[2];
	if (cou < 3) {
		cout << cou << endl;
		for (int i = 0; i < 3; ++i) {
			if (us[i] > 0) {
				char a = 'a' + i;
				cout << a << endl;
			}
		}

		return 0;
	}

	for (int len1 = 1; len1 <= l; ++len1) {
		for (int len2 = 1; len2 <= l; ++len2) {
			bool isOk = false;
			int pos = len1;

			while (pos < n) {
				if (zs[0][pos] < len1) {
					break;
				}
				pos += len1;
			}

			if (candel(pos + len2, len1, len2, pos)) {
				isOk = true;
			}

			if (candel(pos + len2 - len1, len1, len2, pos)) {
				isOk = true;
				pos = pos - len1;
			}

			if (isOk) {
				cout << 2 << endl;
				for (int k = 0; k < len1; ++k) {
					cout << ts[k];
				}
				cout << endl;
				for (int k = pos; k < pos + len2; ++k) {
					cout << ts[k];
				}
				cout << endl;

				return 0;
			}
		}
	}

	cout << 3 << endl;
	cout << "a" << endl;
	cout << "b" << endl;
	cout << "c" << endl;


	return 0;
}