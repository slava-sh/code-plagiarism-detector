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
		s[i].first.first = check1;
		s[i].first.second = check2;
		s[i].second = check3;
	}
	long num1 = 0;
	for (long i = 0; i < n; ++i) {
		num1 = 0;
		for (long j = 0; j < n; ++j) {
			if (i != j) {
				if ((s[i].first.first == s[j].first.first) || (s[i].first.first == s[j].first.second))
					num1++;
			}
		}
		if (num1 == 1) {
			check1 = s[i].first.first;
			check2 = s[i].first.second;
			check3 = s[i].second;
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