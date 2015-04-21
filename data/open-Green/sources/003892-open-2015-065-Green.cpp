#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back

#define all(a) (a).begin(), (a).end()
#define sz(a) (int) (a).size()

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const ll inf = 1000000000ll * 1000000000ll;

ll f(ll n, int k, ll prev)
{
    if (k == 1) return (n + 1) / 2;
    ll ans = inf;
    for (ll x = 1; x * x <= n; x++)
        if (n % x == 0 && x <= prev)
    {
        ans = min(ans, (x + 1) / 2 * f(n / x, k - 1, x));
        //ans = min(ans, (n / x + 1) / 2 * f(x, k - 1));
    }
    return ans;
}

int main()
{

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    ll n;
    int k;

    cin >> n;
    cin >> k;

    cout << f(n, k, n);

}
