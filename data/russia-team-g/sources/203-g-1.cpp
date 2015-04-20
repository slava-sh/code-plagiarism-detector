#include <iostream>
#include <cstdio>

using namespace std;

int min (int a, int b) {
    if (a < b) return a;
    else return b;
}

int main () {
    freopen ("prizes.in", "r", stdin);
    freopen ("prizes.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    cout << min (n / 3, m / 3);
}
