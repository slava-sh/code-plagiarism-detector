#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;


unsigned long long gcd (unsigned long long a, unsigned long long b){
    if (min (a, b) == 0)
        return a + b;
    return gcd (max (a, b) % min (a, b), min (a, b));
}

unsigned long long xyz(unsigned long long a, unsigned long long b)
{
    if (b == 0) return 1;
    unsigned long long res = a, ans = 1;
    while (b > 1)
    {
        if (b & 1) {
            ans *= res;
            b--;
        }
            res *= res;
            b >>= 1;
    }
    return ans * res;
}

unsigned long long a, b, lol, olo;
unsigned long long l, r, m;
vector<unsigned long long> ans;

int main(){
    freopen ("gcm.in", "r", stdin);
    freopen ("gcm.out", "w", stdout);
    cin >> a >> b;
    lol = gcd(a, b);
    olo = a * b / lol;
    unsigned long long h = olo/lol;
    unsigned long long g = h;
    unsigned long long w;
    for (unsigned long long i = 2; i <= (unsigned long long) floor(sqrt(g)); i++)
    {
        l = 0;
        r = (unsigned long long)floor(log(1e19) / log(i));
        while (r - l > 1)
        {
            m = (l + r) / 2;
            if (g % xyz(i, m) == 0) l = m;
            else r = m;
            //cerr << m << " " << xyz(i, m) << endl;
        }
        w = xyz(i, l);
        g /= w;
        //cerr << l << " " << xyz(i, l) << "\n";
        if (w != 1) ans.push_back(w);
        if (g == 1) break;
    }
    if (g != 1) ans.push_back(g);
    sort(ans.begin(), ans.end());
    unsigned long long ans1 = lol, ans2 = lol;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        if (ans2 < ans1) ans2 *= ans[i];
        else ans1 *= ans[i];
    }
    cout << min(ans1, ans2) << ' ' << max(ans1, ans2) << endl;
    return 0;
}
