#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <queue>
#include <vector>

using namespace std;

long long a[100010];

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    long long n, d, ot;

    cin >> n >> d;
    for (long long i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    long long i = n-2;
    ot = a[n-1];
    while (i >= 0)
    {
        if (a[i+1] >= 2*d && a[i] > 2*d)
        {
            ot += (a[i]-d-d);
            a[i+1] -= d;
            a[i] -= d;
        }
        else
            break;
        --i;
    }
    if (i >= 0)
    {
        if (a[n-1] >= 2*d && a[i] > 2*d)
            ot += (a[i]-d-d);
    }
    cout << ot << endl;
    return 0;
}
