#include <iostream>

using namespace std;

bool ct (char ch) {
	cout << ch << endl;
	cout.flush();
	char qwe;
	cin >> qwe;
	if (qwe == 'Y' || qwe == 'E') return 1;
	return 0;
}

int main () {
	int dl = 1, dr = 2, du = 1, dd = 2;
	while (1) {
		for (int i = 1; i <= dl; i++) {
			if (ct('L')) return 0;
		}
		for (int i = 1; i <= du; i++) {
			if (ct('U')) return 0;
		}
		for (int i = 1; i <= dr; i++) {
			if (ct('R')) return 0;
		}
		for (int i = 1; i <= dd; i++) {
			if (ct('D')) return 0;
		}
		dl += 2;
		dr += 2;
		du += 2;
		dd += 2;
	}
}