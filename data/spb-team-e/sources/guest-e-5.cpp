#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	freopen("game.in", "rt", stdin);
	freopen("game.out", "wt", stdout);

	string first = "Petya", second = "Vasya";
	int n, m;
	cin >> n >> m;
	
	int lf, rf, ls, rs;
	cin >> lf >> rf;
	cin >> ls >> rs;

	int lb = max(lf, ls);
	int rb = min(rf, rs);

	int f = 0, s = 0, both = 0;
	for (int i = 0; i < n; ++i) {
		int h;
		cin >> h;
		if (h >= lb && h <= rb) {
			both += 1;
		} else {
			if (h >= lf && h <= rf) {
				f += 1;
			}
			if (h >= ls && h <= rs) {
				s += 1;
			}
		}
	}

	both = min(both, m);

	int scoref = both % 2;
	int scores = 0;

	m -= both;

	if (both % 2 == 1) {
		swap(f, s);
		swap(first, second);
		swap(scoref, scores);
	}

	scoref += min((m / 2) + (m % 2), f);
	scores += min((m / 2), s);

	if (scoref == scores) {
		cout << "Draw" << endl;
	} else if (scoref > scores) {
		cout << first << endl;
	} else {
		cout << second << endl;
	}

	return 0;
}