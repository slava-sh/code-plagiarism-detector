#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <list>
#include <set>

using namespace std;

long long h1, h2;
int len1, len2;
string s;
unsigned int h[1000][1000];
const int p = (1<<30)-7;
const int t = 1373;
int dp[1000];
int n, l;

set <pair <int, int> > s1;

inline bool check(const int pos)
{
	if (dp[pos] != -1)
		return (dp[pos] == 1);
	bool result = false;
	if (len1 <= n - pos)
	{
		if (h1 == h[pos][pos + len1 - 1])
			if (s.length() - pos == len1) result = true;
			else result |= check(pos + len1);
		if (result)
		{
			dp[pos] = true;
			return true;	
		}
	}
	if (len2 <= n - pos)
	{
		if (h2 == h[pos][pos + len2 - 1])
			if (s.length() - pos == len2) result = true;
			else result |= check(pos + len2);
	}
	dp[pos] = result;
	return result;	
}

int main()
{
	cin >> l;
	cin >> s;
	n = s.length();
	//Now answer can be 1, 2 or 3.
	for (int i = 0; i < n; i++)
	{
		h[i][i] = (s[i] - 'a' + 1);
		for (int j = i; j < n; j++)
			h[i][j] = (h[i][j - 1] * t % p + (s[j] - 'a' + 1) + p) % p;
	}
	for (int j = 1; j <= l && j <= n; j++)
	{
		if (n % j == 0)
		{
			bool ok = true;
			int cur = 0;
			while (cur != n)
				ok &= h[cur][cur + j - 1] == h[0][j - 1], cur += j;
			if (ok)
			{
				cout << 1 << "\n" << s.substr(0, j);
				return 0;
			}
		}
	}
	//Answer is more than 1. (In case of a,b answer can not be 3 so we print "a, b")
	for (int i = 0; i < n; i++)
		for (len1 = 1; len1 <= l && i + len1 < n; len1++)
			for (len2 = 1; len2 <= l; len2++)
			{
				for (int q = 0; q < n; q++)
					dp[q] = -1;
				if (i + len1 + len2 > n) break;
				h1 = h[i][i + len1 - 1];
				h2 = h[i + len1][i + len1 + len2 - 1];
				if (s1.count(make_pair(min(h1, h2), max(h1, h2))))
					continue;
				if (check(0))
				{
					cout << 2 << endl << s.substr(i, len1) << endl << s.substr(i + len1, len2);
					return 0;
				}
				s1.insert(make_pair(min(h1, h2), max(h1, h2)));
			}
	cout << 3 << "\na\nb\nc";
	return 0;
}