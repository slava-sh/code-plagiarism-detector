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
int A[200000];
int main()
{
	freopen("sochi.in", "r", stdin); freopen("sochi.out", "w", stdout);
	int n, d, i;
	scanf("%d%d", &n, &d);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
	reverse(A, A + n);
	int ans = A[0];
	int cnt = 0;
	if(A[0] >= 2 * d && A[1] >= 2 * d)
	{
		ans = max(ans, A[0] + A[1] - 2 * d);
	}
	for(i = 0; i < n - 2; i++)
	{
		if(A[i] < 3 * d)
		{
			break;
		}
		cnt += A[i];
		if(A[i + 1] >= 2 * d && A[i + 2] >= 2 * d)
		{
			ans = max(ans, cnt - 2 * d * (i + 1) + A[i + 1] + A[i + 2] - 2 * d);
		}
	}
	printf("%d\n", ans);
	return 0;
}