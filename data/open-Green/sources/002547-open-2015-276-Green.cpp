#include <bits/stdc++.h>
#define dout if (false) cout

using namespace std;

typedef long long ll;

const ll INF = 1e15;

ll n, k;

bool prime[32000000];

ll bf(ll n, ll k) {
    if (k == 1) {
        return n/2 + (n%2);
    } else if (k == 2) {
        if (n%2==0) {
            n /= 2;
            return n/2 + n%2;
        } else {
            for (ll i = sqrt(n)+1; i >= 1; i--) {
                if (n%i==0) {
                    return (n/i/2+1)*(i/2+1);
                }
            }
        }
    } else if (k == 3) {
        return 2;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    //ll bans = bf(n, k);
    dout << "BF DONE" << endl;
    for (ll i = 2; i*i <= n; i++)
        prime[i] = true;

    dout << "PRIME FILLED" << endl;

    for (ll i = 2; i*i*i*i <= n; i++) {
        if (prime[i])
            for (ll j = i*i; j*j <= n; j+=i)
                prime[j] = false;
    }
    dout << "PRIME DONE!" << endl;
    vector<ll> v;
    for (ll i = 2; i*i <= n; i++)
        if (prime[i])
            v.push_back(i);
    ll tc = 0;
    while(n%2==0 && tc < k) {
        ++tc;
        n/=2;
    }
    dout << "TC FOUND: " << tc << endl;
    vector<ll> divs;

    dout << "ALL PRIMES <= sqrt(n): " << endl;
    for (ll i = 0; i < v.size(); i++)
        dout << v[i] << endl;

    dout << "DIVS OF " << n << ": " << endl;

    ll i;
metka:
    i = 0;
    for (; i < v.size(); i++) {
        if (n%v[i] == 0) {
            n /= v[i];
            divs.push_back(v[i]);
            goto metka;
        }
    }


    for (ll i = 0; i < divs.size(); i++)
        dout << divs[i] << ' ';
    dout << endl;

    if (n != 1)
        divs.push_back(n);

    if (k-tc > 0) {
        while (divs.size() > k-tc) {
            divs[0] *= divs[divs.size()-1];
            divs.pop_back();
        }
    }

    dout << "Num of divs: " << divs.size() << endl;

    ll ans = 1;
    for (ll i = 0; i < divs.size(); i++)
        ans *= divs[i]/2+1;
    cout << ans << endl;
    //dout << "(" << bans << ")" << endl;
}


