//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

#define eps 0.0000001

using namespace std;

struct point
{
	int x;
	int y;
};

struct br_line
{
	int l;
	point p[200000];

	br_line()
	{
		//p = new point[200000];
	}

	void scan()
	{
		scanf("%d", &l);
		l++;
		for (int i = 0; i < l; i++)
			scanf("%d%d", &p[i].x, &p[i].y);
	}

	int intersects(const br_line& x)
	{
		int eq = 0;
		int it1 = 0, it2 = 0;

		while (it1 < l && it2 < x.l)
		{
			if (p[it1].x == x.p[it2].x)
			{
				if (eq == 0)
				{
					if (p[it1].y < x.p[it2].y)
						eq = -1;
					else if (p[it1].y > x.p[it2].y)
						eq = 1;
				}

				else if (eq == -1)
				{
					if (p[it1].y > x.p[it2].y)
						return 0;
				}

				else
				{
					if (p[it1].y < x.p[it2].y)
						return 0;
				}

				it1++;
				it2++;
			}

			else if (p[it1].x < x.p[it2].x)
			{
				//ищем такую точку на второй линии, х2 известен, ищем у2
				
				long double x1 = x.p[it2].x - x.p[it2 - 1].x;
				long double y1 = x.p[it2].y - x.p[it2 - 1].y;
				long double x2 = p[it1].x - x.p[it2 - 1].x;

				long double y2 = (x2 * y1) / x1;
				y2 += x.p[it2 - 1].y;

				if (eq == 0)
				{
					if ((long double)p[it1].y < y2 - eps)
						eq = -1;
					else if ((long double)p[it1].y > y2 + eps)
						eq = 1;
				}

				else if (eq == -1)
				{
					if ((long double)p[it1].y > y2 + eps)
						return 0;
				}

				else
				{
					if ((long double)p[it1].y < y2 - eps)
						return 0;
				}

				it1++;
			}

			else
			{
				long double x1 = p[it1].x - p[it1 - 1].x;
				long double y1 = p[it1].y - p[it1 - 1].y;
				long double x2 = x.p[it2].x - p[it1 - 1].x;

				long double y2 = (x2 * y1) / x1;
				y2 += p[it1 - 1].y;

				if (eq == 0)
				{
					if ((long double)x.p[it2].y > y2 + eps)
						eq = -1;
					else if ((long double)x.p[it2].y < y2 - eps)
						eq = 1;
				}

				else if (eq == -1)
				{
					if ((long double)x.p[it2].y < y2 - eps)
						return 0;
				}

				else
				{
					if ((long double)x.p[it2].y > y2 + eps)
						return 0;
				}

				it2++;
			}
		}

		if (eq == 0)
			return 1;
		return eq;
	} //0 - пересекаются, 1 - наша выше, -1 - наша ниже

	/*void operator=(br_line& x)
	{
		l = x.l;
		p = x.p;
	}*/
};

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int a, b, n, l, x, y, upper_num, lower_num;
	scanf("%d%d%d", &a, &b, &n);

	if (n == 1)
	{
		printf("Yes");
		return 0;
	}

	br_line upper, lower, cur1, cur2;

	cur1.scan();
	cur2.scan();

 	int up1 = cur1.intersects(cur2);

	if (up1 == 0)
	{
		printf("No\n1 2");
		return 0;
	}

	if (up1 == 1)
	{
		upper = cur1;
		lower = cur2;
		upper_num = 1;
		lower_num = 2;
	}

	else
	{
		upper = cur2;
		lower = cur1;
		upper_num = 2;
		lower_num = 1;
	}

	for (int i = 2; i < n; i++)
	{
		cur1.scan();

		int up = upper.intersects(cur1);

		if (up == 0)
		{
			printf("No\n%d %d", upper_num, i + 1);
			return 0;
		}

		else if (up == -1)
		{
			upper = cur1;
			upper_num = i + 1;
		}

		else
		{
			int low = lower.intersects(cur1);

			if (low == 0)
			{
				printf("No\n%d %d", lower_num, i + 1);
				return 0;
			}

			else if (low == 1)
			{
				lower = cur1;
				lower_num = i + 1;
			}
		}
	}

	printf("Yes");

	return 0;
}