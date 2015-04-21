#include <iostream>

using namespace std;

struct point {
	long long x, y;
	point (long long x1 = 0, long long y1 = 0) {
		x = x1;
		y = y1;
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

bool f (long long i, long long j) {
	long long uk1 = 2, uk2 = 2;
	while (uk1 <= rz[i] && uk2 <= rz[i]) {
		if (seg(a[i][uk1 - 1], a[i][uk1]) * seg(a[j][uk2 - 1], a[j][uk2]) == 1) return 1;
		if (a[i][uk1].x < a[j][uk2].x) {
			uk1++;
			continue;
		}
		if (a[i][uk1].x > a[j][uk2].x) {
			uk2++;
			continue;
		}
		uk1++;
		uk2++;
	}
	return 0;
}

int main () {
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	long long aa, b;
	cin >> aa >> b;
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> rz[i];
		rz[i]++;
		for (long long j = 1; j <= rz[i]; j++) {
			long long x, y;
			cin >> x >> y;
			a[i][j] = point(x, y);
		}
	}
	for (long long i = 1; i <= n; i++) {
		for (long long j = i + 1; j <= n; j++) {
			if (f(i, j)) {
				cout << "No" << endl << i << " " << j;
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}