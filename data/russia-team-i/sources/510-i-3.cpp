#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 10;
int a[N];

int main()
{
    freopen("sochi.in", "rt", stdin);
    freopen("sochi.out", "w", stdout);

    int i, j, n;

    int d;

    cin >> n >> d;

    for (i = 0; i < n; i++)
        scanf(" %d", &a[i]);

    sort(a, a + n);

    i = n - 1;

    int len = 0;

    len += a[i];
    i--;

    bool flag = true;

    if (len < 3 * d)
        flag = false;

    while (i >= 0 && a[i] >= 3 * d)
    {
        len += a[i] - 2 * d;
        i--;
    }

    for (j = 0; j < 2; j++)
        if (i >= 0 && a[i] >= 2 * d)
        {
            if (j == 1 && (!flag))
                continue;

            len += a[i] - 2 * d;
            i--;
        }

    cout << len << endl;

    return 0;
}
