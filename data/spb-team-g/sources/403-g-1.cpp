#include<iostream>
#include<stdio.h>

using namespace std;
int a[10000];
int sum,c;
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
	k = sum / n;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > k) c++;
	}
	cout << c;

}
