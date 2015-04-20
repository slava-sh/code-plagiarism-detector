 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>

 using namespace std;

 const int N = (int) 1e6;

 typedef long long lli;

 int n, m;

 int f (int n)
 {
     if (n == 2)
        return 0;
     return 1;
 }

 int main () {

    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);

    cin >> n >> m;

    if (n == 1 && m == 1)
    {
        cout << "0\n";
        return 0;
    }

    if (n == 1)
    {
        if (m > 2)
            cout << 1 + (m - 3) / 4 << "\n";
        else
            cout << "0\n";
        return 0;
    }

    if (m == 1)
    {
        if (n > 2)
            cout << 1 + (n - 3) / 4 << "\n";
        else
            cout << "0\n";
        return 0;
    }

    cout << min (f (n), f (m));

    return 0;
 }
