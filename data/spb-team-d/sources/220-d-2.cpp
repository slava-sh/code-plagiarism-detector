/* team 220. */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
};

int _main_()
{
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n, a[200000], i, j, h;
	long long sumn, minsum = -1;
	cin >> n >> h;
	for (i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
	}
	for (i = 0; i <= n - h; i++)
	{
		sumn = 0;
		for (j = i; j < i + h; j++)
		{
			if (a[j] > j - i + 1)
			{
				sumn = -1;
				break;
			}
			sumn += j - i + 1 - a[j];
		}
		if ((sumn <= minsum || minsum == -1) && sumn != -1)
			minsum = sumn;
	}

	cout << minsum << endl;
	return 0;
}

struct blow
{
	int l, r, x;
	blow() :
		l(0), r(0), x(0)
	{
	}
	blow(int nl, int nr, int nx) :
		l(nl), r(nr), x(nx)
	{
	}
};

int main()
{
  freopen("dunes.in", "r", stdin);
  freopen("dunes.out", "w", stdout);

  int n, m;
  int l, r, x;

  cin >> n >> m;
  vector<blow> Ar(n);

  for (int i = 0; i < n; i++)
  {
    cin >> l >> r >> x;
	Ar[i] = blow(l, r, x);
  }

  for (int i = 0; i < m; i++)
  {
    cin >> x;
	int res = 0;
	for (int j = 0; j < n; j++)
	{
		if (x >= Ar[j].l && x <= Ar[j].r)
			res += (x - Ar[j].l) % 2 != 0 ? -Ar[j].x : Ar[j].x;
	}
	cout << res << endl;
 }

  return 0;
}
