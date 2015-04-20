#include<cstdio>
#include<algorithm>

using namespace std;

int N, d, a[100023], ans;

int main()
{                       	
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	scanf("%d%d", &N, &d);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	sort(a, a + N);
	if (a[0] < 2 * d)
	{
		printf("%d\n", a[0]);
		return 0;
	}
	ans = a[0];
	for (int i = 1; i < N; i++)
		ans += max(0, a[i] - 2 * d);
   	printf("%d\n", ans);
	return 0;
}	