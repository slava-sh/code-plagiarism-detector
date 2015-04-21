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
#include <algorithm>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	long long n, k, cost_lamp, cost_el, a[200000], b[200000];
	scanf("%lld%lld%lld%lld", &n, &k, &cost_lamp, &cost_el);

	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		scanf("%lld%lld", &a[i], &b[i]);
		ans += (b[i] - a[i]) * cost_el;
	}

	if (n == 1)
	{
		printf("%lld", ans);
		return 0;
	}

	vector<long long> diff(n - 1);

	for (int i = 1; i < n; i++)
		diff[i - 1] = a[i] - b[i - 1];

	sort(diff.rbegin(), diff.rend());

	long long used = 0;

	int i;

	for (i = 0; i < n - 1; i++)
	{
		if (diff[i] * cost_el >= cost_lamp)
			used++;
		else
			break;
	}

	ans += (used / k) * cost_lamp;
	used %= k;

	while (i < n - 1)
	{
		while (used != k - 1 && i < n - 1)
		{
			used++;
			i++;
		}

		long long cost_k = 0;
		int j;
		for (j = i; j - i < k && j < n - 1; j++)
			cost_k += diff[j] * cost_el;

		if (cost_k > cost_lamp)
		{
			ans += cost_lamp;
			used = k - 1;
		}

		else
			ans += cost_k;

		i = j;
	}

	printf("%lld", ans);

	return 0;
}