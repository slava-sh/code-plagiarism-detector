#pragma comment(linker, "/STACK:16777216")

#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

const double EPS = 1e-9;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//#define FILE_NAME ""
	//	freopen(FILE_NAME ".in", "r", stdin);
	//	freopen(FILE_NAME ".out", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	vector<vector<pair<double, double> > > A(n);
	vector<pair<pair<double, double>, int> > B(n);
	for (int i = 0; i < n; ++i) {
		int l;
		cin >> l;
		A[i].resize(l + 1);
		for (int j = 0; j < l + 1; ++j)
			cin >> A[i][j].first >> A[i][j].second;
		B[i] = make_pair(make_pair(A[i][0].second, atan2(A[i][1].second - A[i][0].second, A[i][1].first - A[i][0].first)), i);
	}
	stable_sort(B.begin(), B.end());
	for (int i = 1; i < n; ++i) {
		int i1 = B[i - 1].second;
		int i2 = B[i].second;
		int p1 = 1;
		int p2 = 1;
		while (true) {
			//cout << i1 << " " << p1 << endl;
			//cout << i2 << " " << p2 << endl;
			//cout << A[i1].size() << " " << A[i2].size() << endl;
			if (A[i1][p1].first < A[i2][p2].first) {
				//cout << "A\n";
				double len2 = A[i2][p2].first - A[i2][p2 - 1].first;
				double len3 = A[i1][p1].first - A[i2][p2 - 1].first;
				double y = A[i2][p2 - 1].second + (len3 / len2) * (A[i2][p2].second - A[i2][p2 - 1].second);
				if (y + EPS < A[i1][p1].second) {
					cout << "No\n";
					cout << i1 + 1 << " " << i2 + 1 << "\n";
					return 0;
				}
				++p1;
			} else {
				//cout << "B\n";
				double len2 = A[i1][p1].first - A[i1][p1 - 1].first;
				double len3 = A[i2][p2].first - A[i1][p1 - 1].first;
				double y = A[i1][p1 - 1].second + (len3 / len2) * (A[i1][p1].second - A[i1][p1 - 1].second);
				//cout << y << endl;
				if (y > A[i2][p2].second + EPS) {
					cout << "No\n";
					cout << i1 + 1 << " " << i2 + 1 << "\n";
					return 0;
				}
				++p2;
			}
			if (p1 >= A[i1].size() || p2 >= A[i2].size())
				break;
		}
	}
	cout << "Yes\n";

	return 0;
}