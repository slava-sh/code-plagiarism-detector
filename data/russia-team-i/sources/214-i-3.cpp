#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int a[100007];


bool for_sort(int a, int b){
    return a > b;
}

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d, w, i, sum = 0, l, r;
    bool flag;
    cin >> n >> d;
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, for_sort);
    l = a[0];
    r = a[0];
    sum = a[0];
    flag = true;
    for (i = 1; i < n; i++){
        if (flag){
            if (r - d * 2 + a[i] > r && r > d && a[i] > d){
                sum = r - d * 2 + a[i];
                l = a[i] - d;
                r = r - d;
                flag = false;
            }
        }
        else
        if (l - 2 * d >= 0 && a[i] - 2 * d > 0){
            sum += a[i] - d * 2;
            l = a[i] - d;
        }
        else
        if (r - 2 * d >= 0 && a[i] - 2 * d > 0){
            sum += a[i] - d * 2;
            r = a[i] - d;
        }
    }
    cout << sum;
    return 0;
}

