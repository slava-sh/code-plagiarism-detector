#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, m;

int main()
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	
	scanf("%i %i", &n, &m);
	if (n>m)
		swap(m, n);

	if (n==1)
	{
		if (m<3)
			printf("0");
		else
			printf("%i", (m-3)/4 + 1);
		return 0;
	}


	if (n==2)
		printf("0");
	else
		printf("1");

	return 0;
}