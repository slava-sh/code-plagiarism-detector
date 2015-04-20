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

int a[100000];

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n, k;
    int min_a = INT_MAX;
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if(a[i] < min_a)
        {
            min_a = a[i];
        }
    }

    sort(a, a + n);

    if(n == 1)
    {
        cout << k << endl;
        return 0;
    }

    int x = min(min_a, (k - min_a) / (n - 1));
    x = min(x, k / n);
    int current_sum = 0;

    for(int i = 0; i < n; ++i)
    {
        if(current_sum + x <= k)
        {
            current_sum = max(current_sum + x, a[i]);
        } else {
            --x;
            --i;
        }
    }

    cout << x << endl;

    return 0;
}
