#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n,k,mid;
int a[100100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("fence.in", "r", stdin);
    freopen("fence.out", "w", stdout);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int l = 1;
    int r = a[0], ans=0;
    int p;
    for (int i = 0; i < 100; i++) {
        p = 0;
        mid = (l+r)/2;
        for (int j = 0; j < n; j++) {
            if (a[j]-p > mid) p = a[j]; else p += mid;
            if (p > k) break;
        }
        if (p <= k) ans=mid, l = mid+1; else
            if (p > k) r = mid-1;
    }
    printf("%d", ans);
    return 0;
}
