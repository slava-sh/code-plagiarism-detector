#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    if (m < n) {
        long long t = m;
        m = n;
        n = t;
    }

    if (n == 1) {
        cout << (m + 1) / 4 ;
    }
    else {
        cout << (n + 1) / 4;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
