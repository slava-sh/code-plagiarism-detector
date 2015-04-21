#include <iostream>

using namespace std;

int main () {
	for (int i = 1; i <= 300; i++) {
		for (int j = 1; j <= 300; j++) {
			cout << "L" << endl;
			cout.flush();
			char ch;
			cin >> ch;
			if (ch == 'Y') return 0;
		}
		cout << "U" << endl;
		cout.flush();
		char ch;
		cin >> ch;
		if (ch == 'Y') return 0;
	}
}