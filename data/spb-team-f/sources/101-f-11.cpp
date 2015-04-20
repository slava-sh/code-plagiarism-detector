#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

long long gcd (long long a, long long b){
    if (min (a, b) == 0)
        return a + b;
    return gcd (max (a, b) % min (a, b), min (a, b));
}

long long xyz(long long a, long long b)
{
    if (b == 0) return 1;
    long long res = a, ans = 1;
    while (b > 1)
    {
        if (b & 1) {
            ans *= res;
            b--;
        }
        else{
            res *= res;
            b >>= 1;
        }
    }
    return ans * res;
}

int main(){
    freopen ("gcm.in", "r", stdin);
    freopen ("gcm.out", "w", stdout);
    long long a, b, lol, olo;
    cin >> a >> b;
    lol = gcd(a, b);
    olo = a * b / lol;
    long long h = olo/lol;
    long long g = h;
    long long w;
    vector<long long> ans;
    long long l, r, m;
    for (long long i = 2; i <= (long long) floor(sqrt(h)); i++)
    {
        l = 0;
        r = 60;
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (g % xyz(i, m) == 0) l = m;
            else r = m;
            //cerr << m << " " << xyz(i, m) << endl;
        }
        w = xyz(i, l);
        if (xyz(i, l) == 0)
        cout << "asdasihdasiudas";
        g /= w;
        //cerr << l << " " << xyz(i, l) << "\n";
        if (w != 1) ans.push_back(w);
        if (g == 1) break;
    }
    ans.push_back(g);
    sort(ans.begin(), ans.end());
    long long ans1 = lol, ans2 = lol;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans2 < ans1) ans2 *= ans[i];
        else ans1 *= ans[i];
    }
    cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << endl;
    return 0;
}
