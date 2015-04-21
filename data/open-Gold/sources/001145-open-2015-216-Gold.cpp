#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 300000;

int a[N], b[N], point;
vector <ll> costs;
ll need_to_pay;

void shift(int x) {
    while (x > 0 && point >= 0) {
        need_to_pay -= costs[point];
        point--;
        x--;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    ll n, k, c, d;
    cin >> n >> k >> c >> d;
    ll already = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        already += d * (b[i] - a[i]);
    }
    for (int i = 2; i <= n; i++) {
        costs.push_back(d * (a[i] - b[i - 1]));
    }
    sort(costs.begin(), costs.end());
    int cnt = costs.size();
    need_to_pay = 0;
    for (int i = 0; i < cnt; i++) {
        need_to_pay += costs[i];
    }
    /*
    cout << already << "\n";
    for (int i = 0; i < costs.size(); i++) {
        cout << costs[i] << "\n";
    }
    cout << need_to_pay << "\n";
    */
    point = cnt - 1;
    shift(k - 1);
    ll ans = already + need_to_pay;
    while (point >= 0) {
        shift(k);
        already += c;
        ans = min(ans, already + need_to_pay);
    }
    cout << ans << "\n";
    return 0;
}