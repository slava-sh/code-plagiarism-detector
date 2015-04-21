#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 1e6 + 11;

int n, a[MAX];


int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	scanf("%d", &n);
	int bad = 0;
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		bad += abs(a[i] - i);
	}
	int ans = bad;
	int ind1 = -1;
	int ind2 = -1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int good = bad - abs(a[i] - i) + abs(a[i] - j);
			good = good - abs(a[j] - j) + abs(a[j] - i);
			if(good < ans)
			{
				ans = good;
				ind1 = i;
				ind2 = j;
			}
		}
	}
	printf("%d %d", ind1, ind2);
	return 0;
}
