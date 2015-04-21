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

ll divup(ll a, ll b) {
	return (a - 1LL) / b + 1LL;
}

//ll divs[(int)(1e8)];
ll dp[(int)(1e6) + 1][11];

ll calc(ll n, ll k) {
	//if (dp[n][k])
//		return dp[n][k];
	if (k == 0) {
		return divup(n, 2);
	}
	ll best = calc(n, k - 1);
	for (ll d = 2, d2; d * d <= n; ++d) {
		if (n % d == 0) {
			best = min(best, divup(n / d, 2) * calc(d, k - 1));
			d2 = n / d;
			best = min(best, divup(d, 2) * calc(d2, k - 1));
		}
	}
	//cout << n << " " << k << ": "  << best << endl;
	return best;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ll n, k;
	cin >> n >> k;
	cout << calc(n, k) << endl;
	//int csdiv = 0;
	//for (ll d = 1; d * d <= n; ++d)
}