#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int X = 1e5 + 1000;
long long lst[X];
long long d;
long long is_need(long long i)
{
	if (lst[i] >= 3*d) return 2;
	if (lst[i] > 2*d) return 1;
	return 0;
}
int main()
{
	long long n, i, ans = 0;
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout); 
	cin >> n >> d;
	for(i = 0; i < n; i++)
	{
		cin >> lst[i]; 
	}
	sort(lst, lst + n);
	i = n - 2;
	ans = lst[n - 1];
	while (i > -1 && is_need(i) > 1)
	{
		ans += lst[i] - 2*d;
		i--;
	}
	if (i > -1 && is_need(i) > 0)
	{
		ans+=lst[i] - 2*d;
		i--;
	}
	if (i > -1 && is_need(i) > 0)
	{
		ans+=lst[i] - 2*d;
		i--;
	}
	cout <<ans;
}