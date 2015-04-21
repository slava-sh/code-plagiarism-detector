#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <queue>
#include <sstream>
#define mp make_pair
#define fs first
#define sc second
#define x first
#define y second

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 300001;
vector <pair <ll, ll> > a[MAXN];
ll h[MAXN];
int id[MAXN];
int l[MAXN];

bool cmp(int id1, int id2)
{
	return h[id1] < h[id2];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	ll ta, tb;
	scanf("%lld%lld", &ta, &tb);
	scanf("%d", &n);	
	for (int i = 0; i < n; i++)
	{
		h[i] = 0;
		scanf("%d", &l[i]);
		l[i]++;
		a[i].resize(l[i]);
		for (int j = 0; j < l[i]; j++)
		{
			scanf("%lld%lld", &a[i][j].x, &a[i][j].y);
			if (j != 0)
			{
				h[i] += (a[i][j].x - a[i][j - 1].x) * (a[i][j].y + a[i][j - 1].y);
			}
		}
		id[i] = i;
	}
	sort(id, id + n, cmp);
	for (int i = 0; i + 1 < n; i++)
	{
		int vd = id[i], vu = id[i + 1];
		int pd = 0, pu = 0;
		bool ok = true;
		while ((pd < l[vd]) && (pu < l[vu]))
		{
			if (a[vd][pd].x == a[vu][pu].x)
			{
				ok = ok && (a[vd][pd].y <= a[vu][pu].y);
				pd++, pu++;
			}
			else if (a[vd][pd].x < a[vu][pu].x)
			{
				ok = ok && (a[vd][pd].y * (a[vu][pu].x - a[vu][pu - 1].x) <= 
					a[vu][pu].y * (a[vd][pd].x - a[vu][pu - 1].x) + a[vu][pu - 1].y * (a[vu][pu].x - a[vd][pd].x));
				pd++;
			}
			else
			{
				ok = ok && (a[vu][pu].y * (a[vd][pd].x - a[vd][pd - 1].x) >= 
					a[vd][pd].y * (a[vu][pu].x - a[vd][pd - 1].x) + a[vd][pd - 1].y * (a[vd][pd].x - a[vu][pu].x));
				pu++;
			}
		}
		if (!ok)
		{
			cout << "No" << endl;
			cout << vd + 1 << " " << vu + 1 << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}