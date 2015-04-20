#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

const ll MAXN = 100000;
ll n, k;
vector<ll> a;

bool check(ll x){
    if (a[0] < x) {
        return false;
    }
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += max(a[i] - sum, x);
    }
    if (sum <= k) {
        return true;
    }
    return false;
}

ll bin(ll l, ll r) {
    if (l == r) {
        return l - 1;
    }
    ll m = (l + r) / 2;
    if (check(m)) {
        bin(m + 1, r);
    }
    else {
        bin(l, m);
    }
}

int main() {
    fin >> n >> k;
    a.resize(n);
    for (ll i = 0; i < n; ++i) {
        fin >> a[i];
    }
    sort(a.begin(), a.end());
    fout << bin(0, k + 1);
    return 0;
}
