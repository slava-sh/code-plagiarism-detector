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
    if (a[0] == k){
        cout << 0;
        return 0;
    }
    int max = 0;
    for (int i = 1; i < n; i++){
        if ((a[i] - a[i - 1] > max) && (a[i] - a[i - 1] <= (k / n))){
            max = a[i] - a[i - 1];
        }
    }
    cout << max;
    return 0;
}
