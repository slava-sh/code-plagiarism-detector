#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[15007], ans, ans1 = -1, ans2 = -1;
short have[15007][15007];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];		
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			have[i][j] = have[i - 1][j];
		}
		have[i][a[i]]++;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			have[i][j] = have[i][j - 1] + have[i][j];
		}
	}
	int total = 0;
	for (int i = 1; i <= n; i++)
	{
		total += (have[i][n] - have[i][a[i]]);
	}
	int ans = total;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = i + 1; j <= n; ++j)
		{			
			if (a[i] < a[j]) continue;			
			int goodright = have[j - 1][a[i]] - have[j - 1][a[j] - 1];
			int goodleft = have[i][a[i]] - have[i][a[j] - 1];
			int curans = total - (goodright - goodleft);
			if (curans < ans)
			{
				ans = curans;
				ans1 = i;
				ans2 = j;
			}
			if (have[n][a[i] - 1] - have[j][a[i] - 1] == 0) break;
		}
	}
	cout << ans1 << ' ' << ans2 << '\n';
}