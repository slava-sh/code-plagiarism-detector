#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "prizes"

ll n, m;

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf(LLD LLD, &n, &m);
	if (min(n, m) == 2)
	{
		printf("0\n");
	}
	else if (min(n, m) == 1)
	{
		n = max(n, m);
		printf(LLD, (n + 1) / 4);
	}
	else
	{
		printf("1\n");
	}

	return 0;
}