#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[15007], ans, ans1 = -1, ans2 = -1;
int inversioncount(int n)
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (a[j]>a[i])
			{
				ans++;
			}
		}
	}
	return ans;
}
short have[15007][15007];
int main()
{
	int n=15007;
	//cin >> n;
	for (int i = 1; i <= n; i++)
	{
		//cin >> a[i];
		a[i] = n - i + 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			have[i][j] = have[i - 1][j];
		}
		have[i][a[i]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			have[i][j] = have[i][j - 1] + have[i][j];
		}
	}
	int total = inversioncount(n);
	int ans = total;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
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
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
}