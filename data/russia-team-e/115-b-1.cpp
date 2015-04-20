#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    long long n, r;
    cin >> n >> r;
    long long d[n + 2];
    for (long long i = 1; i <= n; ++i)
        cin >> d[i];
    d[0] = -100000;
    d[n + 1] = 100000;
    long long ans = 0;
    for (long long i = 1; i <= n; ++i)
    {
        //cerr << i;
        long long l = 0, r = i;
        while (r - l > 1)
        {
            long long mid = (l + r) /2;
            if (d[i] - d[mid] > r)
                r = mid;
            else
                l = mid;
        }
        if (d[i] - d[r] > r)
            ans += r;
        //cerr << " " << r << " ";
        l = i;
        r = n + 1;
        while (r - l > 1)
        {
            long long mid = (l + r) / 2;
            if (d[mid] - d[i] > r)
                l = mid;
            else
                r = mid;
        }
        //cout << l << endl;
        if (d[l] - d[i] > r)
            ans += n - l + 1;
    }
    cout << ans << endl;
    return 0;
}
