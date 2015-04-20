#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

long long m(long long x){
    if (x >= 0){
        return x;
    }
    return -x;
}

long long gcd(long long x, long long y) {
    if (x == 0) {
        return y;
    } else if (y == 0) {
        return x;
    } else {
        long long mn = min(x, y);
        long long mx = max(x, y);
        return gcd(mx - mn, mn);
    }
}
int main()
{
    freopen ("gcm.in", "r", stdin);
    freopen ("gcm.out", "w", stdout);
    long long x, y;
    cin >> x >> y;
    long long a = x * y;
    long long minn;
    long long need = x * y;
    x = gcd(x, y);
    y = need / x;
    minn = y;
    long long ans;
    ans = 1;
    for (int i = 1; i <= round(sqrt(a)); i++){
        if ((a % i == 0) && (i % x == 0) && ((a / i) % x == 0)){
            if (minn > (m(a / i - i))) {
                minn = m(a / i - i);
                ans = i;
            }
        }
    }
    cout << ans << " " << a / ans << endl;
    return 0;
}
