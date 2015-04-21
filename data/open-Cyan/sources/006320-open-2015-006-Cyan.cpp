#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <ctime>

using namespace std;

struct vt {
	double x;
	double y;

	vt(): x(0), y(0) {

	}

	vt(double x, double y): x(x), y(y) {

	}
};

const int maxn = 100010;

vector <vt> v[maxn];

void read(vt &a) {
	scanf("%lf %lf", &a.x, &a.y);
}

vt operator -(vt a, vt b) {
	a.x -= b.x;
	a.y -= b.y;

	return a;
}

double operator %(vt a, vt b) {
	return a.x * b.y - a.y * b.x;
}

int sign(double x) {
	if (x < 0) {
		return -1;
	}

	if (x > 0) {
		return 1;
	}

	return 0;
}

bool check(vt a, vt b, vt c, vt d) {
	if (sign((b - a) % (c - a)) * sign((b - a) % (d - a)) == -1 && sign((c - d) % (c - a)) * sign((c - d) % (c - b)) == -1) {
		return true;
	}

	return false;
}

bool go(int pos1, int pos2) {
	int it = 0;
	bool f1 = false;
	bool f2 = false;

	for (int i = 0; i < (int)v[pos1].size(); i++) {
		while (!(v[pos2][it].x <= v[pos1][i].x && v[pos1][i].x <= v[pos2][it + 1].x)) {
			it++;
		}

		int x = sign((v[pos2][it + 1] - v[pos2][it]) % (v[pos1][i] - v[pos2][it]));

		if (x == 1) {
			f1 = true;
		}

		if (x == -1) {
			f2 = true;
		}
	}

	if (f1 && f2) {
		printf("No\n%d %d", pos1 + 1, pos2 + 1);
		exit(0);
	}

	swap(pos1, pos2);

	it = 0;
	f1 = false;
	f2 = false;

	for (int i = 0; i < (int)v[pos1].size(); i++) {
		while (!(v[pos2][it].x <= v[pos1][i].x && v[pos1][i].x <= v[pos2][it + 1].x)) {
			it++;
		}

		int x = sign((v[pos2][it + 1] - v[pos2][it]) % (v[pos1][i] - v[pos2][it]));

		if (x == 1) {
			f1 = true;
		}

		if (x == -1) {
			f2 = true;
		}
	}

	if (f1 && f2) {
		printf("No\n%d %d", pos1 + 1, pos2 + 1);
		exit(0);
	}

	if (f1) {
		return true;
	}

	if (f2) {
		return false;
	}

	return false;
}

int mas[maxn];

int main() {
	int a, b;

	scanf("%d %d", &a, &b);

	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int sz;
		scanf("%d", &sz);
		v[i].resize(sz + 1);
		for (int j = 0; j < sz + 1; j++) {
			read(v[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		mas[i] = i;
	}

	sort(mas, mas + n, go);

	printf("Yes");

	return 0;
}
