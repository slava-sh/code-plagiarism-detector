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
int n, k;
int A[200000];
bool check(int x)
{
	int i;
	llint cur = 0;
	for(i = 0; i < n - 1; i++)
	{
		if(cur + x < A[i])
		{
			cur = A[i];
		}
		else
		{
			cur = cur + x;
		}
		if(cur >= k)
		{
			return 0;
		}
	}
	if(cur + x < k)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	freopen("fence.in", "r", stdin); freopen("fence.out", "w", stdout);
	int i;
	scanf("%d%d", &n, &k);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A + n);
	int a, b, h;
	a = 1; b = A[0];
	for(; a + 1 < b; )
	{
		h = (a + b) / 2;
		if(check(h) == 1)
		{
			a = h;
		}
		else
		{
			b = h - 1;
		}
	}
	if(check(b) == 1)
	{
		a = b;
	}
	printf("%d\n", a);
	return 0;
}