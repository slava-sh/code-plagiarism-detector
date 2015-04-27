#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <memory.h>
#include <cstdio>
using namespace std;

int n;
struct Point
{
	int x, y;
	bool operator < (const Point& p) const
	{
		if (x != p.x)
			return x < p.x;
		return y < p.y;
	}
	bool operator != (const Point& p) const
	{
		return x != p.x || y != p.y;
	}

	Point(int x = 0, int y = 0)
	{
		this->x = x;
		this->y = y;
	}
};

Point a[10010];
vector<Point> res;

void solve(int l, int r)
{
	if (l == r)
		return;
	int m = (l + r) / 2;
	int x = a[m].x;
	for (int i = l; i <= r; ++i)
	{
		res.push_back(Point(x, a[i].y));
	}
	solve(l, m);
	solve(m + 1, r);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d %d", &a[i].x, &a[i].y);

	sort(a, a + n);
	for (int i = 0; i < n; ++i)
		res.push_back(a[i]);
	solve(0, n - 1);
	
	sort(res.begin(), res.end());
	vector<Point> nres;
	nres.push_back(res[0]);
	for (int i = 1; i < res.size(); ++i)
		if (res[i] != res[i - 1])
			nres.push_back(res[i]);

	printf("%d\n", nres.size());
	for (int i = 0; i < nres.size(); ++i)
		printf("%d %d\n", nres[i].x, nres[i].y);



	return 0;
}