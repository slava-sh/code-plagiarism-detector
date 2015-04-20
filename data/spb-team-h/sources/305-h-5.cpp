#include <fstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

pair <pair <string, string>, string> s[1393];
int main() {
	freopen("names.in", "r", stdin);
	freopen("names.out", "w", stdout);
	long n;
	string check1, check2, check3;
	cin >> n;
	for (long i = 0; i < n; ++i) {
		cin >> check1 >> check2 >> check3;
		if ((check3[check3.length() - 1] == 'h') && (check3[check3.length() - 2] = 'c') && (check3[check3.length() - 3] == 'i') && (check3[check3.length() - 4] = 'v')) {
			s[i].first.first = check1;
			s[i].first.second = check2;
			s[i].second = check3;
		}
		else {
			s[i].first.first = check3;
			s[i].first.second = check1;
			s[i].second = check2;
		}
	}
	sort(s, s + n);
	for (long i = 0; i < n; ++i) {
		cout << s[i].first.first << " " << s[i].first.second << " " << s[i].second << endl;
	}
	return 0;
}