#include <iostream>

using namespace std;

int main() {
	bool dir = true;
	int n = 1, x = 1, y = 1;
	char ans = 'N';
	while (ans == 'N') {
		if (dir)
			if (x == n && y == 1) {
				cout << 'R' << endl;
				cout.flush();
				dir = false;
				++x, ++n;
			} else
				if (x < n) {
					cout << 'R' << endl;
					cout.flush();
					++x;
				} else {
					cout << 'D' << endl;
					cout.flush();
					--y;
				}
		else
			if (x == 1 && y == n) {
				cout << 'U' << endl;
				cout.flush();
				dir = true;
				++y, ++n;
			} else
				if (y < n) {
					cout << 'U' << endl;
					cout.flush();
					++y;
				} else {
					cout << 'L' << endl;
					cout.flush();
					--x;
				}
		cin >> ans;
	}
	return 0;
}