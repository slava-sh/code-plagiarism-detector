#include<iostream>
#include<cstdio>
#include<complex>
#include<utility>
using namespace std;
typedef complex<double> point;
const int maxn = 200;

int hl, hr, n;
int dat[maxn][4];

double cross(point base, point x, point y)
{
	x -= base; y -= base;
	return (x * conj(y)).imag();
}
bool intersect(point ax, point ay, point bx, point by)
{
	return (cross(ax, ay, bx) * cross(ax, ay, by) <= 0 && cross(bx, by, ax) * cross(bx, by, ay) <= 0);
}
point makepoint(double x, double y)
{
	return complex<double>(x, y);
}

int checkpoints(int cnt)
{
	point start = makepoint(0, hl);
	point dest;
	if (cnt & 1) dest = makepoint(100000, (cnt + 1) * 100 - hr);
	else dest = makepoint(100000, cnt * 100 + hr);
	static bool used[maxn];
	int ret = 0;
	for (int i = 0; i < n; i++) used[i] = false;
	for (int i = 0; i < cnt; i++)
	{
		int y;
		if (i & 1) y = (i + 1) * 100;
		else y = (i + 1) * 100;
		bool found = false;
		for (int j = 0; j < n; j++)
		{
			if (dat[j][3] && !(i & 1)) continue;
			if (!dat[j][3] && (i & 1)) continue;
			if (intersect(start, dest, makepoint(dat[j][1], y), makepoint(dat[j][2], y)))
				if (used[j]) return 0;
				else
				{
					ret += dat[j][0];
					used[j] = true;
					found = true;
					break;
				}
		}
		if (!found) return 0;
	}

	return ret;
}

void reverse()
{
	for (int i = 0; i < n; i++) dat[i][3] = !dat[i][3];
	hl = 100 - hl; hr = 100 - hr;
}

void init()
{
	scanf("%d%d%d", &hl, &hr, &n);
	static char str[10];
	for (int i = 0; i < n; i++)
	{
		scanf("%d%s%d%d", &dat[i][0], str, &dat[i][1], &dat[i][2]);
		if (str[0] == 'T') dat[i][3] = 0; else dat[i][3] = 1;
	}
}
void work()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, checkpoints(i));
		reverse();
		ans = max(ans, checkpoints(i));
		reverse();
	}
	printf("%d\n", ans);
}
int main()
{
	//freopen("sample2.in", "r", stdin);
	init();
	work();
	return 0;
}
