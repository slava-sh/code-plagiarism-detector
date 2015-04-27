#include <iostream>

using namespace std;

double a[128];

int main()
{
    int n;
    cin >> n;

    for (int i=0; i<=n; i++)
        cin >> a[i];

    double res = 0;

    for (int i=0; 2*i < n; i++)
        for (int j = n/2 + 1; j<=n; j++)
            res = max(res, (a[i] * (2*j - n) + a[j] * (n - 2*i)) / 2 / (j - i));

    if (n % 2 == 0)
        res = max(res, a[n/2]);

    cout.setf(ios::fixed);
    cout.precision(15);
    cout << res << endl;

    return 0;
}
