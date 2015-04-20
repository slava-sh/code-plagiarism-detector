#include <iostream>
#include <stdio.h>

using namespace std;

const int N = (int)3e5 + 10;

int d[N];

int main()
{
    freopen("che.in", "rt", stdin);
   freopen("che.out", "w", stdout);

    int n, R;

    cin >> n >> R;

    int i, j;

    for (i = 1; i <= n; i++)
        scanf(" %d", &d[i]);

    long long res = 0;

    int l = 1;

    int r = 1;

    while ((r != n) || (d[r] - d[l] > R))
    {
        while ((r != n) && (d[r] - d[l] <= R))
            r++;

        if (d[r] - d[l] > R)
             res += (long long)(n - r + 1);

        l++;
    }

    cout << res << endl;

    return 0;
}
