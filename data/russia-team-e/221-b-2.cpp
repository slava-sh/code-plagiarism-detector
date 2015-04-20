#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

#define INF 1<<30

using namespace std;

const int N = 333333;

int n, r;
int a[N];

int getL(int ind, int dist)
{
    int l = ind;
    int r = n-1;
    if (l > r)
        return n;

    while (l<r)
    {
        int m = (l+r)/2;
        if (a[m] > dist)
        {
            r = m;
        }
        else
        {
            l = m+1;
        }
    }
    if (a[l] <= dist)
        return n;
    return l;
}

int main()
{
    #define TASKNAME "che"

    #ifndef DEUBG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d%d", &n, &r);

    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }

    int res = 0;

    for(int i = 0; i<n; i++)
    {
        int ind = getL(i, a[i]+r);
        res += n - ind;
    }

    printf("%d", res);
    return 0;
}
