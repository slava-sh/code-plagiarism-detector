#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long long a[1000000];


int main()
{
    freopen ("merlin.in", "r", stdin);
    freopen ("merlin.out", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    long long p = a[0];
    for (long long i = 1; i < n; i++){
       p += a[i];
    }
    bool b = true;
    long long h = a[0];
    for (long long i = 1; i < n; i++){
        if (h != a[i]){
            b = false;
        }
    }
    if (b){
        cout << "0";
        exit(0);
    }
    long long ans = 0;
    for (long long i = n - 1; i >= 0; i--) {
        if (p >= a[i - 1] * i){
            cout << n - i;
            exit(0);
        }
    }
    cout << n - 1;
    return 0;
}
