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
	for(int i = 0; i < k; i++)
	{
		d[0][i] = 1e14;
	}

	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			d[i][j] = 1e14;
			for(int pp = i; pp >= 1; pp--)
			{
				long long tt = (b[i] - a[pp]) * d1;
				if(j == k)
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
	long long ans = 1e15;
	for(int i = 0; i <= k; i++)
	{
		ans = min(ans, d[n][i]);
	}
	cout << ans << endl;
	return 0;
}