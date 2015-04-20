#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	vector <long long> a(n);
	long long minium = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		scanf("%I64d", &a[i]);
		minium = min(minium, a[i]);
	}
	sort(a.begin(), a.end());
	int low = 0;
	int high = minium + 1;
	while (low != high - 1)
	{
		int middle = (low + high) / 2;
		long long curColored = 0;
		for (int i = 0; i < n; ++i)
		{
			curColored = max(a[i], curColored + middle);
		}
		if (curColored <= k)
		{
			low = middle;
		}
		else
		{
			high = middle;
		}
	}
	printf("%d\n", low);
	return 0;
}