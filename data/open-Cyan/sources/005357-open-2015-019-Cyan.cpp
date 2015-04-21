#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

struct point {
	long long x, y;
	point (long long x1 = 0, long long y1 = 0) {
		x = x1;
		y = y1;
	}
	long long operator * (point p) {
		if (p.x * y - p.y * x > 0) return 1;
		if (p.x * y - p.y * x < 0) return -1;
		if (p.x * y - p.y * x == 0) return 0;
	}
	point operator - (point p) {
		return point(x - p.x, y - p.y);
	}
};

struct line {
	long long a, b, c;
	line (long long a1 = 0, long long b1 = 0, long long c1 = 0) {
		a = a1;
		b = b1;
		c = c1;
	}
	line (point p, point q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = -(a * p.x + b * p.y);
	}
	long long zn (point p) {
		return a * p.x + b * p.y + c;
	}
	long long zzn (point p) {
		long long qwe = zn(p);
		if (qwe > 0) return 1;
		if (qwe < 0) return -1;
		if (qwe == 0) return 0;
	}
};

struct seg {
	point p, q;
	seg (point p1, point q1) {
		p = p1;
		q = q1;
	}
	bool operator * (seg qwe) {
		if (line(p, q).zzn(qwe.p) * line(p, q).zzn(qwe.q) < 0 && line(qwe.p, qwe.q).zzn(p) * line(qwe.p, qwe.q).zzn(q) < 0) {
			return 1;
		}
		return 0;
	}
};

point a[410][410];
long long rz[410];

bool q (point a1, point a2, point b1, point b2, point o) {
	if (((a1 - o) * (b1 - o)) * ((a2 - o) * (b2 - o)) > 0) return 1;
	return 0;
}

bool f (long long i, long long j) {
	long long uk1 = 2, uk2 = 2;
	long long ans = 0;
	if (a[i][1].y > a[j][1].y) ans = 1;
	if (a[i][1].y < a[j][1].y) ans = -1;
	while (uk1 <= rz[i] && uk2 <= rz[j]) {
		long long ans1 = 0;
		if (a[i][uk1].x == a[j][uk2].x) {
			if (a[i][uk1].y > a[j][uk2].y) ans1 = 1;
			if (a[i][uk1].y < a[j][uk2].y) ans1 = -1;
			if (a[i][uk1].y == a[j][uk2].y) ans1 = 0;
			if (ans * ans1 < 0) return 1;
			if (ans == 0) ans = ans1;
			uk1++;
			uk2++;
			continue;
		}
		if (a[i][uk1].x < a[j][uk2].x) {
			if (seg(a[i][uk1], point(a[i][uk1].x, -1000000001)) * seg(a[j][uk2 - 1], a[j][uk2])) ans1 = 1;
			else ans1 = -1;
			if (line(a[j][uk2 - 1], a[j][uk2]).zzn(a[i][uk1]) == 0) ans1 = 0;
			if (ans * ans1 < 0) return 1;
			if (ans == 0) ans = ans1;
			uk1++;
			continue;
		} else {
			if (seg(a[j][uk2], point(a[j][uk2].x, -1000000001)) * seg(a[i][uk1 - 1], a[i][uk1])) ans1 = -1;
			else ans1 = 1;
			if (line(a[i][uk1 - 1], a[i][uk1]).zzn(a[j][uk2]) == 0) ans1 = 0;
			if (ans * ans1 < 0) return 1;
			if (ans == 0) ans = ans1;
			uk2++;
			continue;
		}
	}
	return 0;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	long long aa, b;
	//cin >> aa >> b;
	scanf("%lld%lld", &aa, &b);
	long long n;
	//cin >> n;
	scanf("%lld", &n);
	for (long long i = 1; i <= n; i++) {
		cin >> rz[i];
		rz[i]++;
		for (long long j = 1; j <= rz[i]; j++) {
			long long x, y;
			//cin >> x >> y;
			scanf("%lld%lld", &x, &y);
			a[i][j] = point(x, y);
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 1; j <= n; j++) {
			if (f(i, j)) {
				//cout << "No" << endl << i << " " << j;
				printf("No\n%lld %lld", i, j);
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
}