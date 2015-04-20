#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const long long SZ = 1e5 + 100;

long long a[SZ];
long long n, k;

bool test(long long m)
{
    long long last = a[0];
    for (long long i = 1; i < n; i++)
    {
        long long start = max(0, last - (a[i] - m));
        last = start + a[i];
    }
    return last <= k;
}


int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> n >> k;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    long long l = 0, r = a[0] + 1;
    while (r - l > 1)
    {
        long long m = (l + r) / 2;
        if (test(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << endl;

    return 0;
}
