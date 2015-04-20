#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = (int)1e5 + 10;

int a[N], n, k;

bool check(int x){
    int h = 0;
    for (int i = 0; i < n; i++){
        if (h + x - a[i] >= 0)
            h = h + x;
        else
            h = a[i];
        if (h > k)
            return 0;
    }
    return 1;
}

int main()
{
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    int l, r, mid;
    long long ans = 0;
    int mn = (int) 2e9;
    cin >> n >> k;
    //k++;
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] < mn)
            mn = a[i];
    }
    sort(a, a + n);
    l = 0;
    r = mn;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if(check(mid))
            l = mid;
        else
            r = mid;
    }
    if (check(r))
        cout << r << endl;
    else
        cout << l << endl;
    return 0;
}
