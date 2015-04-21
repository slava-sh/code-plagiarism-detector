#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const lol N = 5000;
lol a[N], l, k;
lol ans[20], otv = 10000000000000000ll;

void calc() {
    lol a = 1;
//    cout << "MASS\t";
//    for(int i = 1;  i <= k; i++)
//        cout << ans[i] << ' ';
//    cout << "\n\n";
    for(int i = 2; i <= k; i++) {
        a *= (ans[i] / ans[i - 1] + 1) / 2;
    }
    otv = min(otv, a);
//    cout << a << "\n";
}



void rec(lol n, lol k, lol l) {
    if(k == 1) {
        calc();
        return;
    }
    for(int i = l; i >= 1; i--) {
//        cout << "RAZBOR\t" << n << ' ' << k << ' ' << i << "\n";
//        cout << "\t" << a[i] << "\n";
        if(n % a[i] == 0) {
            ans[k] = a[i];
            rec(a[i], k - 1, i);
        }
    }
}

int main() {
    must;
    lol n, i;
    cin >> n >> k;
    for(i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            a[++l] = i;
            if(i != n / i)
                a[++l] = n / i;
        }
    }
    k++;
    ans[1] = 1;
    ans[k] = n;
    sort(a + 1, a + 1 + l);
    rec(n, k - 1, l);
    cout << otv;

}
