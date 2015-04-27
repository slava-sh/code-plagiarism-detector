#include <functional>
#include <algorithm>
#include <stdio.h>
#include <memory.h>
#include <set>

struct point {
	int x, y;

	inline bool operator < (const point &a) const {
		if (x != a.x) return x < a.x;
		return y < a.y;
	}
	inline bool operator > (const point &a) const {
		if (x != a.x) return x > a.x;
		return y > a.y;
	}
};

int n;
point data[10010];

int x[10010], y[10010];

int m;
point answer[200010];
std::set<point> check;

inline void answer_insert(int x, int y)
{
	point insert = {x, y};
	if (check.find(insert) == check.end()) {
		answer[m++] = insert;
		check.insert(insert);
	}
}

void solve(point *data, int n)
{
	if (n==1) {
		answer_insert(data[0].x, data[0].y);
		return;
	}

	int linex = data[n/2-1].x;
	solve(data, n/2);
	solve(data+n/2, n - n/2);

	int i;
	for (i=0; i<n; i++)
		answer_insert(linex, data[i].y);
}

int main()
{
	int i;

	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d %d", &data[i].x, &data[i].y);
		x[i] = data[i].x;
		y[i] = data[i].y;
	}
	std::sort(x, x+n);
	std::sort(y, y+n);

	for (i=0; i<n; i++) {
		int start=0, end=n-1, mid;
		while (start<=end) {
			mid = (start+end)/2;
			if (data[i].x == x[mid]) {data[i].x = mid; break;}
			if (data[i].x < x[mid]) end = mid-1;
			else start = mid+1;
		}
		start=0, end=n-1;
		while (start<=end) {
			mid = (start+end)/2;
			if (data[i].y == y[mid]) {data[i].y = mid; break;}
			if (data[i].y < y[mid]) end = mid-1;
			else start = mid+1;
		}
	}

	std::sort(data, data+n);
	solve(data, n);

	printf("%d\n", m);
	for (i=0; i<m; i++)
		printf("%d %d\n", x[answer[i].x], y[answer[i].y]);

	return 0;
}
