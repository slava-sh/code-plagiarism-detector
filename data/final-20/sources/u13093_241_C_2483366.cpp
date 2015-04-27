
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define EPS 1e-8

using namespace std;

int hl, hr, n;
const int H = 100;
const int W = 100000;
vector <vector <int> > top, bot;
bool topHit[100], botHit[100];
int bestScore = 0;

int calc(double cotA) {
	for (int i = 0; i < n; i++)
		topHit[i] = botHit[i] = false;

	double x = hl * cotA;
	bool onTop = false;
	int score = 0;
	while (x <= W) {
		bool hasHit = false;
		if (onTop) {
			for (int i = 0; i < top.size(); i++)
				if (x >= top[i][0] && x <= top[i][1]) {
					if (topHit[i])
						return 0;
					score += top[i][2];
					topHit[i] = true;
					hasHit = true;
					break;
				}
		}
		else {
			for (int i = 0; i < bot.size(); i++)
				if (x >= bot[i][0] && x <= bot[i][1]) {
					if (botHit[i])
						return 0;
					score += bot[i][2];
					botHit[i] = true;
					hasHit = true;
					break;
				}
		}

		if (!hasHit)
			return 0;
		x += H * cotA;
		onTop = !onTop;
	}
	return score;
}

void solve() {
	for (int i = 1; i <= n; i++) {
		int den = hl + (i - 1) * H;
		if (i % 2 == 1)
			den += hr;
		else
			den += H - hr;

		int score = calc(1.0 * W / den);
		if (score > bestScore)
			bestScore = score;
	}
}

int main() {
	cin >> hl >> hr >> n;
	for (int i = 0; i < n; i++) {
		string s;
		vector <int> a(3);
		cin >> a[2] >> s >> a[0] >> a[1];
		if (s[0] == 'T')
			top.push_back(a);
		else
			bot.push_back(a);
	}

	solve();
	swap(top, bot);
	hl = H - hl, hr = H - hr;
	solve();
	cout << bestScore << endl;
}
