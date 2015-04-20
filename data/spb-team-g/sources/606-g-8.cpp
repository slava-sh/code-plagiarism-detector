#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("merlin.in", "r", stdin);
    freopen("merlin.out", "w", stdout);
    long long n;
    cin >> n;
    long long ss = 0;
    long long a[n], s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        ss+= a[i];
        s[i] = ss;
    }
    if (ss == n * a[n - 1])
    {cout << 0; return 0;}
    long long ans = 0;
    long long sl = 0;
    for (long long i = n - 1; i > -1; i--)
    {
        ss -= a[i];
        sl += a[i];
        ans ++;
        if (a[i - 1] * (i-1) <= sl + s[i - 2])
        {
            cout << ans;
            return 0;
        }
    }
    return 0;
}
