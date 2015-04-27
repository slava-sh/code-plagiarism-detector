#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <set>
#include <map>

using namespace std;

int n;
double p[101];

void read_data()
{
	scanf("%d", &n);

	for (int i = 0 ; i <= n; ++i)
	{
		scanf("%lf", &p[i]);
	}
}

bool check(double b)
{
	if (n%2 == 0 && b < p[n/2]) return false;

	double lb = 0, ub = 1e9;

	for (int i = 0; i <= n; ++i)
	{
		if (2*i == n) continue;

		if (2*i < n) ub = min(ub, (p[i] - b) / (2*i - n));
		if (2*i > n) lb = max(lb, (p[i] - b) / (2*i - n));
	}

	if (lb <= ub) return true; else return false;
}

void solve()
{
	double bl = 0, br = 1;

	while (br-bl > 1e-9)
	{
		double b = (bl + br) / 2;
		if (check(b)) br = b; else bl = b;
	}

	printf("%.10lf\n", (bl + br) / 2);
}

int main()
{
	//freopen("input.txt", "r", stdin);

	read_data();
	solve();

	return 0;
}
