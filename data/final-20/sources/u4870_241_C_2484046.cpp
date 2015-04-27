#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;

const int W = 100000;
const int H = 100;
const int MAXN = 110;
const double eps = 1e-12;

struct sMirror
{
	int v, a, b;
	string st;
};

int hl, hr, n;
sMirror mm[MAXN];
bool chkd[MAXN];

int Find(int it, double x)
{
	for (int i = 0; i < n; i ++)
	{  
		if ((it % 2 == 0) && mm[i].st == "T")  continue;
		if ((it % 2 != 0) && mm[i].st == "F")  continue;
		if (mm[i].a < x + eps && x < mm[i].b + eps)  return i;
	}
	return -1;
}

int Work()
{
	int ans = 0, res, hhr;
	for (int ii = -100; ii <= 100; ii ++)
	{
		if (ii == 0)  continue;
		hhr = H * ii + ((ii % 2 == 0)? hr: H - hr);
		res = 0;
		memset(chkd, false, sizeof(chkd));
		for (int i = (ii > 0); i != ii + (i > 0); i += ((ii >= i)? 1: -1))
		{
			double x = W * (i * H - hl) / (hhr - hl);
			int z = Find(i, x);
			if (z < 0 || chkd[z])
			{
				res = 0;
				break;
			}
			chkd[z] = true;
			res += mm[z].v;
		}
		ans = max(ans, res);
	}
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	cin.sync_with_stdio(false);
	cin >> hl >> hr >> n;
	for (int i = 0; i < n; i ++)
		cin >> mm[i].v >> mm[i].st >> mm[i].a >> mm[i].b;

	cout << Work() << endl;

	return 0;
}