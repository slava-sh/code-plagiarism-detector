#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

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


int main() {
	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	vector <int> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	int Q;
	cin >> Q;
	int ans = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] != arr[i - 1])
			ans++;
	}
	for (int _i = 0; _i < Q; ++_i) {
		int p, c;
		cin >> p >> c;
		--p;
		int q1 = 0,
			q2 = 0;
		if (p > 0) {
			q1 += arr[p - 1] != arr[p];
			q2 += arr[p - 1] != c;
		}
		if (p < n - 1) {
			q1 += arr[p + 1] != arr[p];
			q2 += arr[p + 1] != c;
		}
		arr[p] = c;
		ans += q2 - q1;
		cout << ans << endl;
	}
}