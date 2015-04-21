#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[100007],ans,ans1=-1,ans2=-1;
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
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int total = inversioncount(n);
	int ans = total;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (a[i] < a[j]) continue;
			int curans = total;
			for (int k = i + 1; k <= j; k++)
			{
				if (a[k]<a[i] && a[k]>a[j]) curans--;
			}
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