#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int ans, a, b;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    if (a == 1 && b >= 3) {
        ans = 1 + ((b - 3) / 4);
    }
    if (a >= 3)
        ans = 1;
    cout << ans;
    return 0;
}
