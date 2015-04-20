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
const int N = (int)5005 + 7;
const int INF = 2e9 + 5;

ll a[N];
int n, m;

bool check(int x)
{
    ll cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (m - cur < x)
            return false;
        cur = max(cur + x, a[i]);
    }

    return true;
}

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);

    ll r = INF;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        r = min(r, a[i]);
    }

    sort(a, a + n);

    int l = 0;
    r++;
    while (l + 1 < r)
    {
        int md = (l + r) / 2;
        if (check(md))
            l = md;
        else
            r = md;
    }

    cout << l << endl;

    return 0;
}
