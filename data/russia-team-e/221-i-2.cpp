#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1<<30

using namespace std;

const int N = 111111;

int n, d;
int a[N];


int main()
{
    #define TASKNAME "sochi"

    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        freopen(TASKNAME".in", "r", stdin);
        freopen(TASKNAME".out", "w", stdout);
    #endif // DEUBG

    scanf("%d%d", &n, &d);
    vector<int> v;

    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);

    sort(a, a+n);

    int res = -1;
    int lastD = INF;

    for(int i = n-1; i>=0; i--)
    {
        if (a[i] > 2*d)
        {
            if (res == -1)
                res = a[i];
            else
                res += a[i] - d*2;

            if (a[i] - 2*d < d)
            {
                if (i > 0 && a[i-1] > 2*d)
                    res += a[i-1] - 2*d;
                break;
            }
        }
    }

    if (res == -1)
        res = a[n-1];

    printf("%d", res);

    return 0;
}
