#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

map< string, set< string > > middles;

string split(const string &str) {
	if (str.length() == 7) return str.substr(0, 3) + "-" + str.substr(3, 2) + "-" + str.substr(5, 2);
	if (str.length() == 6) return str.substr(0, 2) + "-" + str.substr(2, 2) + "-" + str.substr(4, 2);
	if (str.length() == 5) return str.substr(0, 3) + "-" + str.substr(3, 2);
	if (str.length() == 4) return str.substr(0, 2) + "-" + str.substr(2, 2);
	return str;
}

#define FILENAME "numbers"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string left;
		int k;
		cin >> left >> k;
		for (int j = 0; j < k; ++j) {
			string middle;
			cin >> middle;
			middles[left].insert(middle);
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		string number;
		cin >> number;
		bool is_correct = false;
		for (int left_length = 1; left_length <= 3; ++left_length) {
			string left = number.substr(0, left_length);
			auto it = middles.find(left);
			if (it == middles.end()) {
				continue;
			}
			auto &left_middles = it->second;
			for (int middle_length = 3; middle_length <= 5; ++middle_length) {
				string middle = number.substr(left_length, middle_length);
				if (left_middles.find(middle) == left_middles.end()) {
					continue;
				}
				string right = number.substr(left_length + middle_length);
				if (right[0] == '0') {
					continue;
				}
				cout << "+" << left << "(" << middle << ")" << split(right) << "\n";
				is_correct = true;
			}
		}
		if (!is_correct) {
			cout << "Incorrect\n";
		}
	}
	return 0;
}