#include <fstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

typedef
    long long ll;

ifstream cin("sochi.in");
ofstream cout("sochi.out");

int main() {
    ll n, d;
    ll ans = 0;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    v[n - 1] += d;
    v[n - 2] += d;
    for (int i = 0; i < n; ++i)
        v[i] -= d * 2;
    for (int i = 0; i < n; ++i)
        if (v[i] > 0)
            ans += v[i];
    cout << ans;
    return 0;
}
