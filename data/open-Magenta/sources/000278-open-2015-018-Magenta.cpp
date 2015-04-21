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
	int st = -1;
	int count = 2;
	int h = 0;
	while (cin >> c) {
		if (c == 'Y' || c == 'E') {
			cout.flush();
			break;
		}
		if (h == 0) {
			st++;
			if (st > 3) {
				st = 0;
			}
			h = count / 2;
			count++;
		}
		switch(st) {
		case 0:
			cout << "R" << endl;
			break;
		case 1:
			cout << "U" << endl;
			break;
		case 2:
			cout << "L" << endl;
			break;
		case 3:
			cout << "D" << endl;
			break;
		}
		cout.flush();
		h--;
	}
	return 0;
}