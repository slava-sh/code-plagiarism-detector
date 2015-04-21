#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    int k;
    cin >> n >> k;
    if (k == 1) {
        cout << (n + 1) / 2 << endl;
        return 0;
    }
    if (k == 3) {
        cout << 2 << endl;
        return 0;
    }
    if (k == 2) {
        int ans = n + 1;
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (((i + 1) / 2) * ((n / i + 1) / 2) < ans) {
                    ans = min(ans, ((i + 1) / 2) * ((n / i + 1) / 2));
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

