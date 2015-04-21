//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

const int maxN = 2e5;

struct point
{
	long long x;
	long long y;
	point(){}
	point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}

	point operator-(point p)
	{
		return point(x - p.x, y - p.y);
	}

	long long operator*(point p)
	{
		return x * p.y - y * p.x;
	}

};

vector <vector <point> > v1;
vector <vector <point> > v;
long long L[maxN];
int tmp[maxN];

int nat[maxN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	long long A, B;
	cin >> A >> B;
	int n;
	cin >> n;
	v.resize(n + 1);
	v1.resize(n + 1);
	for(int i = 0; i < n; i++)
	{
		nat[i] = i;
		int l;
		cin >> l;
		L[i] = -1e9 - 1000;
		for(int j = 1; j <= l + 1; j++)
		{
			long long a, b;
			cin >> a >> b;
			L[i] = max(L[i], b);
			v[i].push_back(point(a, b));
		}
	}
	for(int j = 0; j < n; j++)
	{
		for(int i = j + 1; i < n; i++)
		{
			int um = -1;
			int lst = 1;
			for(int ti = 0; ti < v[i].size(); ti++)
			{
				for(int tj = lst; tj < v[j].size(); tj++)
				{
					if(v[i][ti].x >= v[j][tj - 1].x && v[i][ti].x <= v[j][tj].x)
					{
						point p1 = v[j][tj] - v[i][ti];
						point p2 = v[j][tj - 1] - v[i][ti];
						lst = tj;
						if(p1 * p2 == 0)
						{
							break;
						}
						if(p1 * p2 > 0)
						{
							if(um == -1 || um == 0)
							{
								um = 0;
							}
							else
							{
								cout << "No" << endl;
								cout << nat[j] + 1 << " " << nat[i] + 1 << endl;
								return 0;
							}
						}
						else
						{
							if(um == 1 || um == -1)
							{
								um = 1;
							}
							else
							{
								cout << "No" << endl;
								cout << nat[j] + 1 << " " << nat[i] + 1 << endl;
								return 0;
							}
						}
						break;
					}
				}
			}
			lst = 1;
			for(int tj = 0; tj < v[j].size(); tj++)
			{
				for(int ti = lst; ti < v[i].size(); ti++)
				{
					if(v[j][tj].x >= v[i][ti - 1].x && v[j][tj].x <= v[i][ti].x)
					{
						point p1 = v[i][ti] - v[j][tj];
						point p2 = v[i][ti - 1] - v[j][tj];
						lst = ti;
						if(p1 * p2 == 0)
						{
							break;
						}
						if(p1 * p2 > 0)
						{
							if(um == -1 || um == 1)
							{
								um = 1;
							}
							else
							{
								cout << "No" << endl;
								cout << nat[j] + 1 << " " << nat[i] + 1 << endl;
								return 0;
							}
						}
						else
						{
							if(um == 0 || um == -1)
							{
								um = 0;
							}
							else
							{
								cout << "No" << endl;	
								cout << nat[j] + 1 << " " << nat[i] + 1 << endl;
								return 0;
							}
						}
						break;
					}
				}
			}
		}
	}

	cout << "Yes" << endl;
	return 0;
}