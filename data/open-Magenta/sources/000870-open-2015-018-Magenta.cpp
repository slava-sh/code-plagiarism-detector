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
	int count = 3;
	cout << "R" << endl << endl;
	fflush(stdout);
	int h = 0;
	while (cin >> c) {
		if (c != 'N') {
			return 0;
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
			cout << "R" << endl << endl;
			break;
		case 1:
			cout << "D" << endl << endl;
			break;
		case 2:
			cout << "L" << endl << endl;
			break;
		case 3:
			cout << "U" << endl << endl;
			break;
		}
		fflush(stdout);
		h--;
	}
	//for(;;);
	return 0;
}