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

int main()
{
	FILE *in, *out;
	in = freopen("sochi.in", "r", stdin);
	out = freopen("sochi.out", "w", stdout);
//-------------------------------------------------------------------
	long long ans = 0, tans = 0;
	int n, f, d;
	cin >> n >> d;
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		cin >> f;
		ans = max(ans, (long long)f);
		v.push_back(f);
	}
	sort(v.begin(), v.end());
	n++;
	long long temp = v[n - 1] - d;
	if (temp < 0)
		cout << ans;
	else
	{
		for (int i = n - 2; i >= 0; i--)
		{
			tans = max(tans, temp + d);
			if (v[i] - 3 * d >= 0)
				temp += v[i] - 2 * d;
			else if (v[i] - d > 0)
			{
				temp += v[i] - d;
				break;
			}
			else
			{
				temp += d;
				break;
			}
		}
	}

	cout << max(ans, max(temp, tans));
//-------------------------------------------------------------------
	fclose(in);
	fclose(out);
	return 0;
}
