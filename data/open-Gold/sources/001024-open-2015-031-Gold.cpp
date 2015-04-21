#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <map>
#include <stdlib.h>

using namespace std;

const long long inf = 1E9;

long long d[3010][3010];
long long a[3010];
long long b[3010];

long long prev(long long k, long long K)
{
    if (k == 1) return K;
    return k - 1;
}

long long need (long long k)
{
    if (k == 1) return 1;
    return 0;
}

int main()
{
    long long n, K, C, D;
    cin >> n >> K >> C >> D;
    for (long long i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
    }
    for (long long i = 0; i <= n; ++i)
    {
        for (long long j = 0; j <= K; ++j)
        {
            d[i][j] = inf;
        }
    }
    d[0][K] = -C;

    b[0] = -inf;

    long long mn;
    for (long long i = 1; i <= n; ++i)
    {
        mn = inf;
        for (long long k = 1; k <= K; ++k)
        {
            long long gap = a[i] - b[i - 1];
            long long len = b[i] - a[i];
            d[i][k] = min(d[i - 1][k] + D * (gap + len),
                          d[i - 1][prev(k, K)] + need(k) * C + D * len);
            mn = min(mn, d[i][k]);
            //cout << i << ' ' << k << ' ' << d[i][k] << '\n';
        }
    }

    cout << mn;

    return 0;
}
