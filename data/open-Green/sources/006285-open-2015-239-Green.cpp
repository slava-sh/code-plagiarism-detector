#include <iostream>
#include <vector>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define int long long
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n, k, n2, L;
vector <long long> arr;

int res(int n, int i) {
    //cout << n << ' ' << i << endl;
    if (i == 0) {
        return (n + 1) / 2;
    }
    int ans;
    if (arr.size() != L) {
        ans = arr[L];
        ++L;
    }
    else {
        ans = 1;
    }
    //cout << ans << endl;
    return res(n / ans, i - 1) * ((ans + 1) / 2);
}

main() {
    cin >> n2 >> k;
    n = n2;
    for(int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            arr.pb(i);
            n /= i;
        }
    }
    if (n != 1) {
        arr.push_back(n);
    }
    cout << res(n2, k);
}

