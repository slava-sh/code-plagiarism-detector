#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int Q = int(1e3) + 10;

long long n, sum, t[Q], sumr;
pair <int, int> a[Q];

int main()
{
    freopen("conquest.in", "r", stdin);
    freopen("conquest.out", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        sum += x;
        a[i] = make_pair(x, y);
    }
    sort(a, a + n);
    sum -= a[n - 1].first;
    for(int i = n - 1; i >= 0; i--)
    {
        if((sum + sumr) <= a[i].first)
        {
            t[i] = (a[i].first - (sum + sumr)) / 2 + 1;
          //  cout << t[i] << " " << sum << "\n";
        }
        if(i > 0)
          sum -= a[i - 1].first;
        sumr += t[i];
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {

        ans += t[i] * a[i].second;
    }
    cout << ans;
    return 0;
}
