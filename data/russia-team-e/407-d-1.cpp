#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <climits>

using namespace std;

vector<int> v;
int k;

bool check(int f)
{
	int i, n = (int)v.size(), l = v[0];
	for (i = 1; i < n; i++)
	{
		if (l + f < v[i])
			l = v[i];
		else
			l += f;
		if (l > k)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	FILE *in, *out;
	in = freopen("fence.in", "r", stdin);
	out = freopen("fence.out", "w", stdout);
//-------------------------------------------------------------------

	int n, f, r = INT_MAX;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> f;
		r = min(f + 1, r);
		v.push_back(f);
	}
	sort(v.begin(), v.end());

	int l = 0, m;
	while (r - l > 1)
	{
		m = (r + l) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	cout << l;
	
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
