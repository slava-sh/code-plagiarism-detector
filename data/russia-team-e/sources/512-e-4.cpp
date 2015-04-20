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

int getCountry (string &s, int i) {
	for (int k = 0; k < a[i].code.size(); k++) {
		if (a[i].code[k] != s[k]) {
			return false;
		}
	}
	return true;
}

bool getOperator (string &s, int i, int j, int ind) {
	for (int k = 0; k < a[i].region[j].size(); k++) {
		if (a[i].region[j][k] != s[ind + k]) {
			return false;
		}
	}
	return true;
}

bool checkNum (string &s) {
	for (int i = 1; i <= n; i++) {
		ansSt = "";
		int ind = 0;
		if (s[0] == '0') {
			return false;
		}
		if (!getCountry(s, i)) {
			continue;
		} else {
			ind = a[i].code.size();
		}
		if (s[ind] == '0') {
			continue;
		}
		for (int j = 0; j < a[i].region.size(); j++) {
			ind = a[i].code.size();
			if (!getOperator(s, i, j, ind)) {
				continue;
			} else {
				ind += a[i].region[j].size();
			}
			if (s[ind] == '0') {
				continue;
			}
			ansSt = "+" + a[i].code + "(";
			ansSt += a[i].region[j] + ")";
			if (ind == 8) {
				ansSt += s.substr(8, 3);
			}
			if (ind == 7) {
				ansSt = ansSt + s[7] + s[8] + "-" + s[9] + s[10];
			}
			if (ind == 6) {
				ansSt = ansSt + s.substr(6, 3) + "-" + s[9] + s[10];
			}
			if (ind == 5) {
				ansSt = ansSt + s.substr(5, 2) + "-" + s.substr(7, 2) + "-" + s.substr(9, 2); 
			}
			if (ind == 4) {
				ansSt = ansSt + s.substr(4, 3) + "-" + s.substr(7, 2) + "-" + s.substr(9, 2); 
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