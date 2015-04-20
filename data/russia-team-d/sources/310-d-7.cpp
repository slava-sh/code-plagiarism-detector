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
int n, k;
int min_a = INT_MAX;

bool isOK(int x)
{
    return (max(a[n - 1], min_a + (n - 1) * x) <= k);
}

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    ios_base::sync_with_stdio(false);

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
        cout << a[0] << endl;
        return 0;
    }

//    int l = 0;
//    int r = a[0];
//    while(l < r)
//    {
//        int m = (l+r+1) / 2;
//        if(isOK(m))
//            l = m;
//        else
//            r = m-1;
//    }
//    cout << l << endl;

    int x = min(min_a, (k - min_a) / (n - 1));
    x = min(x, k / n);
    int current_sum = 0;
    int num = 0, sum = 0;
    int i = 0;
    while ((i < n) && (x > 0))
    {
        if(current_sum + x <= k)
        {
            current_sum = current_sum + x;
            if (a[i] > current_sum)
            {
                current_sum = a[i];
            }
            ++i;
        } else {
            --x;
            i = 0;
            current_sum = 0;
        }
    }

    cout << ((x < 0) ? 0 : x) << endl;

    return 0;
}
