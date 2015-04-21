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
	int curans = get();
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int p, t;
		cin >> p >> t;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if (t == a[p])
		{
			cout << curans << endl;
			continue;
		}
		if (p == 1)
		{
			if (a[2] == a[1])
			{
				curans++;
			}
			if (a[2] == t)
			{
				curans--;
			}
			a[p] = t;
			cout << curans << endl;
			continue;
		}
		if (p == n)
		{
			if (a[n - 1] == a[n])
			{
				curans++;
			}
			if (a[n - 1] == t)
			{
				curans--;
			}
			a[p] = t;
			cout << curans << endl;
			continue;
		}
		if (a[p - 1] == a[p] && a[p] == a[p + 1])
		{
			curans += 2;
			a[p] = t;
			cout << curans << endl;
			continue;
		}
		if (a[p - 1] == t && a[p + 1] == t)
		{
			curans -= 2;
			a[p] = t;
			cout << curans << endl;
			continue;
		}
		bool del = (a[p - 1] == a[p] || a[p + 1] == a[p]);
		bool add = (a[p - 1] == t || a[p + 1] == t);
		if (del)
		{
			curans++;
		}
		if (add)
		{
			curans--;
		}
		a[p] = t;
		cout << curans << endl;
	}
}