#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

const int Max = 20202;
int L, n;
char s[Max];

bool magic1()
{
	for (int i = 1; i <= L; i++)
	{
		if (n % i == 0)
		{
			bool err = false;
			for (int j = i + 1; j <= n; j++)
				if (s[j] != s[j - i])
				{
					err = true;
					break;
				}
			if (!err)
			{
				printf("1\n");
				for (int j = 1; j <= i; j++)
					printf("%c", s[j]);
				printf("\n");
				return true;
			}
		}
	}
	return false;
}

struct _dp_
{
	int s1, e1;
	int s2, e2;
};

bool mark[101][101][101];

bool cmp(int s1, int e1, int s2, int e2)
{
	if (e1 - s1 != e2 - s2)
		return false;
	return mark[s1][s2][e1 - s1 + 1];
}

bool magic3(int s, int e, int s1, int e1, int &s2, int &e2)
{
	if (s == e + 1)
		return true;
	if (s2 != 0 && e2 != 0)
	{
		if (s + e1 - s1 <= n)
		{
			if (cmp(s1, e1, s, s + e1 - s1))
			{
				if (magic3(s + e1 - s1 + 1, e, s1, e1, s2, e2))
					return true;
			}
		}
		if (s + e2 - s2 <= n)
		{
			if (cmp(s2, e2, s, s + e2 - s2))
			{
				if (magic3(s + e2 - s2 + 1, e, s1, e1, s2, e2))
					return true;
			}
		}
		return false;
	}
	for (int i = 1; i <= L; i++)
	{
		if (s + i - 1 <= n)
		{
			if (cmp(s1, e1, s, s + i - 1))
			{
				if (magic3(s + i, e, s1, e1, s2, e2))
					return true;
			}
			else
			{
				int S = s;
				int E = s + i - 1;
				if (magic3(s + i, e, s1, e1, S, E))
				{
					s2 = S;
					e2 = E;
					return true;
				}
			}
		}
		else
			break;
	}
	return false;
}

bool magic2()
{
	for (int i = 1; i <= L; i++)
	{
		int s1 = 0;
		int e1 = 0;
		if (magic3(i + 1, n, 1, i, s1, e1))
		{
			printf("2\n");
			for (int j = 1; j <= i; j++)
				printf("%c", s[j]);
			printf("\n");
			for (int j = s1; j <= e1; j++)
				printf("%c", s[j]);
			printf("\n");
			return true;
		}
	}
	return false;
}

/*
int dp[Max][Max];

bool magic2()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= L; j++)
			dp[i][j] = -1;
	for (int i = 1; i <= n; i++)
	{
		if (i <= L)
			dp[i][i] = 1;
		int down = i - 1;
		if (L < down)
			down = L;
		for (int j = 1; j <= down; j++)
		{
			int S = i - j + 1;
			int E = i;
			int e = S - 1;
			int s = e - j + 1;
			if (dp[i - j][j] == 1)
			{
				if (cmp(s, e, S, E))
					dp[i][j] = 1;
				else
					dp[i][j] = 2;
			}
			if (dp[i - j][j] == 2)
			{
				if (cmp(s, e, S, E))
					dp[i][j] = 2;
				else
				{
					int d = i - 1;
					if (L < d)
						d = L;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (i <= L)
		{
			_dp_ pref;
			pref.s1 = 1;
			pref.e1 = i;
			pref.s2 = -1;
			pref.e2 = -1;
			dp1[i].push_back(pref);
		}
		int down = i - L + 1;
		if (down < 2)
			down = 2;
		for (int j = i; j >= down; j--)
		{
			for (int z = 0; z < dp1[j - 1].size(); z++)
				if (cmp(dp1[j - 1][z].s1, dp1[j - 1][z].e1, j, i))
					dp1[i].push_back(dp1[j - 1][z]);
				else
				{
					_dp_ now = dp1[j - 1][z];
					now.s2 = j;
					now.e2 = i;
					dp2[i].push_back(now);
				}
			for (int z = 0; z < dp2[j - 1].size(); z++)
				if (cmp(dp2[j - 1][z].s1, dp2[j - 1][z].e1, j, i) || cmp(dp2[j - 1][z].s2, dp2[j - 1][z].e2, j, i))
					dp2[i].push_back(dp2[j - 1][z]);
		}
	}
	if (dp2[n].size() == 0)
		return false;
	printf("2\n");
	for (int i = dp2[n][0].s1; i <= dp2[n][0].e1; i++)
		printf("%c", s[i]);
	printf("\n");
	for (int i = dp2[n][0].s2; i <= dp2[n][0].e2; i++)
		printf("%c", s[i]);
	printf("\n");
	return true;
}
*/

int main()
{
	scanf(" %d", &L);
	scanf(" %s", &s);
	n = strlen(s);
	if (L > n)
		L = n;
	for (int i = n; i >= 1; i--)
		s[i] = s[i - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int LLL = n - i + 1;
			if (n - j + 1 < LLL)
				LLL = n - j + 1;
			for (int z = 1; z <= n; z++)
				mark[i][j][z] = false;
			for (int ind = 0; ind < LLL; ind++)
				if (s[i + ind] == s[j + ind])
					mark[i][j][ind + 1] = true;
				else
					break;
		}
	if (magic1())
	{
		return 0;
	}
	int a = 0;
	int b = 0;
	int c = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == 'a')
			a++;
		if (s[i] == 'b')
			b++;
		if (s[i] == 'c')
			c++;
	}
	if (a == 0 || b == 0 || c == 0)
	{
		printf("2\n");
		if (a != 0)
			printf("a\n");
		if (b != 0)
			printf("b\n");
		if (c != 0)
			printf("c\n");
		return 0;
	}
	if (magic2())
	{
		return 0;
	}
	printf("3\na\nb\nc\n");
	return 0;
}