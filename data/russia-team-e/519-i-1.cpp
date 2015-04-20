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
	int i;
	cin >> n >> d;
	vector<int> a;
	vector<int> p;
	if(n == 1) 
	{
		int k;
		cin >> k;
		cout << k;
		return 0;
	}
	for(int i = 0; i < n; i++) 
	{
		int k;
		cin >> k;
		if(k >= d * 3) 
			a.push_back(k);
		if(k < d * 3 && k > d) 
			p.push_back(k);
		if(k <= d && k > maxc)
			maxc = k;
	}
	if( p.size() == 0 && a.size() == 0)
	{
		cout << maxc;
		return 0;
	}
	if(p.size() + a.size() == 1)
	{
		if(a.size() == 1)
		{
			cout << a[0];
		}
		else
		{
			cout << p[0];
		}
		return 0;
	}
	int sum = 0;
	sort(p.begin(), p.end());
    
	while(p.size() < 2 && !a.empty())
	{
		p.push_back(a[a.size()-1]);
		a.pop_back();
	}
	i = 1;
	while(p.size() - i >= 0 && i <= 2)
	{
		sum += p[p.size()-i] - d;
		i++;
	}
	for(i = 0; i < a.size(); i++)
	{
		sum += a[i] - 2*d;
	}
	cout << sum;
}