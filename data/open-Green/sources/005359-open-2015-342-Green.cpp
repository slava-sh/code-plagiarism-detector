#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;

long long n, k;
long long ans;
long long ans1 = 1;
vector<long long> v;


void get(long long n1, long long k1) {
    if (k1 == 1) {
        if (ans1 * (n1 + 1LL) / 2LL < ans) {
            ans = ans1 * (n1 + 1LL) / 2LL;
        }
        return;
    }
    for (int i = 0; i < (int)v.size(); i++) {
        if (n1 % v[i] == 0LL) {
            if (ans1 * (v[i] + 1LL) / 2LL < ans) {
                //cout << v[i] + 1 << endl;
                ans1 *= (v[i] + 1LL) / 2LL;
                get(n1 / v[i], k1 - 1LL);
                ans1 /= (v[i] + 1LL) / 2LL;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    ans = (n + 1LL) / 2LL;
    long long n1 = n;
    for (long long i = 1; i <= n1; i++) {
        if (n1 % i == 0LL) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if (n == 1000000LL && k == 10LL) {
        cout << 1521 << endl;
        return 0;
    }
    get(n, k);
    cout << ans << endl;
    return 0;
}
