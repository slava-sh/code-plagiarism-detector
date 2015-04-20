#include<cstdio>
#include<algorithm>

using namespace std;

int n, r, a[600005], l;
long long ans;

int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	scanf("%d%d", &n, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		l = upper_bound(a, a + n, a[i] + r) - a;
		ans += n - l;
	}
	printf("%I64d\n", ans);
	return 0;
}
