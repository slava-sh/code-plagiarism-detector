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
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n, d;
    long long current_length = 0;

    cin >> n >> d;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    if(a[n - 1] <= d)
    {
        cout << a[n - 1] << endl;
        return 0;
    }
    current_length = a[n - 1] - d;
    int last = 0;

    for(int i = n - 2; i > 0; --i)
    {
        if(a[i] < 3 * d)
        {
            last = i;
            break;
        } else {
            current_length += a[i] - 2 * d;
        }
    }

    if(a[last] > d)
    {
        current_length += a[last] - d;
    }

    cout << current_length << endl;

    return 0;
}
