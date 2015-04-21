#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
#define MOD 1000000007LL
#define P 5
using namespace std;



struct Point {
	ld x, y;
	int num;
	ld gety(ld xx) {
		return y / x * xx;
	}
	Point(){}
	Point(ld x, ld y):x(x), y(y){}
};
vector<Point> a[100001];
Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

ld gety(const Point &l, const Point &r, ld x) {
	return l.y + (r - l).gety(x - l.x);
}
const ld EPS = 1e-9;

ll A, B;
bool cmp(const vector<Point> &a, const vector<Point> &b) {
	bool wasa = false;
	bool wasb = false;
	int ap = 0, bp = 0;
	ld ay, by;
	while (true) {
		if (a[ap + 1].x <= b[bp + 1].x) {
			by = gety(b[bp], b[bp + 1], a[ap + 1].x);
			if (abs(by - a[ap + 1].y) > EPS) {
				if (by > a[ap + 1].y) wasb = true;
				if (a[ap + 1].y > by) wasa = true;
			}
			ap++;
		} else {
			ay = gety(a[ap], a[ap + 1], b[bp + 1].x);
			if (abs(ay - b[bp + 1].y) > EPS) {
				if (ay > b[bp + 1].y) wasa = true;
				if (b[bp + 1].y > ay) wasb = true;
			}
			bp++;
		}
		if (a[ap].x == B) break;
		if (b[bp].x == B) break;
	}
	if (wasa & wasb) {
		printf("No\n%d %d\n", a[0].num, b[0].num);
		exit(0);
	}
	return wasa;
}
int t1, t2;
int main(void) {
	scanf("%lld%lld", &A, &B);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int l;
		scanf("%d", &l);
		a[i].resize(l + 1);
		a[i][0].num = i + 1;
		for (int j = 0; j < l + 1; ++j) {
			scanf("%d%d", &t1, &t2);
			a[i][j].x = t1;
			a[i][j].y = t2;
		}
	}
	sort(a, a + n, cmp);
	printf("Yes\n");
	return 0;
}