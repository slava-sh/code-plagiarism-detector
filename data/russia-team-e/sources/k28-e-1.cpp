#include<cstdlib>
#include<cstdio>
#include<stdio.h>
#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "numbers"

using namespace std;

int n, i, a[10000], k, b[1000000], cnt, c, m, x, j, y;
bool was[10000];
char s[20];

void go()	{
	printf("Incorrect\n");
}

void fi(int z)  {
    printf("+%d", x);
    printf("(%d)", y);
    if (z == 3)
        printf("%c%c%c", s[9], s[10], s[11]);
    if (z == 4)
        printf("%c%c-%c%c", s[8], s[9], s[10], s[11]);
    if (z == 5)
        printf("%c%c%c-%c%c", s[7], s[8], s[9], s[10], s[11]);
    if (z == 6)
        printf("%c%c-%c%c-%c%c", s[6], s[7], s[8], s[9], s[10], s[11]);
    if (z == 7)
        printf("%c%c%c-%c%c-%c%c", s[5], s[6], s[7], s[8], s[9], s[10], s[11]);
    printf("\n");
}

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);
	scanf("%d\n", &n);
	for (i = 1; i <= n; i++)	{
		scanf("%d%d\n", &c, &k);
		was[c] = true;
		a[k] = ++cnt;
		for (j = 1; j <= k; j++)    {
			scanf("%d\n", &x);
			b[x] = c;
		}
	}
	scanf("%d\n", &m);
	for (i = 1; i <= m; i++)	{
		scanf("%s", s + 1);
		cnt = 0;
		x = 0;
		while(cnt != 3)	{
			x *= 10;
			x += s[++cnt] - 48;
            y = 0;
            if (was[x])
                for (j = 1; j <= 5; j++)    {
                    y *= 10;
                    y += s[cnt + j] - 48;
                    if (b[y] == x && s[cnt + j + 1] != '0')  {
                        fi(11 - cnt - j);
                        goto w;
                    }
                }
		}
		go();
		w:;
	}
	return 0;
}

