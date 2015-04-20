#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n, r;
	scanf("%d %d", &n, &r);
	vector <int> d(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &d[i]);
	}
	long long answer = 0;
	for (int i = 0; i < n; ++i)
	{
		int cur = distance(upper_bound(d.begin(), d.end(), d[i] + r), d.end());
		answer += cur;
	}
	printf("%I64d\n", answer);
	return 0;
}