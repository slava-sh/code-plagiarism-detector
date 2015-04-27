#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

using namespace std;
unsigned long long P = 1759LL;
const int MAX_N = 200005;

unsigned long long step[MAX_N];
unsigned long long h_r[MAX_N], h_l[MAX_N];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("inventory.in", "r", stdin);
	freopen("inventory.out", "w", stdout);
#endif

	unsigned long long step_p = 1;
	for (int i = 0; i < MAX_N; i++)
	{
		step[i] = step_p;
		step_p *= P;
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string sx;
		cin >> sx;
		int n = (int)sx.length();
		if (n == 1) {cout << 0 << "\n"; continue;}

		int k = 0;
		if (n % 2 != 0) k = 1;
		int dl = n / 2;
		int len = 2 * n;
		string s = sx + sx;
		h_r[0] = s[0];
		for (int i = 1; i < len; i++)
			h_r[i] = (h_r[i - 1] * P) + s[i];

		h_l[len - 1] = s[len - 1];
		for (int i = len - 2; i >= 0; i--)
			h_l[i] = (h_l[i + 1] * P) + s[i];

		int f = 0;
		for (int i = 0; i < n; i++)
		{
			unsigned long long h1, h2;
			if (i == 0) h1 = h_r[dl - 1];
			else h1 = h_r[i + dl - 1] - h_r[i - 1] * step[dl];
			int l1 = i + dl + k + dl;
			int l2 = i + dl + k;
			h2 = h_l[l2] - h_l[l1] * step[dl];
			if (h1 == h2)
			{
				f = 1;
				cout << (i) << "\n";
				break;
			}
		}
		if (f == 0) cout << -1 << "\n";
	}

	return 0;
}