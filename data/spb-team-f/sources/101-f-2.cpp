#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include<cmath>
#include<algorithm>

using namespace std;

long long gcd (long long a, long long b){
    if (min (a, b) == 0)
        return a + b;
    return gcd (max (a, b) % min (a, b), min (a, b));
}

int main(){
    //freopen ("gcm.in", "r", stdin);
    //freopen ("gcm.out", "w", stdout);
    long long a, b, lol, olo;
    cin >> a >> b;
    lol = gcd(a, b);
    olo = a * b / lol;
    long long h = olo/lol;
    long long g = h;
    long long w;
    vector<long long> ans;
    for (int i = 2; i <= h/2; i++)
    {
        w = 1;
        while (g%i == 0)
        {
            g /= i;
            w *= i;
        }
        ans.push_back(w);
    }
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
