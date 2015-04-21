#include<iostream>
#include<algorithm>
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
	ans = inversioncount(n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			swap(a[i], a[j]);
			if (inversioncount(n) < ans)
			{
				ans = inversioncount(n);
				ans1 = i;
				ans2 = j;
			}
			swap(a[j], a[i]);
		}
	}
	cout << ans1 << ' ' << ans2 << endl;
}