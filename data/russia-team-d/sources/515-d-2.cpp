#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int SZ = 1e5 + 100;

int a[SZ];
int n, k;

bool test(int m)
{
    int last = a[0] - 1;

    for (int i = 1; i < n; i++)
    {
        int start = max(0, last - (a[i] - m));
        last = start + a[i];
    }
    return last <= k;
}


int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 0, r = a[0] + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (test(m))
        {
            l = m;
        }
        else
        {
            r = m;
        }
    }
    cout << l << endl;

    return 0;
}
