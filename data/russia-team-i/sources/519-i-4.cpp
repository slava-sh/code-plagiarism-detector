#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	long long n, d;
	long long i, ans;
	cin >> n >> d;
	vector<long long> a(n);
	for(i = 0; i < n; i++) 
		cin >> a[i];

	sort(a.begin(), a.end());
	ans = a[a.size() - 1];
	i = a.size()- 2;
    while(i >= 0 && a[i] >= 3*d)
	{
		ans = ans + a[i] - 2*d;
		i--;
	}
	if(i >= 0)
	{
		if(a[i] > 2*d)
		ans = ans + a[i] - 2*d;
		if(i - 1 >= 0 && a[i-1] > 2*d)
		ans = ans + a[i-1] - 2*d;
	}
	cout << ans;
}