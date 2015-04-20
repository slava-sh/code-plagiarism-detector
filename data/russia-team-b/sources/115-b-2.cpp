#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    long long n, R;
    cin >> n >> R;
    long long d[n];
    for (long long i = 0; i < n; ++i)
        cin >> d[i];
    long long ans = 0;
    for (long long i = 0; i < n; ++i)
    {
        //cerr << i;
        long long l = 0, r = i;
        while (r - l > 1)
        {
            long long mid = (l + r) /2;
            if (d[i] - d[mid] <= R)
                r = mid;
            else
                l = mid;
        }
        if (d[i] - d[l] > R)
        {
            ans += l + 1;
            //cerr << " +1 ";
        }
        //cerr << " " << l << " ";
        l = i;
        r = n - 1;
        while (r - l > 1)
        {
            long long mid = (l + r) / 2;
            if (d[mid] - d[i] <= R)
                l = mid;
            else
                r = mid;
        }
        //cout << r;
        if (d[r] - d[i] > R)
        {
            ans += n - r;
            //cerr << " +2";
        }
        //cerr << endl;
    }
    cout << ans / 2 << endl;
    return 0;
}
