#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    freopen("abcd.in", "r", stdin);
    freopen("abcd.out", "w", stdout);
    int n, cur;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        int a = cur / 100, b = cur % 100, c = a * a + b * b;
        if (c % 7 == 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
