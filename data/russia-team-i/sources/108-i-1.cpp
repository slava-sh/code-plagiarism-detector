#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[100001];

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int i = n - 1;
    long long sum = 0;
    while ((i >= 0) && (a[i] >= 3 * d)){
        sum += a[i] - 2 * d;
        i--;
    }
    if ((i >= 0) &&(a[i] >= 2 * d)){
        sum += a[i] - 2 * d;
        i--;
    }
    if ((i >= 0) &&(a[i] >= 2 * d)){
        sum += a[i] - 2 * d;
        i--;
    }
    if (i == n - 1){
        cout << a[n - 1];
        return 0;
    }
    cout << sum + 2 * d;
    return 0;
}
