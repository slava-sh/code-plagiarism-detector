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

int N, D, ans;
int a[100100];

int main()
{
	int i;
	freopen("sochi.in", "r", stdin); freopen("sochi.out", "w", stdout);
	scanf ("%d%d", &N, &D);
	for (i=0; i<N; ++i)
	{
		scanf ("%d", a + i);
	}
	sort (a, a + i);
	ans = a[N-1];
	/*if (N - 2 >= 0 && a[N-2] > 2 * D)
		ans -= D;
	else
	{
		printf ("%d\n", ans);
		return 0;
	}*/
	int p = 0;
	bool b = false;
	for (i=N-2; i>=0 && p < 2; --i)
	{
		if (a[i] >= 3 * D)
			ans += a[i] - 2*D;
		else
			if (a[i] > 2 * D)
			{
				ans += a[i] - 2*D;
				++p;
			}
			else
				break;
	}
	printf ("%d\n", ans);
	return 0;
}