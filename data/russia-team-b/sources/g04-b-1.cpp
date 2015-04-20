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
int A[400000];
int main()
{
	freopen("che.in", "r", stdin); freopen("che.out", "w", stdout);
	int n, r, i, h;
	scanf("%d%d", &n, &r);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
	llint ans = 0;
	for(i = 0; i < n; i++)
	{
		h = A + n - upper_bound(A, A + n, A[i] + r);
		ans += h;
	}
	printf("%I64d\n", ans);
	return 0;
}