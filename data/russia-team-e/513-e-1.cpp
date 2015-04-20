#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

#define FNAME "numbers"
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < n; i++)

int n, m, k, c1, c2, boo, used[1005], x, y;
vector <bool> used1[1005];
char s[100];
int f(int l, int r)
{
	int ans = 0;
	for (int i = l; i < r; i++)
		ans = ans * 10 + s[i] - '0';
	return ans;
}

void f1(int l)
{
	if (11 - l == 3)
		printf("%c%c%c", s[l], s[l + 1], s[l + 2]);
	if (11 - l == 4)
		printf("%c%c-%c%c", s[l], s[l + 1], s[l + 2], s[l + 3]);
	if (11 - l == 5)
		printf("%c%c%c-%c%c", s[l], s[l + 1], s[l + 2], s[l + 3], s[l + 4]);
	if (11 - l == 6)
		printf("%c%c-%c%c-%c%c", s[l], s[l + 1], s[l + 2], s[l + 3], s[l + 4], s[l + 5]);
	if (11 - l == 7)
		printf("%c%c%c-%c%c-%c%c", s[l], s[l + 1], s[l + 2], s[l + 3], s[l + 4], s[l + 5], s[l + 6]);

}
int main()
{
	forn(i, 1000)
		used1[i].resize(100005);
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	scanf("%d", &n);
	forn(i, n)
	{		
		scanf("%d%d", &x, &m);
		used[x] = 1;
		forn(j, m)
		{
			scanf("%d", &y);
			used1[x][y] = 1;
		}
	}
	scanf("%d\n", &k);
	forn(q, k)
	{
		gets(s);
		boo = 0;
		for (int i = 1; i <= 3; i++)
		{
			c1 = f(0, i);
			if (boo)
				break;
			if (used[c1] && s[i] != '0' && s[0] != '0')
			{
				for (int j = 3; j <= 5; j++)
				{
					c2 = f(i, i + j);
					if (used1[c1][c2] && s[i + j] != '0')
					{
						boo = 1;
						printf("+");
						forn(t, i)
							printf("%c", s[t]);
						printf("(");
						for (int t = i; t < i + j; t++)
							printf("%c", s[t]);
						printf(")");
						f1(i + j);
						puts("");
						break;
					}
				}

            }
		}
		if (!boo)
			puts("Incorrect");		
	}
	return 0;
}