#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++)
		cin >> a[i];
	int Q;
	cin >> Q;
	int ans = 1;
	for (int q = 1; q < N; q++)
	{
		if (a[q] != a[q - 1])
			ans++;
	}
	for (int i = 0; i < Q; i++)
	{
		int x, pos;
		cin >> pos >> x;
		if (N == 1)
		{
			cout << 1 << endl;
			continue;
		}
		pos--;
		if (a[pos] == x)
		{
			cout << ans << endl;
			continue;
		}
		if (pos == 0)
		{
			if (a[pos + 1] == a[pos])
			{
				ans++;
				cout << ans << endl;
				a[pos] = x;
				continue;
			}
			else
			{
				if (x == a[pos + 1])
				{
					ans--;
					cout << ans << endl;
					a[pos] = x;
					continue;
				}
				else
				{
					cout << ans << endl;
					a[pos] = x;
					continue;
				}
			}
		}
		if (pos == N - 1)
		{
			if (a[pos - 1] == a[pos])
			{
				ans++;
				cout << ans << endl;
				a[pos] = x;
				continue;
			}
			else
			{
				if (x == a[pos - 1])
				{
					ans--;
					cout << ans << endl;
					a[pos] = x;
					continue;
				}
				else
				{
					cout << ans << endl;
					a[pos] = x;
					continue;
				}
			}
		}
		if (a[pos - 1] == a[pos + 1])
		{
			if (x == a[pos - 1])
			{
				ans -= 2;
				cout << ans << endl;
				a[pos] = x;
				continue;
			}
		}
		if (a[pos - 1] == a[pos] && a[pos] == a[pos + 1])
		{
			ans += 2;
			cout << ans << endl;
			a[pos] = x;
			continue;
		}
		if ((a[pos] == a[pos - 1] && x == a[pos + 1]) || (a[pos] == a[pos + 1] && x == a[pos - 1]))
		{
			cout << ans << endl;
			a[pos] = x;
			continue;
		}
		if (a[pos] == a[pos - 1] || a[pos] == a[pos + 1])
		{
			ans++;
			cout << ans << endl;
			a[pos] = x;
			continue;
		}
		if (x == a[pos - 1] || x == a[pos + 1])
		{
			ans--;
			cout << ans << endl;
			a[pos] = x;
			continue;
		}
		if (x != a[pos - 1] && x != a[pos + 1] && a[pos] != a[pos - 1] && a[pos] != a[pos + 1])
		{
			cout << ans << endl;
			a[pos] = x;
			continue;
		}
	}
	return 0;
}