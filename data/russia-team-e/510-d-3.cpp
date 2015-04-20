#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 10;
int a[N];

int k;
int n;

bool check(int x)
{
    int i, j;

    int len = 0;

    for (i = 0; i < n; i++)
    {
        if (k - len < x)
            return false;

        len = max(a[i], len + x);
    }

    return true;
}

int main()
{
    freopen("fence.in", "rt", stdin);
    freopen("fence.out", "w", stdout);


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

        if (check(mid))
            left = mid;
        else
            right = mid;
    }

    cout << left << endl;

    return 0;
}
