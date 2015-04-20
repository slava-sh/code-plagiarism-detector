#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <queue>

#define x first
#define y second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = (int)(1e5) + 7;

int a[N];
bool b[N];

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int x = n - 1;
    while (x >= 0 && a[x] >= 3 * r)
        --x;
    int res = 0, cnt = 0;
    while (x > -1 && a[x] >= r * 2)
    {
        if (cnt < 2)
        {
            res += a[x] - r;
            b[x] = 1;
            cnt++;
        }
        else
            break;
        --x;
    }
    for (int i = 0; i < n; ++i)
        if (cnt < 2 && a[i] >= r * 2 && !b[i])
        {
            b[i] = 1;
            cnt++;
            res += a[i] - r;
        }
    for (int i = 0; i < n; ++i)
        if (a[i] >= r * 3 && !b[i])
        {
            b[i] = 1;
            res += a[i] - (r * 2);
        }
    cout << max(a[n - 1], res) << endl;
    return 0;
}
