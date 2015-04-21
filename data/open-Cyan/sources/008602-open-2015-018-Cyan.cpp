#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

const double EPS = 1e-8;
const long double INF = 1e9 + 1;

struct Line {
	long double a, b, c;
	Line (long double _a, long double _b, long double _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	Line (long double x1, long double y1, long double x2, long double y2) {
		a = y1 - y2;
		b = x2 - x1;
		c = x1 * y2 - x2 * y1;
	}
};

vector<vector<int> > up;
vector<int> uc;
vector<vector<Line> > lines;
vector<vector<long double> > dots;
vector<pair<long double, pair<int, int> > > actions; 

long long a, b;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> a >> b;

	int c;
	cin >> c;
	lines.resize(c);
	dots.resize(c);
	uc.resize(c, -1);
	up.resize(c);
	for (int i = 0; i < c; ++i) {
		up[i].resize(c, 0);
		int k;
		cin >> k;
		int x1, y1, x2, y2;
		cin >> x1 >> y1;
		actions.push_back(make_pair(x1, make_pair(i, 0)));
		for (int j = 0; j < k - 1; ++j) {
			cin >> x2 >> y2;
			actions.push_back(make_pair(x2, make_pair(i, 1)));
			lines[i].push_back(Line(x1, y1, x2, y2));
			x1 = x2;
			y1 = y2;
		}
		cin >> x2 >> y2;
		actions.push_back(make_pair(x2, make_pair(i, 2)));
		lines[i].push_back(Line(x1, y1, x2, y2));
	}

	sort(actions.begin(), actions.end());

	vector<long double> curr(c);

	for (int i = 0; i < (int)actions.size(); ++i) {
		int ind = actions[i].second.first;
		int x = actions[i].first;
		
		switch(actions[i].second.second) {
		case 0:
			uc[ind] = 0;
			break;
		case 1:
			uc[ind]++;
			break;
		case 2:
			uc[ind] = -1;
			break;
		}
		
		vector<long double> newC(c);
		for (int j = 0; j < c; ++j) {
			if (uc[j] != -1) {
				newC[j] = (-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b;
			}
		}

		for (int i1 = 0; i1 < (int) c; ++i1) {
			for (int i2 = i1 + 1; i2 < (int) c; ++i2) {
				if (uc[i1] != -1 && uc[i2] != -1) {
					if (up[i1][i2] == 0) {
						if (newC[i1] > newC[i2]) {
							up[i1][i2] = 1;
							up[i2][i1] = -1;
						} else if (newC[i1] < newC[i2]) {
							up[i1][i2] = -1;
							up[i2][i1] = 1;
						}
					} else {
						if ((up[i1][i2] > 0 && newC[i1] < newC[i2]) ||
							(up[i1][i2] < 0 && newC[i1] > newC[i2])) {

							cout << "No" << endl;
							cout << i1 + 1 << " " << i2 + 1 << endl;
							return 0;
						}
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}