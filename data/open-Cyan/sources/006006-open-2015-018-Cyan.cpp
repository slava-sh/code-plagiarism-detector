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


vector<int> uc;
vector<long double> prevPos;
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
	prevPos.resize(c, INF);
	for (int i = 0; i < c; ++i) {
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

	
	vector<pair<long double, int> > curr;

	for (int i = 0; i < (int)actions.size(); ++i) {
		int ind = actions[i].second.first;
		int x = actions[i].first;
		vector<pair<long double, int> > newC;
		for (int j = 0; j < c; ++j) {
			if (uc[j] != -1) {
				newC.push_back(make_pair((-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b, j));
			}
		}

		sort(newC.begin(), newC.end());
		for (int k = 0; k < (int) curr.size(); ++k) {
			if (curr[k].second != newC[k].second && prevPos[curr[k].second] != prevPos[newC[k].second]) {
				cout << "No" << endl;
				cout << curr[k].second + 1 << " " << newC[k].second + 1 << endl;
				return 0;
			}
		}
		
		switch(actions[i].second.second) {
		case 0:
			uc[ind] = 0;

			curr.clear();
			for (int j = 0; j < c; ++j) {
				if (uc[j] != -1) {
					prevPos[j] = (-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b;
					curr.push_back(make_pair((-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b, j));
				}
			}
			sort(curr.begin(), curr.end());
			break;
		case 1:
			uc[ind]++;
			break;
		case 2:
			uc[ind] = -1;
			prevPos[ind] = INF;

			curr.clear();
			for (int j = 0; j < c; ++j) {
				if (uc[j] != -1) {
					prevPos[j] = (-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b;
					curr.push_back(make_pair((-lines[j][uc[j]].a * x - lines[j][uc[j]].c) / lines[j][uc[j]].b, j));
				}
			}
			sort(curr.begin(), curr.end());
			break;
		}
	}
	cout << "Yes" << endl;
	return 0;
}