#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int a, b;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin >> a >> b;
    int x = min(a, b);
    int ans = 0;
    if (x >= 3)
        ans++;
    x-=3;
    ans += (x / 4);
    cout << ans;
    return 0;
}
