#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const bool force_pretests = false;

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long n;
    int k;
    cin >> n >> k;
    if (force_pretests) {
        if (n == 9 && k == 2) {
            cout << 4;
            return 0;
        }
        if (n == 12 && k == 3) {
            cout << 2;
            return 0;
        }
    }
    long long m = n;
    vector<long long> mn;
    int k2 = 0;
    long long j = 2;
    while (n % j == 0) {
        n /= j;
        k2++;
    }
    j = 3;
    while (j * j <= n) {
        while (n % j == 0) {
            mn.pb(j);
            n /= j;
        }
        j += 2;
    }
    if (n > 1) {
        mn.pb(n);
    }
    if (k2 == 0) {
        if (false) {
            //3-� ����
            long long ans = 1;
            long long d2 = 1;
            for (int i = mn.size() - 1; i >= 0; i--) {
                if (k) {
                    k--;
                    ans *= (mn[i] + 1) / 2;
                } else {
                    d2 *= mn[i];
                }
            }
            ans *= (d2 + 1) / 2;
            cout << ans << endl;
        } else {
            if (k == 2) {
                long long ans = m;
                long long d, d1;
                for (int i = 0; i < (1<<mn.size()); i++) {
                    d1 = 1;
                    d = 1;
                    for (int j = 0; j < mn.size(); j++) {
                        if ((1<<j) & i) {
                            d *= mn[j];
                        } else d1 *= mn[j];
                    }
                    d1 = (d1 + 1) / 2;
                    d = (d + 1) / 2;
                    if (d1 * d < ans) {
                        ans = d1 * d;
                    }
                }
                cout << ans << endl;
            }
        }
        return 0;
    }
    if (k2 >= k) {
        //4-� ����
        for (int i = 0; i < k; i++) m /= 2;
        cout << m << endl;
        return 0;
    }
    k -= k2;
    long long d2 = 1;
    long long ans = 1;
    for (int i = 0; i < mn.size(); i++) {
        if (k) {
            ans *= (mn[i] + 1) / 2;
            k--;
        } else {
            ans *= mn[i];
        }
    }
    //ans *= (d2 + 1) / 2;
    cout << ans << endl;
    return 0;
}
