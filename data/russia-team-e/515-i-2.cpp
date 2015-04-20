#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int X = 1e5 + 2;
long long lst[X];
long long d;
int is_need(int i)
{
	if (lst[i-1]>=3*d) return 2;
	if (lst[i-1]>2*d) return 1;
	return 0;
}
int main()
{
	long long n, i, ans;
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout); 
	cin >> n >> d;
	for(i = 0; i < n; i++)
	{
		cin >> lst[i]; 
	}
	sort(lst, lst + n);
	i = n - 1;
	ans=lst[n - 1];
	while (i>0 && is_need(i)==2)
	{
		ans+=lst[i-1]-2*d;
		i--;
	}
	if (i>0 && is_need(i)==1)
	{
		ans+=lst[i-1]-2*d;
		i--;
	}
	if (i>0 && is_need(i)==1)
	{
		ans+=lst[i-1]-2*d;
		i--;
	}
	cout <<ans;
}