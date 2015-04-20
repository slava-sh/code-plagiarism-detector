#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 10;
int a[N];

int main()
{
    freopen("fence.in", "rt", stdin);
    freopen("fence.out", "w", stdout);

    int n, k;

    int i, j;

    cin >> n >> k;

    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);

    sort(a, a + n);

    int left = 0, right = min(a[0] + 1, k + 1);
    int mid;

    while (right - left > 1)
    {
        mid = (right + left) / 2;

        if ((a[0] + (n - 1) * mid) <= k)
            left = mid;
        else
            right = mid;
    }

    cout << left << endl;

    return 0;
}
