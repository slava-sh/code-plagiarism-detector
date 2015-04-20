#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int inf = 1e4;
int a[100001];

int main()
{
    freopen("sochi.in","r",stdin);
    freopen("sochi.out","w",stdout);
    int i,n, sum = 0, d;
    cin >> n >> d;
    for (i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < d) a[i] = inf;
    }
    sort(a, a+n);
    sum += a[0] + a[1] - 2*d;
    for (i = 2; i < n; i++)
        if (a[i] != inf && a[i] > 2*d) sum += a[i] - 2*d;

    cout << sum;
    return 0;
}
