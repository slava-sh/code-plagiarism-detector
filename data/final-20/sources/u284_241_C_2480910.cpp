#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define file ""
#define SIZE(A) ((int)A.size())
#define sqr(A) (1LL*(A)*(A))
#define x1 giwrjo
#define x2 gfiogjos
#define y1 lfjnfb
#define y2 fbnjdfjbn

const int MAXN = 200;
int h1, h2, n;
int v[MAXN], l[MAXN], r[MAXN], w[MAXN];
char c[MAXN];

int doit()
{
	int ret = 0;

	for (int len = 1/*TODO*/; len <= n; len++)
	{
	 	int x1 = 0, y1 = h1;
	 	int x2 = 100000, y2 = 100*len;
	 	if (len & 1)
	 		y2 += 100-h2;
	 	else
	 		y2 += h2;

	 	int cur = 0;
	 	long long A = y2-y1, B = x1-x2, C = 1LL*x2*y1-1LL*x1*y2;

	 	if (A < 0) A *= -1, B *= -1, C *= -1;

	 	for (int i = 0; i < n; i++)
	 		w[i] = 0;

	 	for (int j = 0, cury = 100, fnd; j < len; j++, cury+=100)
	 	{
	 		fnd = 0;
	 		for (int i = 0; i < n; i++)
	 			if (j&1)
	 			{
	 			 	if (c[i] == 'F')
	 			 	{
						if (l[i]*A <= -B*cury-C && -B*cury-C <= 1LL*r[i]*A)
						{
							if (w[i]) break;

							fnd = 1;
							cur += v[i];
							w[i] = 1;
						}
	 			 	}
	 			}
	 			else
	 			{
					if (c[i] == 'T')
					{
						if (l[i]*A <= -B*cury-C && -B*cury-C <= r[i]*A)
						{
							if (w[i]) break;
							fnd = 1;
							cur += v[i];
							w[i] = 1;
						}
					}
	 			}

	 		if (fnd == 0)
	 		{
	 			cur = -1000000000;
	 			break;
	 		}
	 	}


	 	ret = max(ret, cur);
	}

	return ret;
}

int main ()
{
	scanf("%d%d%d", &h1, &h2, &n);
	for (int i = 0; i < n; i++)
	 	cin >> v[i] >> c[i] >> l[i] >> r[i];

	int res = 0;
	res = max(res, doit());
	for (int i = 0; i < n; i++)
		if (c[i] == 'T')
			c[i] = 'F';
		else
			c[i] = 'T';
	h1 = 100-h1;
	h2 = 100-h2;
	res = max(res, doit());

	printf("%d\n", res);

	return 0;
}
