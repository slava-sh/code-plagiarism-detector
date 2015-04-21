#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <cstdio>
#include <memory.h>
#include <iostream>
#include <cmath>
#include <queue>

#pragma comment(linker, "/STACK:64000000")

using namespace std;

#define mp make_pair
#define pi M_PI

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;

const int infi = (int)1e9 + 7;
const ll infl = (ll)1e18 + 7;
const ld eps = (ld)(1e-8);
const int it = 1000000;

struct point{
	ll x, y;
	point(){}
	point(ll x, ll y) : x(x), y(y) {}
};
point operator +(point a, point b) {
	return point(a.x + b.x, a.y + b.y);
}
point operator -(point a, point b) {
	return point(a.x - b.x, a.y - b.y);
}
point operator *(point a, ld b) {
	return point(a.x / b, a.y / b);
}
point operator /(point a, ld b) {
	return point(a.x / b, a.y / b); 
}
bool operator ==(point a, point b) {
	if (fabsl(a.x - b.x) <= eps && fabsl(a.y - b.y) <= eps) {
		return 1;
	}
	return 0;
}
typedef pair<point, point> ppp;
struct line{
	ld a, b, c;
	line(){}
	line (ppp p) {
		a = p.first.y - p.second.y;
		b = p.second.x - p.first.x;
		c = -a * p.first.x - b * p.first.y;
	}
};
ll sn(point a, point b) {
	return a.x * b.y - b.x * a.y;
}
ll cs(point a, point b) {
	return a.x * b.x + a.y * b.y;
}

int check(ppp a, point b) {
	if (fabsl(sn(a.first - a.second, b - a.second)) > eps) {
		return 0;
	}
	if (cs(a.first - a.second, b - a.second) < -eps) {
		return 0;
	}
	if (cs(a.second - a.first, b - a.first) < -eps) {
		return 0;
	}
	return 1;
}
int check1(ppp a, point b) {
	if (a.first.x > a.second.x) {
		swap(a.first.x, a.second.x);
	}
	if (a.first.y > a.second.y) {
		swap(a.second.y, a.first.y);
	}
	if (a.first.x - eps <= b.x && b.x <= a.second.x + eps && a.first.y - eps <= b.y && b.y <= a.second.y + eps) {
		return 1;
	}
	return 0;
}
point per(line a, line b) {
	point ans;
	ans.x = -(a.c * b.b - a.b * b.c) / (a.a * b.b - a.b * b.a);
	ans.y = -(a.a * b.c - a.c * b.a) / (a.a * b.b - a.b * b.a);
	return ans;
}
int check(ppp a, ppp b) {
	point q = a.first - a.second, w = b.first - b.second;
	if (fabsl(sn(q, w)) <= eps) {
		return 0;
	}
	if (check(a, b.first) || check(a, b.second) || check(b, a.first) || check(b, a.second)) {
		return 0;
	}
	point c = per(line(a), line(b));
	if (check1(a, c) && check1(b, c)) {
		return 1;
	}
	return 0;
}
vector <point> ar[100500];
int gety(point b, point l, point r) {
	if (r.x == b.x) {
		if (r.y == b.y) {
			return 0;
		}
		if (b.y > r.y) {
			return 1;
		}
		return 2;
	}
	ll c = sn(b - l, r - l);
	if (c == 0) {
		return 0;
	}
	if (c > 0) {
		return 2;
	}
	return 1;
}

int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int n;
	ld a, b;
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		++m;
		ar[i].resize(m);
		for (int j =0 ; j < m; ++j) {
			cin >> ar[i][j].x >> ar[i][j].y;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int flag = 0;
			int w = 0;
			for (int q = 0; q < (int)ar[i].size(); ++q) {
				int a;
				for (; w < (int)ar[j].size() && ar[j][w].x < ar[i][q].x; ++w);
				if (w) {
					a =gety(ar[i][q], ar[j][w - 1], ar[j][w]);
				}
				else {
					a = gety(ar[i][q], ar[j][w], ar[j][w]);
				}
				if (a == 0) {
					continue;
				}
				if (a == 1) {
					if (flag) {
						if (flag == 2) {
							printf("No\n%d %d", i + 1, j + 1);
							return 0;
						}
					}
					else {
						flag = 1;
					}
				}
				else {
					if (flag) {
						if (flag == 1) {
							printf("No\n%d %d", i + 1, j + 1);
							return 0;
						}
					}
					else {
						flag = 2;
					}
				}
			}
			w = 0;
			for (int q = 0; q < (int)ar[j].size(); ++q) {
				int a;
				for (; w < (int)ar[i].size() && ar[i][w].x < ar[j][q].x; ++w);
				if (w) {
					a =gety(ar[j][q], ar[i][w - 1], ar[i][w]);
				}
				else {
					a = gety(ar[j][q], ar[i][w], ar[i][w]);
				}

				if (a == 0) {
					continue;
				}
				if (a == 1) {
					if (flag) {
						if (flag == 1) {
							printf("No\n%d %d", i + 1, j + 1);
							return 0;
						}
					}
					else {
						flag = 2;
					}
				}
				else {
					if (flag) {
						if (flag == 2) {
							printf("No\n%d %d", i + 1, j + 1);
							return 0;
						}
					}
					else {
						flag = 1;
					}
				}
			}
		}
	}
	cout << "Yes";

	return 0;
}