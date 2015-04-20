#include <iostream>
#include <cstdio>

using namespace std;

int const Max = 303303;
int dist[Max];
int n, r;
long long ans;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	scanf(" %d %d", &n, &r);
	for (int i = 1; i <= n; i++)
		scanf(" %d", &dist[i]);
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (dist[n] - dist[i] > r)
		{
			int L, R, M;
			L = i;
			R = n;
			while (true)
			{
				if (L >= R)
				{
					ans += (n - R + 1);
					break;
				}
				M = (L + R) / 2;
				if (dist[M] - dist[i] > r)
					R = M;
				else
					L = M + 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}