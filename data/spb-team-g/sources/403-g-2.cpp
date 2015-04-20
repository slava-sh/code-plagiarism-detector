#include<iostream>
#include<stdio.h>

using namespace std;
int a[10000];
int sum,c1=0,c2=0;
int main()
{
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);
	int n;
	float k;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	k = float(sum) / (float)n;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] >k) c1++;
		if (a[i] <=k) c2++;
	}
	if (c1 > c2) cout << c2;
	else cout << c1;

}
