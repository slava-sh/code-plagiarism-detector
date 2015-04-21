//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;

const int maxN = 200;	

long long a[maxN];
long long b[maxN];
long long d[maxN][maxN];

int main()
{
	long long n, k, c, d1;
	cin >> n >> k >> c >> d1;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> b[i];
	}
	for(int i = 0; i <= k; i++)
	{
		d[1][i] = 2e18;
	}
	d[1][k - 1] = (b[1] - a[1]) * d1;
	for(int i = 2; i <= n; i++)
	{
		for(int j = 0; j < k; j++)
		{
			d[i][j] = 2e18;
			for(int pp = 1; pp <= i; pp++)
			{
				long long tt = (b[i] - a[pp]) * d1;
				if(pp == 1)
				{
					if(j == k - 1)
					{
						d[i][j] = min(d[i][j], tt);
						continue;
					}
					else
					{
						continue;
					}
				}
				if(j == k - 1)
				{
					d[i][j] = min(d[i][j], tt + d[pp - 1][0] + c);
				}
				else
				{
					d[i][j] = min(d[i][j], tt + d[pp - 1][j + 1]);
				}
			}
		}
	}
	long long ans = d[n][0];
	for(int i = 0; i < k; i++)
	{
		ans = min(ans, d[n][i]);
	}
	cout << ans << endl;
	return 0;
}