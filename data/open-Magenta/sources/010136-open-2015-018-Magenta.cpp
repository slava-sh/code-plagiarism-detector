#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	char c;
	int st = 0;
	int count = 1;
	cout << "R" << endl << endl;
	fflush(stdout);
	int h = 0;
	while (cin >> c) {
		if (c != 'N') {
			return 0;
		}
		if (count & 1) {
			cout << 'U' << endl << endl;
			fflush(stdout);
			for (int i = 0; i < count - 1; ++i) { 
				cin >> c;
				if (c != 'N') {
					return 0;
				}
				cout << 'U' << endl << endl;
				fflush(stdout);
			}
			for (int i = 0; i < count; ++i) {
				cin >> c;
				if (c != 'N') {
					return 0;
				}
				cout << 'L' << endl << endl;
				fflush(stdout);
			}
			cin >> c;
			if (c != 'N') {
				return 0;
			}
			cout << 'U' << endl << endl;
			fflush(stdout);
		} else {
			cout << 'R' << endl << endl;
			fflush(stdout);
			for (int i = 0; i < count - 1; ++i) { 
				cin >> c;
				if (c != 'N') {
					return 0;
				}
				cout << 'R' << endl << endl;
				fflush(stdout);
			}
			for (int i = 0; i < count; ++i) {
				cin >> c;
				if (c != 'N') {
					return 0;
				}
				cout << 'D' << endl << endl;
				fflush(stdout);
			}
			cin >> c;
			if (c != 'N') {
				return 0;
			}
			cout << 'R' << endl << endl;
			fflush(stdout);
		}
		count++;
	}
	return 0;
}