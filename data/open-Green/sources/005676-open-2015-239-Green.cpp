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

int n, k, n2;
vector <long long> arr;

int res(int n, int i) {
    //cout << n << ' ' << i << endl;
    if (i == 0) {
        return (n + 1) / 2;
    }
    if (n % 2 == 0) {
        return res(n / 2, i - 1);
    }
    else {
        int ans;
        if (arr.size()) {
            ans = arr[(int)arr.size() - 1];
        }
        else {
            ans = 1;
        }
        //cout << ans << endl;
        arr.pop_back();
        return res(n / ans, i - 1) * ((ans + 1) / 2);
    }
}

main() {
    cin >> n2 >> k;
    n = n2;
    while (n % 2 == 0) {
        n /= 2;
    }
    for(int i = 3; i * i <= n; ++i) {
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

