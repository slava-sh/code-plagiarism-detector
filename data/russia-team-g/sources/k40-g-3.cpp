#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long
#define in(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int main() {
    in("prizes.in");
    out("prizes.out");
    ll n, m, kol = 0;
    cin >> n >> m;
    if(n <= 2 && m <= 2) {
        cout << 0;
        exit(0);
    }
    if(n == 1)
        kol = 1 + (m - 3) / 4;
    else if(m == 1)
        kol = 1 + (n - 3) / 4;
    else
        kol = min((n - 3) / 4, (m - 3) / 4) + 1;
    cout << kol;


}
