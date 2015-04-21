#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

#define int long long int

using namespace std;

struct point
{
	int x, y, id;
	point() : x(0), y(0), id(0) { }
	point(int a, int b, int c) : x(a), y(b), id(c) { }
};

const bool operator == (const point a, const point b)
{
	return a.x == b.x && a.y == b.y;
}

struct vect
{
	int x, y;
	vect() : x(0), y(0) { }
	vect(point a, point b) : x(b.x - a.x), y(b.y - a.y) { }
};

int crossproduct(vect a, vect b)
{
	return a.x * b.y - a.y * b.x;
}

int dotproduct(vect a, vect b)
{
	return a.x * b.x + a.y * b.y;
}

int area(point a, point b, point c)
{
	return crossproduct(vect(a, b), vect(a, c));
}


bool point_on_ray(point p, point begin, point end)
{
	return crossproduct(vect(begin, p), vect(begin, end)) == 0 && dotproduct(vect(begin, p), vect(begin, end)) >= 0;
}

bool point_on_fragment(point p, point begin, point end)
{
	return point_on_ray(p, begin, end) && point_on_ray(p, end, begin);
}

// bool cmp_point(point a, point b)
// {
// 	return (a.x < b.x || (a.x == b.x && a.y < b.y) || (a.x == b.x && a.y == b.y && a.id < b.id));
// }

// bool cmp(pair<point, point> a, pair<point, point> b)
// {
// 	return cmp_point(a.first, b.first);
// }


bool f(int a, int b, int c, int d)
{
	return max(min(a, b), min(c, d)) <= min(max(a, b), max(c, d));
}

bool different(int a, int b)
{
	if ((a > 0 && b < 0) || (a < 0 && b > 0))
		return true;
	return false;
}
bool intersect(pair<point, point> A, pair<point, point> B)
{
	if (A.first == B.first || A.first == B.second || A.second == B.first || A.second == B.second)
		return false;

	point a = A.first, b = A.second, c = B.first, d = B.second;
	return different(area(a, b, c), area(a, b, d)) && different(area(c, d, a), area(c, d, b)) && f(a.x, b.x, c.x, d.x) && f(a.y, b.y, c.y, d.y);
}

main()
{
	ios::sync_with_stdio(false);

	int A, B, n;
	cin >> A >> B >> n;
	vector<pair<point, point> > F;

	for (int i = 0; i < n; ++i)
	{
		int l;
		cin >> l;

		point current;
		cin >> current.x >> current.y;
		current.id = i;

		for (int j = 0; j < l; ++j)
		{
			int x, y;
			cin >> x >> y;
			F.push_back(make_pair(current, point(x, y, i)));
			current = point(x, y, i);
		}
	}

	// for (int i = 0; i < F.size(); ++i)
	// 	cout << F[i].first.id << endl;

	// sort(F.begin(), F.end(), cmp);

	// cout << F.size() << endl;


	for (int i = 0; i < F.size(); ++i)
	{
		pair<point, point> now = F[i];
		for (int j = 0; j < F.size(); ++j)
		{
			pair<point, point> next = F[j];

			if (now.first.x == A || next.first.x == A)
				continue;

			// cout << "?" << endl;
			if (now.first == next.first)
			{
				// cout << "!" << endl;
				pair<point, point> prev_now = F[i - 1];
				pair<point, point> prev_next = F[j - 1];

				if (intersect(make_pair(prev_now.first, now.second), make_pair(prev_next.first, next.second)))
				{
					cout << "No" << endl << now.first.id + 1 << " " << next.first.id + 1 << endl;
					return 0;
				}
			}
		}
	}

	// for (int i = 0; i < F.size(); ++i)
	// {
	// 	pair<point, point> now = F[i];

	// 	for (int j = 0; j < F.size(); ++j)
	// 	{
	// 		pair<point, point> next = F[j];

	// 		if (point_on_fragment(now.first, next.first, next.second))
	// 		{
	// 			pair<point, point> prev_now = F[i - 1];

	// 			if (intersect(make_pair(prev_now.first, now.second), next))
	// 			{
	// 				cout << "No" << endl << now.first.id + 1 << " " << next.first.id + 1 << endl;
	// 				return 0;
	// 			}
	// 		}
	// 	}
	// }

	for (int i = 0; i < F.size(); ++i)
	{
		pair<point, point> now = F[i];
		// cout << now.first.id << endl;
		for (int j = i + 1; j < F.size(); ++j)
		{
			pair<point, point> next = F[j];
			// if (next.first.id == now.first.id)
			// 	break;

			if (intersect(now, next))
			{
				// cout << now.first.x << " " << now.first.y << " " << now.second.x << " " << now.second.y << next.first.x << " " << next.first.y << " " << next.second.x << " " << next.second.y << endl;
				cout << "No" << endl << now.first.id + 1 << " " << next.first.id + 1 << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}