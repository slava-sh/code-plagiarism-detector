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
	for (int i = 0; i < N / 2; i++)
		swap(a[i], a[N - i - 1]);
	if (a[0] < 3 * d)
	{
		printf("%d\n", max(a[0], a[0] + a[1] - 2 * d));
		return 0;
	}
	ans = a[0];
	for (int i = 1; i < N; i++)
		if (a[i] >= 3 * d)
			ans += max(0, a[i] - 2 * d);
		else
		{
			if (a[i] > 2 * d)
				ans += a[i] - 2 * d;
			if (a[i + 1] > 2 * d)
				ans += a[i + 1] - 2 * d;
		   	printf("%d\n", ans);
		    return 0;
	   	}
   	printf("%d\n", ans);
	return 0;
}	