#include<iostream>
using namespace std;
int a[1000007], n;
int get()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i==1 || a[i] != a[i - 1]) ans++;
	}
	return ans;
}
int main()
{	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int p, t;
		cin >> p >> t;
		a[p] = t;
		cout << get() << endl;
	}
}