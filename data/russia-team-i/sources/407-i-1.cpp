#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>

using namespace std;

vector<int> v;
int d;

bool check(long long p)
{
	long long temp = 0;
	int i = 0, n = (int)v.size(), l = 0;
	for (; i < n; i++)
	{
		if (i == l)
		{
			if (v[i] - d >= 0)
			{
				temp = v[i] - d;
			}
			else
			{
				temp = 0;
				l = i + 1;
				continue;
			}
		}
		else
		{
			if (v[i] - d >= 0 && (temp + v[i] - d) >= p)
				return true;
			if (v[i] - 3 * d >= 0)
			{
				temp += v[i] - 2 * d;
			}
			else
			{
				if (v[i] - d >= 0)
				{
					temp = v[i] - d;
					l = i;
				}
				else
				{
					temp = 0;
					l = i + 1;
				}
			}
		}
	}
	if (temp >= p)
		return true;
	return false;
}

int main()
{
	FILE *in, *out;
	in = freopen("sochi.in", "r", stdin);
	out = freopen("sochi.out", "w", stdout);
//-------------------------------------------------------------------
	long long ans = 0;
	int n, f;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		cin >> f;
		ans = max(ans, (long long)f);
		v.push_back(f);
	}
	long long l, r, m;
	l = 1;
	r = 1000 * 1000001;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	cout << max(ans, l);
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
