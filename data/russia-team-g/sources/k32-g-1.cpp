 # include <iostream>
 # include <cstdio>
 # include <cstdlib>
 # include <algorithm>

 using namespace std;

 const int N = (int) 1e6;

 typedef long long ll;

 int n, m;

 int f (int n, int m)
 {
     if (n == 1)
     {
         if (m > 2)
            return 1 + (m - 3) / 4;
         return 0;
     }
     if (n > 2)
        return 1 + (n - 3) / 4;
     return 0;
 }

 int main () {

    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);

    cin >> n >> m;

    cout << min (f (n, m), f (m, n)) << "\n";

    return 0;
 }
