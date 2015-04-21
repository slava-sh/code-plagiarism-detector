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

ll divup(ll a, ll b) {
	return (a - 1LL) / b + 1LL;
}

map <ll, ll> dp[11];

ll calc(ll n, ll k) {
	if (dp[k].find(n) != dp[k].end())
		return dp[k][n];
	/*if (k == 0) {
		return divup(n, 2);
	}*/
	if (k == 1)
		return dp[k][n] = divup(n, 2);
	ll best = 1LL << 62LL;
	for (ll d = 1, d2; d * d <= n; ++d) {
		if (n % d == 0) {
			ll c1 = calc(d, k - 1);
			ll c2 = calc(n / d, k - 1);
			ll r1 = divup(n / d, 2) * c1;
			ll r2 = divup(d, 2) * c2;
			if (r1 < best) {
				//if (n == 357210000)
					//cout << n << " " << d << endl;
				best = r1;
			}
			if (r2 < best) {
				//if (n == 357210000)
				//	cout << n << " " << n / d << endl;
				best = r2;
			}
		}
	}
	//cout << n << " " << k << ": "  << best << endl;
	return dp[k][n] = best;
}


ll calc2(ll n, ll k) {
	/*if (k == 0) {
		return divup(n, 2);
	}*/
	if (k == 1)
		return divup(n, 2);
	ll best = INF;
	for (ll d = 2, d2; d * d <= n; ++d) {
		if (n % d == 0) {
			ll r1 = divup(n / d, 2) * calc2(d, k - 1);
			ll r2 = divup(d, 2) * calc2(n / d, k - 1);
			bool f = 0;
			if (r1 < best) {
				best = r1;
				f = 1;
			}
			if (r2 < best) {
				best = r2;
				f = 1;
			}
			if (!f)
				break;
		}
	}
	if (best == INF)
		best = min(divup(n, 2), calc(n, k - 1));
	//cout << n << " " << k << ": "  << best << endl;
	return best;
}

ll calc3(ll n, ll k) {
	if (dp[k].find(n) != dp[k].end())
		return dp[k][n];
	/*if (k == 0) {
		return divup(n, 2);
	}*/
	if (k == 1)
		return dp[k][n] = divup(n, 2);
	ll best = 1LL << 62LL;
	for (ll d = 1, d2; d * d <= n; ++d) {
		if (n % d == 0) {
			//ll c1 = calc(d, k - 1);
			ll c2 = calc(n / d, k - 1);
			//ll r1 = divup(n / d, 2) * c1;
			ll r2 = divup(d, 2) * c2;
			bool f = 0;
			//cout << n << " " << d << " " << r1 << " " << r2 << endl;
			/*if (r1 < best) {
				//if (n == 357210000)
					//cout << n << " " << d << endl;
				best = r1;
				f = 1;
			}*/
			if (r2 < best) {
				//if (n == 357210000)
				//	cout << n << " " << n / d << endl;
				best = r2;
				f = 1;
			}
			if (!f) {
					break;
			}
		}
	}
	//cout << n << " " << k << ": "  << best << endl;
	return dp[k][n] = best;
}


ll calc4(ll n, ll k) {
	/*if (k == 0) {
		return divup(n, 2);
	}*/
	if (k == 1)
		return divup(n, 2);
	ll best = 1LL << 62LL;
	for (ll d = 1, d2; d * d <= n; ++d) {
		if (n % d == 0) {
			//ll r1 = divup(n / d, 2) * calc2(d, k - 1);
			ll r2 = divup(d, 2) * calc2(n / d, k - 1);
			bool f = 0;
			/*if (r1 < best) {
				best = r1;
				f = 1;
			}*/
			if (r2 < best) {
				best = r2;
				f = 1;
			}
			if (!f)
				break;
		}
	}
	//cout << n << " " << k << ": "  << best << endl;
	return best;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ll n, k;
	cin >> n >> k;
	//cout << calc(n, k) << endl;
	cout << calc2(n, k) << endl;
	//cout << calc3(n, k) << endl;
	//cout << calc4(n, k) << endl;
	//int csdiv = 0;
	//for (ll d = 1; d * d <= n; ++d)
}