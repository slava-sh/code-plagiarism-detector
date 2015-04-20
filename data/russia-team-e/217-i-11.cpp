#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

int n,d;
long long a[100100];
long long ans,x,y,l;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    l = a[n-1]+a[n-2]-(2*d);
    x = a[n-2]-d;
    y = a[n-1]-d;
    ans = max(l,a[n-1]);
    if (n == 1 || a[n-2] <= 2*d) {
        printf("%d", a[n-1]);
        return 0;
    }
    for (int i = n - 3; i >= 0; i--) {
        if (a[i]<=2*d) break;
        if (x < 2*d && y < 2*d) break;
        x < y ? y = a[i] - d : x = a[i] - d;
        l = l + a[i] - (2*d);
        ans = max(l,ans);
    }
    printf("%d", ans);
    return 0;
}
