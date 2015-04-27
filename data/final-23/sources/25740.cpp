#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>

#define mp make_pair
#define f first
#define s second
#define pb push_back

using namespace std;

typedef long long lglg;
typedef double db;

const int inf = 1<<30, N = 131072, NN = 262145;

int ax[] = {0, 1, -1, 0, 0};
int ay[] = {0, 0, 0, -1, 1};

int n, m, a[NN];

int main()
{
    //freopen("input.txt","r",stdin);
    freopen("signchange.in","r",stdin);
    freopen("signchange.out","w",stdout);
    cin>> n;
    memset(a, 0, sizeof(a));
    int i;
    for (i=N; i<N+n; i++)
        scanf("%d", &a[i]);
    for (i=N-1; i>=1; i--)
        if (2*i+1 < N)
            a[i] = a[2*i] + a[2*i+1];
        else
            a[i] = a[2*i] - a[2*i+1];
    cin>> m;
    int com, x, q, res, l, r;
    for (i=1; i<=m; i++)
    {
        scanf("%d", &com);
        if (com == 0)
        {
            scanf("%d%d", &l, &r);
            a[l+N-1] = r;
            x = l+N-1;
            while (x > 1)
            {
                x /= 2;
                if (2*x+1 < N)
                a[x] = a[2*x] + a[2*x+1];
                    else
                a[x] = a[2*x] - a[2*x+1];
            }
        }
        else
        {
            scanf("%d%d", &l, &r);
            l += N-1;
            r += N-1;
            res = 0;
            q = l;
            while (r >= l)
            {
                if (l & 1)
                {
                    if (l < N)
                        if (q % 2 == 0)
                            res += a[l];
                        else
                            res -= a[l];
                    else
                        if ((l - q) % 2 == 0)
                            res += a[l];
                        else
                            res -= a[l];
                    l++;
                   // cout<< l;
                }
                if (!(r & 1))
                {
                    if (l < N)
                        if (q % 2 == 0)
                            res += a[r];
                        else
                            res -= a[r];
                    else
                    if ((r - q) % 2 == 0)
                        res += a[r];
                    else
                        res -= a[r];
                    r--;
                }
                l /= 2;
                r /= 2;

            }
            printf("%d\n", res);

        }

    }
    return 0;

}
