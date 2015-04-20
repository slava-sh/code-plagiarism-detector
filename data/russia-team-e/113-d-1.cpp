#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

int n, k, x, l, r, m;
long long ans;
vector < int > a;

bool check(int x)
{
	int d = a[0];
	if (a[0] < x)
		return false;
	for (int i = 1; i < a.size(); ++i)
	{
		if (d > k || a[i] < x || x > k - d)
			return false;
		d = max(d + x - a[i] + 1, 1) + a[i] - 1;
	}
	return true;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	l = 0;
	r = a[a.size() - 1] + 1;
	while (l + 1 < r)
	{
		m = l + (r - l) / 2;
		if (check(m))
			l = m;
		else
			r = m;
	}
	if (check(r))
		cout << r << endl;
	else
		cout << l << endl;
	//system("pause");
}