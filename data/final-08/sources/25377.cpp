#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

double p[101];
int n;

int main()
{
	scanf("%d", &n);
	for(int i = 0; i <= n; i++) scanf("%lf", &p[i]);

	double res = (p[0] + p[n]) / 2.0;

	for(int i = n; i >= (n + 1) / 2; i--)
	{
		double need = 2 * i - n;
		for(int j = 0; j < (n + 1) / 2; j++)
		{
			double times = need / (n - 2 * j);

			double cur = (p[i] + times * p[j]) / (1 + times);

			//printf("%d and %.3lf * %d -> %.3lf\n", i, times, j, cur);

			res = max(res, cur);
		}
	}

	printf("%.10lf\n", res);

	return 0;
}