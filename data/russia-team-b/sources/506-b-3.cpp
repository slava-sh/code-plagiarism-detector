#include <fstream>
#include <vector>

#define ll long long

using namespace std;

ifstream fin("che.in");
ofstream fout("che.out");

vector<ll> a;
ll n;

ll bin (ll x, ll l, ll r) {
    if (a[r] < x + 1)
        return r + 1;
    ll mid = (l + r) / 2;
    if (mid + 1 < n && a[mid + 1] > x && a[mid] < x)
        return mid + 1;
    if (a[mid] == x){
        return min(mid + 1, n);
    }
    if (a[mid] <= x)
        return bin(x, mid, r);
    else
        return bin(x, l, mid);
}

int main() {
    ll r;
    fin >> n >> r;
    a.resize(n);
    for (ll i = 0; i < n; ++i)
        fin >> a[i];
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += n  - bin(a[i] + r, 0, n - 1);
    }
    fout << sum << endl;
    return 0;
}
