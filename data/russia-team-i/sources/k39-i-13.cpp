#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define sc scanf
#define pr printf
#define fi first
#define se second
#define mk make_pair
#define pb push_back

int used[300002], a[300002];
vector <int> vec;

int cmp (int a, int b)
{
    return a > b;
}
int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    freopen ("sochi.in", "r", stdin);freopen ("sochi.out", "w", stdout);
    int n, d, i, j, k = 0, l, m, ans = 0, mx = 0;
    cin >> n >> d;
    for (i = 1; i <= n; i++)
    {
        cin >> l;
        mx = max (l, mx);
        a[i] = l - 2 * d;
    }
    sort (a + 1, a + n + 1);
    for (i = n; i >= 1; i--)
        if (a[i] >= d)
            ans += a[i], used[i] = 1, k++;
        else
            break;
    for (i = 1; i <= n; i++)
        if (!used[i] && a[i] + d >= 1)
            vec.pb (a[i] + d);
    sort (vec.begin(), vec.end(), cmp);
    if (vec.size() >= 2)
    {
        if (k == 0)
            cout << max (mx, vec[0] + vec[1]) << endl;
        else
            cout << max (mx, vec[0] + vec[1] + ans) << endl;
        return 0;
    }
    if (vec.size() == 1)
    {
        if (k == 0)
            cout << max (mx, vec[0] + d) << endl;
        else
            cout << max (mx, vec[0] + ans + d);
        return 0;
    }
    if (k == 0)
        cout << mx;
    else
        cout << max (mx, ans + 2 * d);
}
