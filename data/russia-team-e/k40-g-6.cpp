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

    ll n, m;
    cin >> n >> m;
    if(n > m)
        swap(n, m);
    if(n == 2 || m == 2)
        cout << 0;
    else if(n == 1) {
        if(m == 1)
            cout << 0;
        else
            cout << (m - 3) / 4 + 1;
    } else
        cout << 1;
}
