#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string s[1000][3], str;
int n;

bool f(string a, string b) {
	if (a.size() != b.size()) {
		return false;
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return false;
		}
	}
	return true;
}

int main(){
	freopen("names.in", "r", stdin);
	freopen("names.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i][0] >> s[i][1] >> s[i][2];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (f(s[i][0], s[j][0])) {
					str = s[i][0];
					s[i][0] = s[i][2];
					s[i][2] = s[i][1];
					s[i][1] = str;
					str = s[j][0];
					s[j][0] = s[j][2];
					s[j][2] = s[j][1];
					s[j][1] = str;
				}
            }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (f(s[i][0], s[j][1])) {
				str = s[i][0];
				s[i][0] = s[i][2];
				s[i][2] = s[i][1];
				s[i][1] = str;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (s[j][0] > s[j + 1][0]) {
				str = s[j][0];
				s[j][0] = s[j + 1][0];
				s[j + 1][0] = str;
				str = s[j][1];
				s[j][1] = s[j + 1][1];
				s[j + 1][1] = str;
				str = s[j][2];
				s[j][2] = s[j + 1][2];
				s[j + 1][2] = str;
			}
        }
	}
	for (int i = 0; i < n; i++) {
		cout << s[i][0] << " " << s[i][1] << " " << s[i][2] << "\n";
	}
	return 0;
}