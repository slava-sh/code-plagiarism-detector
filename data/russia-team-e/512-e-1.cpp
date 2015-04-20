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

int getCountry (string s) {
	for (int i = 1; i <= n; i++) {
		if (s.substr(0, a[i].code.size()) == a[i].code) {
			return i;
		}
	}
	return -1;
}

int getOperator (string s, int p) {
	for (int i = 0; i < a[p].region.size(); i++) {
		if (s.substr(0, a[p].region[i].size()) == a[p].region[i]) {
			return i;
		}
	}
	return -1;
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
		cId = getCountry(s);
		if (cId == -1) {
			cout << "Incorrect\n";
			continue;
		}
		s.erase(0, a[cId].code.size());
		ansSt = "+" + a[cId].code + "(";
		opId = getOperator(s, cId);
		if (opId == -1) {
			cout << "Incorrect\n";
			continue;
		}
		ansSt += a[cId].region[opId] + ")";
		s.erase(0, a[cId].region[opId].size());
		if (s[0] == '0') {
			cout << "Incorrect\n";
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
		cout << ansSt << "\n";
	}
	return 0;
}