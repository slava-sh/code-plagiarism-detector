#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct point {
	long long x, y;
};

struct seg {
	int num;
	point a, b;
};

struct vec {
	long long x, y;
	vec(seg s): x(s.b.x - s.a.x), y(s.b.y - s.a.y) {}
	vec(point a, point b): x(b.x - a.x), y(b.y - a.y) {}
};

const int MAXN = 100000;
int n;
set <seg> sit;
set <pair <long long, seg> > st, fn;

bool operator < (pair <long long, seg> a, pair <long long, seg> b) {
	return a.first < b.first || (a.first == b.first && a.second.num < b.second.num);
}

long long mul(vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

long long mul2(vec a, vec b) {
	return a.x * b.x + a.y * b.y;
}

int zn(long long x) {
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}

bool con(seg s, point p) {
	long long m = mul(vec(s), vec(s.a, p));
	long long m2 = mul2(vec(p, s.a), vec(p, s.b));
	return (m == 0 && m2 <= 0);
}

bool operator < (seg a, seg b) {
	/*cout << endl;
	cout << a.a.x << ' ' << a.a.y << ' ' << a.b.x << ' ' << a.b.y << endl;
	cout << b.a.x << ' ' << b.a.y << ' ' << b.b.x << ' ' << b.b.y << endl;
	cout << endl;*/
	bool f1 = con(a, b.a) || con(a, b.b) || con(b, a.a) || con(b, a.b);
	bool f2 = zn(mul(vec(a), vec(a.a, b.a))) * zn(mul(vec(a), vec(a.a, b.b))) <= 0;
	bool f3 = zn(mul(vec(b), vec(b.a, a.a))) * zn(mul(vec(b), vec(b.a, a.b))) <= 0;
	bool f4 = min(b.a.x, b.b.x) <= max(a.a.x, a.b.x);
	bool f5 = max(b.a.x, b.b.x) >= min(a.a.x, a.b.x);
	bool f6 = min(b.a.y, b.b.y) <= max(a.a.y, a.b.y);
	bool f7 = max(b.a.y, b.b.y) >= min(a.a.y, a.b.y);
	if (!f1 && f2 && f3 && f4 && f5 && f6 && f7) {
		cout << "No" << endl;
		cout << a.num << ' ' << b.num << endl;
		cin >> n;
		exit(0);
	}
	long long m = mul(vec(a), vec(a.a, b.b));
	if (m > 0)
		return true;
	if (m < 0)
		return false;
	m = mul(vec(a), vec(a.a, b.a));
	if (m > 0)
		return true;
	if (m < 0)
		return false;
	return a.num < b.num;
}

int main() {
	cin >> n >> n >> n;
	for (int i = 0; i < n; ++i) {
		int l, x, y;
		cin >> l >> x >> y;
		for (int j = 0; j < l; ++j) {
			seg s;
			s.num = i + 1;
			s.a.x = x, s.a.y = y;
			cin >> x >> y;
			s.b.x = x, s.b.y = y;
			st.insert(make_pair(s.a.x, s));
			fn.insert(make_pair(s.b.x, s));
		}
	}
	while (st.size() > 0) {
		long long lx = st.begin()->first;
		if (fn.size() > 0)
			lx = min(lx, fn.begin()->first);
		while (fn.size() > 0 && fn.begin()->first == lx) {
			sit.erase(fn.begin()->second);
			fn.erase(fn.begin());
		}
		while (st.size() > 0 && st.begin()->first == lx) {
			sit.insert(st.begin()->second);
			st.erase(st.begin());
		}
	}
	cout << "Yes" << endl;
	cin >> n;
	return 0;
}