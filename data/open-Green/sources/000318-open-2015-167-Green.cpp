#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

int main()
{
    ll n, ans = 1ll;
    int k;
    cin >> n >> k;
    for (int i = 1; i < k; i++){
        for (ll j = 2ll; j * j <= n; j++)
            if (n % j == 0ll){
                if (j % 2ll != 0ll && n % (j + 1ll) == 0ll)
                    continue;
                n /= j;
                ans *= (j / 2ll) + (j % 2ll);
                break;
            }
    }
    ans *= n / 2ll + n % 2ll;
    cout << ans;
    return 0;
}
