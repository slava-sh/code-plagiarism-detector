#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1<<30

using namespace std;

const int N = 111111;

int n, k;
int a[N];

bool checkVal(int x)
{
    int painted = a[0];
    for(int i = 1; i<n; i++)
    {
        if (a[i] < x)
            return false;
        if (k - painted < x)
            return false;
        painted += max(x, a[i]-painted);
    }
    return true;
}

int main()
{
    #define TASKNAME "fence"

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d%d", &n, &k);

    int l = 0;
    int r = INF;

    for(int i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
        r = min(r, a[i]);
    }

    sort(a, a+n);

    while (l < r)
    {
        int m = (l+r+1)/2;
        if (checkVal(m))
        {
            l = m;
        }
        else
        {
            r = m-1;
        }
    }

    printf("%d", l);

    return 0;
}
