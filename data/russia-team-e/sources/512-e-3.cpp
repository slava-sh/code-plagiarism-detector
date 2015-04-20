#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

struct country {
	string code;
	vector <string> region;
};

vector <country> a;
string s, ansSt;;
int n, k, m, cId, opId;

int getCountry (string s, int i) {
	return (s.substr(0, a[i].code.size()) == a[i].code);
}

bool getOperator (string s, int i, int j) {
	return (s.substr(0, a[i].region[j].size()) == a[i].region[j]);
}

bool checkNum (string s) {
	string backup = s;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < a[i].region.size(); j++) {
			s = backup;
			ansSt = "";
			if (s[0] == '0') {
				continue;
			}
			if (!getCountry(s, i)) {
				continue;
			} else {
				s.erase(0, a[i].code.size());
			}
			if (s[0] == '0') {
				continue;
			}
			ansSt = "+" + a[i].code + "(";
			if (!getOperator(s, i, j)) {
				continue;
			} else {
				ansSt += a[i].region[j] + ")";
				s.erase(0, a[i].region[j].size());
			}
			if (s[0] == '0') {
				continue;
			}
			if (s.size() == 3) {
				ansSt += s;
			}
			if (s.size() == 4) {
				ansSt = ansSt + s[0] + s[1] + "-" + s[2] + s[3];
			}
			if (s.size() == 5) {
				ansSt = ansSt + s.substr(0, 3) + "-" + s[3] + s[4];
			}
			if (s.size() == 6) {
				ansSt = ansSt + s.substr(0, 2) + "-" + s.substr(2, 2) + "-" + s.substr(4, 2); 
			}
			if (s.size() == 7) {
				ansSt = ansSt + s.substr(0, 3) + "-" + s.substr(3, 2) + "-" + s.substr(5, 2); 
			}
			return true;
		}
	}
	return false;
}

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("numbers.in", "r", stdin);freopen("numbers.out", "w", stdout);
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i].code >> k;
		for (int j = 1; j <= k; j++) {
			cin >> s;
			a[i].region.push_back(s);
		}
	}
	cin >> m;
	for (int p = 1; p <= m; p++) {
		cin >> s;
		if (checkNum(s)) {
			cout << ansSt << "\n";
		} else {
			cout << "Incorrect\n";
		}
	}
	return 0;
}