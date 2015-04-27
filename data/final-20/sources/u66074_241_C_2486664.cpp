#include <iostream>
#include <cstring>
#include <string>
using std::cin;
using std::cout;
using std::endl;
const int maxm = 100005;
const int maxn = 105;
int hl, hr, n, ans;
int ce[maxm], fl[maxm], v[maxn], la[maxn], ra[maxn];
bool b[maxn];

void find_path(int p,int h1,int h2,int* x, int* y)
{
	int toth = (p-1)*100+h1+h2;
	memset(b, false, sizeof(b));
	int *t;
	int lh = h1, wi;
	int tot = 0;
	for (int ii = 1; ii <= p; ++ii)
	{
		wi = (lh * 100000)/toth;
		int tp = wi;
		if (x[tp] && la[x[tp]]<=tp &&  ra[x[tp]] >= tp) {
			if (b[x[tp]]) return;
			tot += v[x[tp]];
			b[x[tp]] = true;
		}
		else return;
		t = x; x = y; y = t;
		lh +=100;
	}
	if (tot > ans) ans = tot;
}
int main()
{
	cin >> hl >> hr >> n;
	memset(ce, 0, sizeof(ce));
	memset(fl, 0, sizeof(fl));
	int tl, tr;
	std::string ci;
	for (int i = 1; i <= n; ++i)
	{
		cin >> v[i] >> ci >> tl >> tr;
		la[i] = tl; ra[i] = tr;
		if (ci[0] == 'T') 
		{
			for (int j = tl; j <= tr; ++j)
				ce[j] = i;
		}
		else 
			for (int j = tl; j <= tr; ++j)
 				fl[j] = i;
	}
	ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i&1) find_path(i, hl, hr, fl, ce);
		else find_path(i, hl, 100-hr, fl, ce);

		if (i&1) find_path(i, 100-hl, 100-hr, ce, fl);
		else find_path(i, 100-hl, hr, ce, fl);

	}
	cout << ans << endl;
}

