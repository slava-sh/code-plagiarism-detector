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

long long a[100100];
long long b[100100];

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    long long c, d;
    cin >> n >> k >> c >> d;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<long long> v;
    for (int i = 0; i < n-1; i++) {
        v.pb(a[i+1] - b[i]);
    }
    sort(v.rbegin(), v.rend());
    long long cur = (b[n-1] - a[0]) * d;
    int i = 0;
    while (i < v.size() && i < k - 1) {
        cur -= v[i] * d;
        i++;
    }
    long long ans = cur;
    for (; i < v.size(); i += k) {
        int j = i;
        cur += c;
        while (j < v.size() && j - i < k) {
            cur -= v[j] * d;
            j++;
        }
        ans = min(ans, cur);
    }
    cout << ans << endl;
    return 0;
}
