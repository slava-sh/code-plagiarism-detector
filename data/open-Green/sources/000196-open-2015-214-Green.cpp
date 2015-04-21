#include<iostream>
#include<algorithm>
using namespace std;
int main()
{	
	int n, k;
	cin >> n >> k;
	if (k == 3)
	{
		cout << 2 << endl;
		return 0;
	}
	if (k == 1)
	{
		cout << (n + 1) / 2 << endl;
		return 0;
	}
	if (k == 2)
	{
		int ans = n + 1;
		for (int i = 1; i <= n; i++)
		{
			if (n%i == 0)
			{
				ans = min(ans, (i + 1) / 2 * ((n / i + 1) / 2));
			}
		}
		cout << ans << endl;
		return 0;
	}
}