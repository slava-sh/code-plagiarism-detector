#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define sc scanf
#define pr printf
#define fi first
#define se second
#define mk make_pair
#define pb push_back

int d[300002];

int main()
{
    //freopen ("in.txt", "r", stdin);freopen ("out.txt", "w", stdout);
    freopen ("fence.in", "r", stdin);freopen ("fence.out", "w", stdout);
    int n, k, l = 1000000002, i;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
        cin >> d[i];
    sort (d + 1, d + n + 1);
    if (n == 1)
    {
        cout << d[1];
        return 0;
    }
    cout << min (d[1], (k - d[1]) / (n - 1));
}
