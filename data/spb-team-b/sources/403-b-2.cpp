#include<iostream>
#include<stdio.h>

using namespace std;
int a[10000];
int main()
{
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	int n,k=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] >= i) k++;
		else break;
	}
	cout << k << endl;
	for (int i = 1; i <= k;i++)
	{
		cout << i << " " << i << endl;
	}
}
