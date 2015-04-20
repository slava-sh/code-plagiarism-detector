#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	int n, d, maxc = -1;
	int i, ans;
	cin >> n >> d;
	vector<int> a;
	for(int i = 0; i < n; i++) 
	{
		int k;
		cin >> k;
		a.push_back(k);
	}
	sort(a.begin(), a.end());
	ans = a[a.size() - 1];
	i = a.size()- 2;
    while(i >= 0 && a[i] >= 3*d)
	{
		ans += a[i] - 2*d;
		i--;
	}
	if(i >= 1)
	{
		ans += a[i] - 2*d;
		ans += a[i-1] - 2*d;
	}
	else
	{
		if(i == 0)
			ans += a[i] - 2*d;
	}
	cout << ans;
}