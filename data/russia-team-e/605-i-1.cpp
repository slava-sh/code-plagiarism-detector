#include <iostream>
#include <algorithm>
using namespace std;

int const Max = 101101;
int n, d, len[Max];
long long ans;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> len[i];
	sort(len + 1, len + n + 1);
	len[0] = 0;
	if (len[n] >= 3 * d)
	{
		for (int i = n; i >= 0; i--)
			if (len[i] >= 3 * d)
				ans += (len[i] - 2 * d);
			else
			{
				if (i >= 2)
				{
					if (len[i] > 2 * d)
						ans += len[i] - d;
					else
						ans += d;
					if (len[i - 1] > 2 * d)
						ans += len[i - 1] - d;
					else
						ans += d;
					break;
				}
				if (i == 1)
				{
					if (len[i] > 2 * d)
						ans += len[i] - d;
					else
						ans += d;
					ans += d;
					break;
				}
				if (i == 0)
				{
					ans += 2 * d;
					break;
				}
				break;
			}
		cout << ans << endl;
		return 0;
	}
	ans = len[n];
	if (n >= 2)
	{
		if (len[n] + len[n - 1] - 2 * d > ans)
			ans = len[n] + len[n - 1] - 2 * d;
	}
	cout << ans << endl;
	return 0;
}

/*
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("prizes.in", "r", stdin);
	//freopen("prizes.out", "w", stdout);
	long long l1, l2;
	cin >> l1 >> l2;
	long long ans, L1, L2;
	L1 = min(l1, l2);
	L2 = max(l1, l2);
	if (L1 == 1)
	{
		if (L2 <= 2)
			ans = 0;
		else
		{
			ans = (L2 - 2) / 4;
			if ((L2 - 2) % 4 > 0)
				ans++;
		}
	}
	else
	{
		ans = (L1 - 2) / 4;
		if ((L1 - 2) % 4 > 0)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
*/