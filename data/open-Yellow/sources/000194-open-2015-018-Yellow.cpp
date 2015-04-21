#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> in;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int c = 1;
	cin >> n;
	in.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> in[i];
	}
	for (int i = 1; i < n; ++i) {
		if (in[i] != in[i - 1]) c++;
	}

	int q;
	cin >> q;
	if (n == 1) {
		for (int i = 0; i < q; ++i) {
			int pos, d;
			cin >> pos >> d;
			cout << 1 << endl;
		}
		return 0;
	}

	for (int i = 0; i < q; ++i) {
		int pos, d;
		cin >> pos >> d;
		pos--;
		if (d != in[pos]) {

			if (pos == 0) {
				if (d == in[pos + 1]) {
					c--;
				}
			} else if (pos == n - 1) {
				if (d == in[pos - 1]) {
					c--;
				}
			} else {
				if (in[pos] == in[pos - 1]) {
					c++;
				}
				if (in[pos] == in[pos + 1]) {
					c++;
				}
				if (d == in[pos - 1]) {
					c--;
				}
				if (d == in[pos + 1]) {
					c--;
				}
			}

			in[pos] = d;
		}

		cout << c << endl;
		
	}

	
	return 0;
}