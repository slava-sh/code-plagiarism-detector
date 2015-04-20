#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("prizes.in", "rt", stdin);
    freopen("prizes.out", "w", stdout);

    int n, m;

    int temp;

    cin >> n >> m;

    if (m == 1)
    {
        cout << ((n + 1) / 4) << endl;
        return 0;
    }

    if (n == 1)
    {
        cout << ((m + 1) / 4) << endl;
        return 0;
    }

    if (n < m)
    {
            temp = m;
            m = n;
            n = temp;
    }

    cout << ((m + 1) / 4) << endl;

    return 0;
}
