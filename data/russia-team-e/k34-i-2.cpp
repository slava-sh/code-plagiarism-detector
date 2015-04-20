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
    ll n, d, k = 0;
    ll ans = 0;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i)
        v[i] -= d;
    for (int i = 0; i < n; ++i)
        if (v[i] >= d)
        {
            if (k < 2)
            {
                ans += v[i];
                k ++;
            }
            else if (k == 2)
                if (v[i] - d >= d)
                ans += v[i] - d;
        }
    cout << ans;
    return 0;
}
