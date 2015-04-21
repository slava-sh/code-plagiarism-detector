#include <iostream>
#include <vector>
#include <fstream>
#include <set>
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

const int MaxN = 3000;
ll dp[MaxN + 2][MaxN + 2];

int main() {
	freopen("input.txt", "r", stdin);
	int n, k;
	ll C, D;
	cin >> n >> k >> C >> D;
	vector <int> a(n),
		b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	C = C / (ld)k;
	k = 1;
	memset(dp, 57, sizeof(dp));
	dp[0][1] = (b[0] - a[0]) * D;
	for (int i = 1; i < n; ++i) {
		for (int k1 = 1; k1 <= k; ++k1) {
			int k2 = k1 - 1;
			ll add = 0;
			if (k2 == 0) {
				k2 = k;
				add = C;
			}
			dp[i][k1] = min(
				dp[i - 1][k1] + D * (b[i] - b[i - 1]),
				dp[i - 1][k2] + add + D * (b[i] - a[i])
				);
		}
	}
	ll ans = dp[n - 1][0];
	for (int k1 = 0; k1 <= k; ++k1)
		ans = min(ans, dp[n - 1][k1]);
	cout << ans << endl;
}