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
    ll n, d, k = 0, kk = 0;
    ll ans = 0;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    if (n == 1)
        cout << v[0];
    else {
        sort(v.begin(), v.end());
        for(int i = 0; i < n; ++i) {
            if (v[i] - d > 0)
                kk++;
        }
        if (kk >= 2) {
            for(int i = 0; i < n; ++i)
                v[i] -= d;
            for (int i = 0; i < n; ++i)
                if (k < 2)
                {
                    if (v[i] > 0)
                    {
                        ans += v[i];
                        k ++;
                    }
                }
                else if (k == 2)
                        if (v[i] - d >= d)
                        ans += v[i] - d;
            cout << ans;
        } else
            cout << v[n - 1];
    }
    return 0;
}
