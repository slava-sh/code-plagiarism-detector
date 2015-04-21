#include <iostream>

using namespace std;

int a[100002];

int main()
{
    int n, ans = 1, q, p, c;
    cin >> n;
    cin >> a[1];
    a[0] = a[n + 1] = 2e9;
    for (int i = 2; i <= n; ++i)
        (cin >> a[i]), ans += a[i] != a[i - 1];
    cin >> q;
    while (q--)
    {
        cin >> p >> c;
        ans += a[p] == a[p - 1];
        ans += a[p] == a[p + 1];
        a[p] = c;
        ans -= a[p] == a[p - 1];
        ans -= a[p] == a[p + 1];
        cout << ans << '\n';
    }
    return 0;
}
