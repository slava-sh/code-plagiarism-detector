#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

char s[200100];
char t[200100];
LL p1[200100];
LL p2[200100];
int fi[30];

int mod1 = 1000000007;
int mod2;
LL hs1[26][200100];
LL hs2[26][200100];
LL ht1[26][200100];
LL ht2[26][200100];
int cnt1[26];
vector<int> ans;
int who[26];


int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	double beg = clock();
#endif

	srand(time(NULL));
	mod2 = rand() % 160;
	mod2 += 1000000000;
	p1[0] = p2[0] = 1;
	FOR(i, 1, 200100)
	{
		p1[i] = (p1[i - 1] * 5) % mod1;
		p2[i] = (p2[i - 1] * 5) % mod2;
	}
	int n, m;
	scanf("%d%d%s%s", &n, &m,s,t);
	MEMS(fi, -1);
	FOR(i, 0, m)
	{
		int c = t[i] - 'a';
		if (fi[c] == -1)
		{
			fi[c] = i;
		}
	}
	FOR(c, 0, 26)
	{
		FOR(i, 0, n)
		{
			if (i)
			{
				hs1[c][i] = hs1[c][i - 1];
				hs2[c][i] = hs2[c][i - 1];
			}
			if (s[i] - 'a' == c)
			{
				hs1[c][i] += p1[i] * 3;
				hs2[c][i] += p2[i] * 3;
			}
			else
			{
				hs1[c][i] += p1[i] * 2;
				hs2[c][i] += p2[i] * 2;
			}
			hs1[c][i] %= mod1;
			hs2[c][i] %= mod2;
		}
	}

	FOR(c, 0, 26)
	{
		FOR(i, 0, m)
		{
			if (i)
			{
				ht1[c][i] = ht1[c][i - 1];
				ht2[c][i] = ht2[c][i - 1];
			}
			if (t[i] - 'a' == c)
			{
				ht1[c][i] += p1[i] * 3;
				ht2[c][i] += p2[i] * 3;
			}
			else
			{
				ht1[c][i] += p1[i] * 2;
				ht2[c][i] += p2[i] * 2;
			}
			ht1[c][i] %= mod1;
			ht2[c][i] %= mod2;
		}
	}
	for (int st = 0; st + m <= n; ++st)
	{
		MEMS(cnt1, 0);
		FOR(i, 0, 26)
		{
			who[i] = -1;
		}
		FOR(i, 0, 26)
		{
			if (fi[i] == -1)
				continue;
			cnt1[s[st + fi[i]] - 'a']++;
			who[i] = s[st + fi[i]] - 'a';
		}
		bool f = true;
		FOR(i, 0, 26)
		{
			int w = who[i];
			if (w == -1)
				continue;
			if ((who[w] != -1) && (who[w] != i))
			{
				f = false;
				break;
			}
		}
		if (!f)
			continue;
		FOR(i, 0, 26)
		{
			int w = who[i];
			if (w == -1)
				continue;
			LL HT1 = ht1[i][m - 1]*p1[st];
			HT1 %= mod1;
			LL HT2 = ht2[i][m - 1] * p2[st];
			HT2 %= mod2;
			LL HS1 = hs1[w][st + m - 1];
			if (st)
				HS1 -= hs1[w][st - 1];
			if (HS1 < 0)
				HS1 += mod1;
			LL HS2 = hs2[w][st + m - 1];
			if (st)
				HS2 -= hs2[w][st - 1];
			if (HS2 < 0)
				HS2 += mod2;
			if ((HS1 != HT1) || (HS2 != HT2))
			{
				f = false;
				break;
			}
		}
		if (f)
		{
			ans.push_back(st);
		}
	}
	printf("%d\n", ans.size());
	FOR(i, 0, ans.size())
	{
		if (i)
			printf(" ");
		printf("%d", ans[i]+1);
	}
	printf("\n");

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}