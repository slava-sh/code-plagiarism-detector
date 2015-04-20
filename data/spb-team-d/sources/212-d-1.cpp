#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int l[1000], r[1000], x[1000];

int main()
{
    freopen("dunes.in", "r", stdin);
    freopen("dunes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i] >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        int d, ans = 0;
        cin >> d;
        for (int i = 0; i < n; i++)
        {
            if (l[i] <= d && d <= r[i])
            {
                if ((d - l[i]) % 2 == 0)
                {
                    ans += x[i];
                }
                else
                {
                    ans -= x[i];
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
