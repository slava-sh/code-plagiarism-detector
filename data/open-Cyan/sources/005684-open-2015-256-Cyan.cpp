#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <map>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

const ll INF = 1LL << 62LL;

struct Point {
	ld x, y;
	Point(ld=0, ld=0);
	Point operator-(const Point &) const;
	ld len() const;
};

Point::Point(ld x, ld y): x(x), y(y)
{}

Point Point::operator-(const Point &p) const {
	return Point(x - p.x, y - p.y);
}

ld Point::len() const {
	return sqrt(x*x + y*y);
}

//const int S = 6100;

void togo(char c) {
	cout << c << endl;
	cin >> c;
	if (c != 'N')
		exit(0);
}


void Left() {
	togo('L');
}

void Down() {
	togo('D');
}

void Up() {
	togo('U');
}

int n;

int main() {
	freopen("input.txt", "r", stdin);
	int A, B;
	cin >> A >> B;
	vector<int> Xes;
	cin >> n;
	vector <vector <int> > chainX(n), chainY(n);
	for (int i = 0, Len; i < n; ++i) {
		cin >> Len;
		chainX[i].resize(Len + 1);
		chainY[i].resize(Len + 1);
		for (int j = 0; j < Len + 1; ++j) {
			cin >> chainX[i][j];
			cin >> chainY[i][j];
			Xes.push_back(chainX[i][j]);
		}
	}
	sort(Xes.begin(), Xes.end());
	Xes.resize(unique(Xes.begin(), Xes.end()) - Xes.begin());
	vector <ld> curY(n);
	vector <int> curInd(n, 1);
	for (int i = 0; i < n; ++i)
		curY[i] = chainY[i][0];
	cout << fixed;
	cout.precision(10);
	int m = Xes.size();
	vector <vector <ld> > YatX(m);
	YatX[0] = curY;
	for (int i = 0; i < m - 1; ++i) {
		int x1 = Xes[i];
		int x2 = Xes[i + 1];
		vector <ld> nextY(n);
		for (int j = 0; j < n; ++j) {
			ld y3 = chainY[j][curInd[j]];
			ld x3 = chainX[j][curInd[j]];
			nextY[j] = (x2 - x1) * (y3 - curY[j]) / (ld)(x3 - x1) + (ld)curY[j];
			if (chainX[j][curInd[j]] == x2)
				curInd[j]++;
		}
		YatX[i + 1] = nextY;
		//for (int j = 0; j < n; ++j)
//			cout << nextY[j] << " ";
		//cout << endl;
		/*for (int j = 0; j < n; ++j) {
			for (int g = 0; g < n; ++g) {
				if (curY[g] > curY[j] && nextY[g] < nextY[j]) {
					cout << "No" << endl;
					cout << j + 1 << " " << g + 1 << endl;
					return 0;
				}
			}
		}*/
		curY = nextY;
	}
	/*
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << YatX[i][j] << " ";
		cout << endl;
	}*/
	for (int i = 0; i < m; ++i) {
		for (int j = i + 1; j < m; ++j) {
			for (int l1 = 0; l1 < n; ++l1) {
				for (int l2 = 0; l2 < n; ++l2) {
					if (YatX[i][l1] > YatX[i][l2] && YatX[j][l1] < YatX[j][l2]) {
						cout << "No" << endl;
						cout << l1 + 1 << " " << l2 + 1 << endl;
						return 0;	
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
 }