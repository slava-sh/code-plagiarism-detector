#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;

int mas[MAXN];
int n, q;

int check()
{
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] != mas[i - 1] || i == 0)
			res++;
	}
	return res;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &mas[i]);

	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int ind, cl;
		scanf("%d%d", &ind, &cl);
		ind--;
		mas[ind] = cl;
		printf("%d\n", check()); 
	}

	return 0;
}