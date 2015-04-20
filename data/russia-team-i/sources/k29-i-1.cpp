#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

long long n, d, i, sum, col, a[100001];

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin >> n >> d;
	for (i =1 ; i <= n; i++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (i = 1; i <= n; i++)
		if (a[i] > d){
			sum += a[i];
			col++;
			}
	cout << sum - ((col - 1) * d * 2);
	return 0;
}