#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;


char str[240000];
char cp = 1;
int p[480000];
inline char &gogo(int p)
{   if (p & 1)
        return cp;
    else
        return str[p / 2]; }

void center()
{   gets(str + 1);
    int n;
    for (n = 0; str[n + 1]; n++);
    for (int i = 1; i <= n; i++)
        str[n + i] = str[i];
    str[n * 2 + 1] = 0;
    int rp = 0, r = -1;
    for (int i = 2; i < 4 * n; i++)
    {   if (i < r)
            p[i] = min(p[rp - (i - rp)], r - i);
        else
            p[i] = 0;
        while (gogo(i - p[i]) == gogo(i + p[i]))
            p[i]++;
        if (i + p[i] - 1 > r)
            r = i + p[i] - 1, rp = i;
        if (!(i & 1) && (n & 1) && p[i] >= n)
        {   printf("%d\n", ((i / 2) - ((n + 1) / 2) + n) % n);
            return; }
        if ((i & 1) && !(n & 1) && p[i] >= n)
        {   printf("%d\n", ((i / 2) - (n / 2) + n) % n);
            return; } }
    printf("-1\n"); }

int main()
{   freopen("inventory.in", "rt", stdin);
    freopen("inventory.out", "wt", stdout);
    int n;
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        center();

    return 0; }
