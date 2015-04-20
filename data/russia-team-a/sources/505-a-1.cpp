#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_N = 1005;
const int MOD = 1000000007;
#define ll long long
#define ld long double

int n;
int flag[MAX_N];
int a[MAX_N];
int z[MAX_N];
int s[MAX_N];
int w[MAX_N];
int ans[MAX_N];
void find_z()
{
	z[0] = 0;
	int l = 0;
	int r = 0;
	for (int i = 1; i < n; i++)
	{
		if (i > r)
		{
			int k = 0;
			int d = i;
			while (d < n && w[d] == w[d - i])
			{
				k++;
				d++;
			}
			z[i] = k;
			if (k > 0)
			{
				l = i;
				r = i + k - 1;
			}
		}
		else
		{
			int k = z[i - l];
			if (k <= r - i) z[i] = k;
			else if (k > r - i)
			{
				k = r - i + 1;
				int d = r + 1;
				while (d < n && w[d] == w[d - i])
				{
					k++;
					d++;
				}
				z[i] = k;
				if (k > 0)
				{
					l = i;
					r = i + k - 1;
				}
			}
		}
	}
	return;
}

int check(int pos, int c)
{
	for (int i = 0; i < n; i++)
		z[i] = 0;
	for (int i = 0; i < n; i++)
		w[i] = s[i];

	if (pos != -1)
	{
		for (int i = 0; i < n; i++)
			if (flag[i] == flag[pos])
				w[i] = c;
	}

	find_z();
	for (int i = 0; i < n; i++)
		if (w[i] != -1 && (z[i] != a[i] && a[i] != -1))
			return 0;
	return 1;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		s[i] = -1;
	}

	s[0] = 0;
	for (int i = 1; i < n; i++)
		if (a[i] == 0)
			s[i] = 1;
		else if (a[i] > 0)
			s[i] = 0;

	int colour = 1;
	for (int i = 0; i < n; i++)
		if (a[i] != -1)
		{
			int p1 = 0;
			int p2 = i;
			int cnt = 0;
			while (cnt < a[i])
			{
				if (s[p1] != s[p2] && (s[p1] != -1 && s[p2] != -1))
				{
					cout << 0;
					return 0;
				}
				else if (s[p1] == -1 && s[p2] == -1)
				{
					if (flag[p1] == 0 && flag[p2] == 0)
					{
						flag[p1] = flag[p2] = colour;
						colour++;
					}
					else if (flag[p1] != 0)
						flag[p2] = flag[p1];
					else if (flag[p2] != 0)
						flag[p1] = flag[p2];
				}
				else if (s[p1] != -1 && s[p2] == -1)
				{
					s[p2] = s[p1];
					if (flag[p2] != 0)
					{
						for (int j = 0; j < n; j++)
							if (flag[j] == flag[p2])
								s[j] = s[p1];
					}
				}
				else if (s[p1] == -1 && s[p2] != -1)
				{
					s[p1] = s[p2];
					if (flag[p1] != 0)
					{
						for (int j = 0; j < n; j++)
							if (flag[j] == flag[p1])
								s[j] = s[p2];
					}
				}
				p1++;
				p2++;
				cnt++;
			}
		}

	for (int i = 0; i < n; i++)
		if (flag[i] != 0)
		{
			if (s[i] != -1)
			{
				for (int j = 0; j < n; j++)
					if (flag[j] == flag[i])
						s[j] = s[i];
			}
			else
			{
				ans[flag[i]] += check(i, 0);
				ans[flag[i]] += check(i, 1);
				if (ans[flag[i]] == 0)
				{
					cout << 0;
					return 0;
				}
			}
		}


	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (flag[i] == -1)
			cnt++;

	if (cnt == 0)
	{
		if (check(-1, -1) == 0)
		{
			cout << 0;
			return 0;
		}
		else
		{
			cout << 2;
			return 0;
		}
	}

	long long otv = 1;
	for (int i = 1; i <= colour; i++)
		if (ans[i] != 0)
			otv = (otv * ans[i]) % MOD;
	otv = (otv * 2LL) % MOD;
	cout << otv;

	return 0;
}