#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 411;

struct Point
{
	ll x, y;
	Point(){}
	Point(ll x, ll y) : x(x), y(y){}
};

struct Line
{
	Point p1, p2;
	ll a, b, c;
	Line(){}
	Line(Point p1, Point p2) : p1(p1), p2(p2)
	{
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = -(a * p1.x + b * p1.y);
	}
};

struct Segment
{
	Point p1, p2;
	Segment(){}
	Segment(Point p1, Point p2) : p1(p1), p2(p2){}
};

int A, B, n;

int l[MAX];

Point p[MAX][MAX];

bool isContained(Segment s1, Segment s2, Point p)
{
	ll minx = min(min(s1.p1.x, s2.p1.x), min(s1.p2.x, s2.p2.x));
	ll maxx = max(max(s1.p1.x, s2.p1.x), max(s1.p2.x, s2.p2.x));
	ll miny = min(min(s1.p1.y, s2.p1.y), min(s1.p2.y, s2.p2.y));
	ll maxy = max(max(s1.p1.y, s2.p1.y), max(s1.p2.y, s2.p2.y));
	/*if((p.x == minx && p.x == A) || (p.x == maxx && p.x == B))
		return false;*/
	if((p.x > minx && p.x < maxx) || (p.y > miny && p.y < maxy))
		return true;
	return false;
}

bool check(Line l1, Line l2)
{
	if(l2.b * l1.a - l2.a * l1.b == 0)// параллельны
		return false;
	ll y = (l2.a * l1.c - l1.a * l2.c) / (l2.b * l1.a - l2.a * l1.b);
	ll x = (l1.b * l2.c - l1.c * l2.b) / (l2.b * l1.a - l2.a * l1.b);
	if(isContained(Segment(l1.p1, l1.p2), Segment(l2.p1, l2.p2), Point(x, y)))
		return true;
}

bool intersect(int ind1, int ind2)
{
	for(int i = 1; i <= l[ind1]; i++)
	{
		for(int j = 1; j <= l[ind2]; j++)
		{
			Line l1(p[ind1][i], p[ind1][i - 1]);
			Line l2(p[ind2][j], p[ind2][j - 1]);
			if(check(l1, l2))
				return true;
		}
	}
	return false;
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	scanf("%d %d", &A, &B);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &l[i]);
		for(int j = 0; j <= l[i]; j++)
			scanf("%d %d", &p[i][j].x, &p[i][j].y);
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(intersect(i, j))
			{
				printf("No\n%d %d", i + 1, j + 1);
				return 0;
			}
		}
	}
	printf("Yes");
	return 0;
}
