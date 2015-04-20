#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 300001;
int d[MAXN];

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n, r;
	cin >> n >> r;
	long long cnt = ((long long)n * (long long)(n - 1)) / 2;
	for (int i = 0; i < n; i++)
	{
		cin >> d[i];
		int lg = -1, rg = i - 1;
		while (lg < rg)
		{
			int md = (lg + rg + 1) / 2;
			if (d[md] >= d[i] - r) rg = md - 1;
			else lg = md;
		}
		cnt -= (long long)(i - lg - 1);
	}
	cout << cnt << endl;
	return 0;
}