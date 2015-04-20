#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (n == 1){
        cout << a[0];
        return 0;
    }
    sort(a, a + n);
    int l = 0;
    int r = (k / n) + 1;
    while (l + 1 != r){
        int b = k;
        b -= a[0];
        int x = (l + r) / 2;
        for (int i = 1; i < n; i++){
            if (a[i] <= (k - b) + x){
                b -= x;
            }
            else{
                b = k - a[i];
            }
        }
        if (b >= 0){
            l = x;
        }
        else{
            r = x;
        }
    }
    cout << min(a[0], l);
    return 0;
}
