// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);


	int n, m;
	cin >> n >> m;
	int l[10001], r[10001], x[100001], h[10001];
	for (int i = 0; i < 10001; i++) { l[i] = 0; r[i] = 0; x[i] = 0; h[i] = 0; }
	for (int i = 0; i < n; i++) cin >> l[i] >> r[i] >> x[i];

	int q[10001];
	for (int i = 0; i < m; i++)
	{
		cin >> q[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = l[i], k = 1; j <= r[i]; j++, k *= -1)
		{
			h[j] += k * x[i];
		}
	}

	for (int i = 0; i < m; i++)
	{
		cout << h[q[i]] << endl;
	}

}

