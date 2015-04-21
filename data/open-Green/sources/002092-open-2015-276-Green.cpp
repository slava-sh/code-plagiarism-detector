#include <bits/stdc++.h>
#define dout if (false) cout

using namespace std;

typedef long long ll;

const ll INF = 1e15;

ll n, k;

bool prime[32000000];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i <= n; i++)
        prime[i] = true;

    for (int i = 2; i*i <= n; i++) {
        if (prime[i])
            for (int j = i*i; j <= n; j+=i)
                prime[j] = false;
    }
    vector<ll> v;
    for (int i = 3; i <= n; i++)
        if (prime[i])
            v.push_back(i);
    int tc = 0;
    while(n%2==0) {
        ++tc;
        n/=2;
    }
    dout << "TC FOUND: " << tc << endl;
    vector<ll> divs;

    dout << "ALL PRIMES <= n: " << endl;
    for (int i = 0; i < v.size(); i++)
        dout << v[i] << endl;

    dout << "DIVS OF " << n << ": " << endl;

    int i;
metka:
    i = 0;
    while(n>1) {
        for (; i < v.size(); i++) {
            if (n%v[i] == 0) {
                n /= v[i];
                divs.push_back(v[i]);
                goto metka;
            }
        }
    }


    for (int i = 0; i < divs.size(); i++)
        dout << divs[i] << ' ';
    dout << endl;

    if (k-tc > 0) {
        while (divs.size() > k-tc) {
            divs[0] *= divs[divs.size()-1];
            divs.pop_back();
        }
    }

    dout << "Num of divs: " << divs.size() << endl;

    ll ans = 1;
    for (int i = 0; i < divs.size(); i++)
        ans *= divs[i]/2+1;
    cout << ans << endl;
}


