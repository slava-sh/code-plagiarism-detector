#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
char str[100001], rev[100001];
unsigned long long h[2][100001];
unsigned long long pow[200002];
unsigned long long tmul, hmul = 1000000007;
int n, len;

unsigned long long geth(int s, int l, int r)
{
	if (l <= r)
		return (h[s][r] - ((l > 0) ? h[s][l - 1] : 0)) * pow[200001 - l];
	else
		return ((h[s][len - 1] - ((l > 0) ? h[s][l - 1] : 0)) + h[s][r] * pow[len]) * pow[200001 - l];
}

int main()
{
	freopen("inventory.in", "r", stdin);
	freopen("inventory.out", "w", stdout);
	
	tmul = 1;
	for (int i = 0; i < 200002; i++)
	{
		pow[i] = tmul;
		tmul *= hmul;
	}
	cin >> n;
	for (int zbcd = 0; zbcd < n; zbcd++)
	{
		cin >> str;

		len = strlen(str);

		for (int i = 0; i < len; i++)
			rev[i] = str[len - i - 1];

		h[0][0] = str[0];
		h[1][0] = rev[0];

		for (int i = 1; i < len; i++)
		{
			h[0][i] = h[0][i - 1] + pow[i] * str[i];
			h[1][i] = h[1][i - 1] + pow[i] * rev[i];
		}

		int l1 = 0, r1 = len / 2 - 1;
		int l2 = l1, r2 = r1;
		int pos = -1;
		for (int i = 0; i < len; i++)
		{
			unsigned long long h1 = geth(0, l1, r1), h2 = geth(1, l2, r2);
			if (h1 == h2)
			{
				pos = i;
				break;
			}
			l1 = (l1 - 1 + len) % len;
			r1 = (r1 - 1 + len) % len;
			l2 = (l2 + 1) % len;
			r2 = (r2 + 1) % len;
		}
		if (pos == -1)
			cout << -1 << "\n";
		else
			cout << len - pos << "\n";
	}
	return 0;
}