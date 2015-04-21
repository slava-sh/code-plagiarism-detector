#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

int n, k;

int f(int n)
{
	return n / 2 + n % 2; 
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> n >> k;
	if(k == 1)
	{
		cout << n / 2 + n % 2;
		return 0;
	}
	else if(k == 2)
	{
		int ans = n + 1;
		for(int i = 1; i <= (int)sqrt(1. * n); i++)
		{
			if(n % i != 0)
				continue;
			ans = min(ans, f(i) * f(n / i));
		}
		cout << ans;
		return 0;
	}
	cout << 2;
	return 0;
}
