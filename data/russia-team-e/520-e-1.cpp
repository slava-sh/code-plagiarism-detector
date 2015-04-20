#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, m;
string str;
string c[200];
int k[200];
string key[110][110];

bool good(string s1, string s2) {
	if (s1.length() > s2.length()) return false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) return false;
	}
	return true;
}

string gimme(string s) {
	if (s.length() == 3) {
		return s;
	} else if (s.length() == 4) {
		string res = string() + s[0];
		res += string() + s[1] + "-" + s[2] + s[3];
		return res;
	} else if (s.length() == 5) {
		string res = string() + s[0];
		res += string() + s[1] + s[2] + "-" + s[3] + s[4];
		return res;
	} else if (s.length() == 6) {
		string res = string() + s[0];
		res += string() + s[1] + "-" + s[2] + s[3] + "-" + s[4] + s[5];
		return res;
	} else {
		string res = string() + s[0];
		res += string() + s[1] + s[2] + "-" + s[3] + s[4] + "-" + s[5] + s[6];
		return res;
	}
}

string ans(string s) {
	for (int i = 0; i < n; i++) {
		if (good(c[i], s)) {
			string l = s.substr(c[i].length(), s.length() - c[i].length());
			for (int j = 0; j < k[i]; j++) {
				if (good(key[i][j], l)) {
					string p = l.substr(key[i][j].length(), l.length() - key[i][j].length());
					if (p[0] != '0' && p.length() >= 3 && p.length() <= 7) {
						string res = "+";
						res += c[i];
						res += "(" + key[i][j] + ")";
						res += gimme(p);
						return res;
					}
				}
			}
		}
	}
	return "Incorrect";
}

int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> key[i][j];
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> str;
		cout << ans(str) << endl;
	}
}