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

int main()
{
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
//    ios_base::sync_with_stdio(false);

    long long n, r, a[300010];
    cin >> n >> r;
    for (long long i = 0; i < n; ++i)
        cin >> a[i];
    long long kol = 0;
    long long i = 0, j = 1;
    while (i < n)
    {
        while (j < n && a[j]-a[i] <= r)
            ++j;
        if (j == n)
            break;
        kol += (n-j);
        ++i;
    }
    cout << kol << endl;
    return 0;
}
