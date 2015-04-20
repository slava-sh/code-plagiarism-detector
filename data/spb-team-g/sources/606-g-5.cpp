#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

unsigned long long n, mas[1000000], sum[1000000];

int main() {
    freopen("merlin.in", "r", stdin);
    freopen("merlin.out", "w", stdout);
    cin >> n;
    for(unsigned long long i = 1; i <= n; i++) {
        cin >> mas[i];
    }
    sort(mas + 1, mas + n + 1);
    sum[1] = mas[1];
    for(unsigned long long i = 2; i <= n; i++) {
        sum[i] = sum[i - 1] + mas[i];
    }
    if (sum[n] == n * mas[n]) {
        cout << 0;
        return 0;
    }

    unsigned long long ans = 0;
    unsigned long long check = 0;

    for(unsigned long long i = n; i >= 1; i--) {
        check+=mas[i];
        if ((mas[i - 1]*(i - 1)) - sum[i - 1] < check) {
            cout << ans + 1;
            return 0;
        }
        else {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
