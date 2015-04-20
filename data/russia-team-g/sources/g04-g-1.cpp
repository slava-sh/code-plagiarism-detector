#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
typedef __int64 llint;
typedef string str;
int main()
{
	int n,m;
	freopen("prizes.in", "r", stdin); freopen("prizes.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	if (n < m)
	{
		int s = 0;
		int k = 3;
		while (k <= n)
		{
			s ++;
			k += 4;
		}
		printf ("%d\n", s);
	}
	else
	{
		int s = 0;
		int k = 3;
		while (k <= m)
		{
			s ++;
			k += 4;
		}
		printf ("%d\n", s);
	}
	return 0;
}