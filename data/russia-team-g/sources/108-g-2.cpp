#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("prizes.in", "r", stdin);
    freopen("prizes.out", "w", stdout);
    int n, m, k;
    cin >> n >> m;
    if (m < n){
        k = n;
        n = m;
        m = k;
    }
    if (n == 1){
        if (m < 3){
            cout << 0;
        }else{
            cout << (m + 1) / 4;
        }
    }else{
        if (n == 2){
            cout << 0;
        } else {
            cout << 1;
        }
    }
    return 0;
}
