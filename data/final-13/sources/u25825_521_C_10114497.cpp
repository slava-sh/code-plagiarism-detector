#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n, k;
string s;
int fact[100100], inv[100100], pref[100100], suff[100100], ex[100100], sum[100100];

int binpow(int a, int k) {
    if(k == 0) return 1;
    int ans = binpow(a, k / 2);
    ans = 1ll * ans * ans % mod;
    if(k % 2) ans = 1ll * ans * a % mod;
    return ans;
}

int C(int n, int k) {
    if(k > n) return 0;
    int ans = fact[n];
    ans = 1ll * ans * inv[k] % mod;
    ans = 1ll * ans * inv[n-k] % mod;
    return ans;
}

int calc(int l, int r) {
    int ans = sum[l];
    ans = (ans - sum[r+1]) % mod;
    ans += mod; ans %= mod;
    return ans;
}

int f(int l, int r) {
    int ans = suff[l] - suff[r+1];
    ans %= mod; ans += mod; ans %= mod;
    ans = 1ll * ans * binpow(ex[n-r-1], mod-2) % mod;
    return ans;
}

int main(){
    
    scanf("%d%d\n", &n, &k);
    getline(cin, s);
    
    fact[0] = inv[0] = 1;
    for(int i = 1; i < 100100; i++) {
        fact[i] = 1ll * i * fact[i-1] % mod;
        inv[i] = binpow(fact[i], mod-2);
    }
    
    if(k == 0) {
        int ans = 0;
        for(int i = 0; i < sz(s); i++) ans = (10ll * ans % mod + s[i] - '0') % mod;
        cout << ans << endl;
        return 0;
    }
    
    pref[0] = s[0] - '0';
    ex[0] = 1;
    for(int i = 1; i < n; i++) {
        ex[i] = 10ll * ex[i-1] % mod;
        pref[i] = (10ll * pref[i-1] % mod + s[i] - '0') % mod;
    }
    
    suff[n-1] = s[n-1] - '0';
    for(int i = n-2; i >= 0; i--) {
        int d = s[i] - '0';
        suff[i] = (d * 1ll * ex[n - i - 1] % mod + suff[i+1]) % mod;
    }
    
    sum[n-1] = s[n-1] - '0';
    for(int i = n-2; i >= 0; i--) sum[i] = (sum[i+1] + s[i] - '0') % mod;
    
    int ans = 0;
    
    for(int i = 0; i < n-1; i++) {
        int temp = C(n - i - 2, k - 1);
        ans = (ans + 1ll * temp * pref[i] % mod) % mod;
    }
    for(int i = n-1; i > 0; i--) {
        int temp = C(i-1, k-1);
        ans = (ans + 1ll * temp * suff[i] % mod) % mod;
    }
    
    if(k == 1) {
        cout << ans << endl;
        return 0;
    }
    
    int s = 0;
    
    for(int sz = 1; sz <= n-2; sz++) {
        int temp = C(n - sz - 2, k - 2);
        if(sz == 1) {
            s = calc(1, n-2);
            ans = (ans + temp * 1ll * s % mod) % mod;
        } else {
            s = (s - f(n - sz, n - 2)) % mod;
            s = (s + mod) % mod;
            s = 10ll * s % mod;
            s = (s + calc(sz, n-2)) % mod;
            ans = (ans + 1ll * temp * s % mod) % mod;
        }
        //cout << sz << " " << s << endl;
    }
    
    cout << ans << endl;
        
    return 0;
}
