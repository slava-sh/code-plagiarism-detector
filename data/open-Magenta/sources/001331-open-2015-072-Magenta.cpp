#include <iostream>

using namespace std;

const int W = 500;

bool check(char c) {
	cout << c << endl;
	cout.flush();
	cin >> c;
	return (c != 'N');
}

int main() {
	for (int i = 0; i < W; ++i)
		if (check('U'))
			return 0;
	if (check('R'))
		return 0;
	for (int i = 0; i < W; ++i)
		if (check('D'))
			return 0;
	for (int i = 1; i < W; ++i)
		if (check('R'))
			return 0;
	if (check('D'))
		return 0;
	for (int i = 1; i < W; ++i)
		if (check('L'))
			return 0;
	for (int i = 1; i < W; ++i)
		if (check('D'))
			return 0;
	if (check('L'))
		return 0;
	for (int i = 1; i < W; ++i)
		if (check('U'))
			return 0;
	for (int i = 0; i < W; ++i)
		if (check('L'))
			return 0;
	if (check('U'))
		return 0;
	for (int i = 0; i < W; ++i)
		if (check('R'))
			return 0;
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