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

char d[] = {'L', 'D', 'U', 'R'};

int main () {
	srand(113);
	while (1) {
		char ch = d[rand() % 4];
		if (ct(ch)) return 0;
	}
}