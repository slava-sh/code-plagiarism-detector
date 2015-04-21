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

const int maxn = 410;

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

	for (int i = 0; i < (int)v[pos1].size() - 1; i++) {
		while (it + 1 < (int)v[pos2].size() && v[pos2][it + 1].x < v[pos1][i].x) {
			it++;
		}

		if (it + 1 == (int)v[pos2].size()) {
			break;
		}

		while (it + 1 < (int)v[pos2].size() && v[pos2][it + 1].x <= v[pos1][i + 1].x) {
			if (check(v[pos1][i], v[pos1][i + 1], v[pos2][it], v[pos2][it + 1])) {
				return true;
			}
			it++;
		}

		if (it + 1 == (int)v[pos2].size()) {
			break;
		}

		if (check(v[pos1][i], v[pos2][i + 1], v[pos2][it], v[pos2][it + 1])) {
			return true;
		}
	}

	return false;
}

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
		for (int j = i + 1; j < n; j++) {
			if (go(i, j)) {
				printf("No\n%d %d", i + 1, j + 1);
				return 0;
			}
		}
	}

	printf("Yes\n");

	return 0;
}
