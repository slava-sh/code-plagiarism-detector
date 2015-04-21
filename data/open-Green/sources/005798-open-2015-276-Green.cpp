#include <bits/stdc++.h>
#define dout if (false) cout

using namespace std;

typedef long long ll;

const ll INF = 1e15;

ll n, k, rans;

bool prime[32000000];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (ll i = 2; i*i <= n; i++)
        prime[i] = true;
    for (ll i = 2; i*i*i*i <= n; i++) {
        if (prime[i])
            for (ll j = i*i; j*j <= n; j+=i)
                prime[j] = false;
    }
    vector<ll> v;
    for (ll i = 3; i*i <= n; i++)
        if (prime[i])
            v.push_back(i);
    ll tc = 0;
    while(n%2==0 && tc < k) {
        ++tc;
        n/=2;
    }
    k -= tc;
    if (k==0) {
        cout << n << endl;
        return 0;
    }
    vector<ll> divs;

    ll i;
    rans = n;
metka:
    i = 0;
    for (; i < v.size(); i++) {
        if (n%v[i] == 0) {
            n /= v[i];
            divs.push_back(v[i]);
            goto metka;
        }
    }


    if (n != 1)
        divs.push_back(n);

    //sort(divs.rbegin(), divs.rend());

    for (int i = 0; i < divs.size(); i++)
        divs[i] = -divs[i];

    priority_queue<ll> pq(divs.begin(), divs.end());


    while (pq.size() > k) {
        ll x = pq.top(); pq.pop();
        ll y = pq.top(); pq.pop();
        pq.push(-x*y);
    }

    ll ans = 1;
    while (!pq.empty()) {
        ans *= abs(pq.top())/2+1;
        pq.pop();
    }
    cout << ans << endl;
}


