#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = (int)1e5 + 10;

int a[N];

bool cmp(int x, int y){
    return x > y;
}

int main()
{
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    int n, i, j, k, d, l, r, mid;
    int ans = 0;
    cin >> n >> d;
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n, cmp);
    j = n - 1;
    while (j >= 0 && a[j] - d < 1)
        j--;
    if (j < 0){
            cout << a[0] << endl;
            return 0;
    }
    ans = a[j] - d;
    for (int i = 0; i < j; i++){
        if (i == j - 1){
                ans += a[i] - d;
                break;
        }
        if (a[i] - (d + d) >= d)
            ans += a[i] - (d + d);
        else{
            if (a[i] - d >= 1)
                ans += a[i] - d;
            else
                ans += d;
            break;
        }
    }
   /* for(i = 0; i < n; i++)
    {
        l = 0, r = i;
        while(r - l > 1)
        {
            mid = (l + r) / 2;
            if(u[mid] - d )
                l = mid;
            else
                r = mid;
        }
        //cout << l << endl;
        ans += 1ll * (n - l - 1);
    }*/

    cout << max(a[0], ans) << endl;
    return 0;
}