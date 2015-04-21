//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int n, perm[1000000], diff[1000000];
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &perm[i]);
		--perm[i];
	}

	for (int i = 0; i < n; i++)
		diff[i] = abs(perm[i] - i);

	int ans = 0, a = -1, b = -1;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int new_ans = diff[i] + diff[j];
			new_ans -= abs(perm[i] - j);
			new_ans -= abs(perm[j] - i);

			if (ans < new_ans)
			{
				ans = new_ans;
				a = i + 1;
				b = j + 1;
			}
		}
	}

	printf("%d %d", a, b);

	return 0;
}