#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    freopen ("sochi.in", "rt", stdin);
    freopen ("sochi.out", "wt", stdout);
    long long n, d;
    cin >> n >> d;
    long long sum = 0;
    long long kol = 0;
    long long a[100010];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++){
        if (a[i] > 2 * d){
            kol++;
            sum += a[i];
        }
    }
    if (kol > 1){
        cout << sum - (2 * d * (kol - 1));
    } else {
        cout << a[n - 1];
    }
    return 0;
}
