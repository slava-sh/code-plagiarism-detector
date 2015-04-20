#include <bits/stdc++.h>

#define ll long long
#define fn "prizes"

using namespace std;

const int MXN = 1e5 + 9;
const int INF = 1e9 + 9;

int n, m;

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    cin >> n >> m;
    if (m == 1 && n == 1)
        cout << 0;
    else if (m == 1 || n == 1)
        cout << max(n, m) / 3;
    else
    {
        if (min(n, m) / 3 > 0) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    return 0;
}
