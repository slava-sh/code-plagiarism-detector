#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

#define LLD "%I64d"

#define FILENAME "che"

ll ans;
int i, j, n, r;
int d[300100];

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d %d", &n, &r);
	for (i = 0; i < n; i++)
			scanf("%d", &d[i]);

	j = 0;
	ans = 0;
	for (i = 0; i < n; i++)
	{
		while (j < n && d[i] + r >= d[j]) j++;
		ans += n - j;
	}
	printf(LLD"\n", ans);

	return 0;
}