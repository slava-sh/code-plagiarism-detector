#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef complex<ll> pt;

char c[100];
int n, hl, hr, v[100], h[100], a[100], b[100], ans = 0;

void check(ll dy, ll dx = 100000)
{
    if (dy == 0) return;
    ll mask[2] = {0,0};
    bool valid = true;
    int score = 0;

    for (int j = (dy > 0); (dy < 0) ^ (-hl+100*j < dy); j += dy/abs(dy))
    {
        ll x_times_dy = abs(-hl+100*j)*dx;
        bool hitmirror = false;
        for (int i = 0; i < n; ++i)
        if (h[i] == (j&1) && a[i]*abs(dy) <= x_times_dy && x_times_dy <= b[i]*abs(dy))
        {
            hitmirror = true;
            score += v[i];
            if (mask[i/64] & (1ll<<(i%64)))
                valid = false;
            else
                mask[i/64] |= 1ll<<(i%64);
        }
        valid &= hitmirror;
    }
    if (valid)
        ans = max(ans, score);
}

int main()
{
    ios::sync_with_stdio(0);

    cin >> hl >> hr >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i] >> c[i] >> a[i] >> b[i], h[i] = c[i]=='T';
    for (int k = -100; k < 101; ++k)
    {
        check(hr-hl+200*k);
        check(-hr-hl+200*k);
    }
    cout << ans << endl;
}
