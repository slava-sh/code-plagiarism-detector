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
    long long m = n;
    vector<long long> mn;
    long long j = 2;
    while (j * j <= n) {
        while (n % j == 0) {
            mn.pb(j);
            n /= j;
        }
        if (j == 2) j = 3; else j += 2;
    }
    if (n > 1) {
        mn.pb(n);
    }
    sort(mn.begin(), mn.end());
    long long kk = 1;
    for (int i = 0; i < mn.size() && k; i++) {
        m /= mn[i];
        kk *= (mn[i] + 1) / 2;
        k--;
    }
    kk *= (m + 1) / 2;
    cout << kk << endl;
    return 0;
}
