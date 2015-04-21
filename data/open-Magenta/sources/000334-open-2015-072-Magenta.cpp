#include <iostream>

using namespace std;

int main() {
	char c = 'R', ans = 'N';
	bool lst = false;
	int n = 1, cur = 0;
	while (ans == 'N') {
		cout << c << endl;
		cout.flush();
		++cur;
		if (cur == n) {
			cur = 0;
			n += lst;
			lst = !lst;
			c = (c == 'R') * 'U' + (c == 'U') * 'L' + (c == 'L') * 'D' + (c == 'D') * 'R';		
		}
		cin >> ans;
	}
	return 0;
}