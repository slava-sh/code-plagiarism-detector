#include <cstdio>
#include <iostream>

using namespace std;

int a[300300];
int n, d;

inline int bs1(int x){
    int l=0, r=n-1, res=-1;
    while (l<=r){
        int m=(l+r)/2;
        if (a[m]<=x)
            res=m, l=m+1;
        else
            r=m-1;
    }
    return res;
}

inline int bs2(int x){
    int l=0, r=n-1, res=-1;
    while (l<=r){
        int m=(l+r)/2;
        if (a[m]>=x)
            res=m, r=m-1;
        else
            l=m+1;
    }
    return res;

}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("che.in", "r", stdin);
    freopen("che.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    long long ans=0;
    for (int i=0; i<n; ++i){
        int k=bs1(a[i]-d-1);
        if (k!=-1) ans+=k+1;
        k=bs2(a[i]+d+1);
        if (k!=-1) ans+=n-k;
    }
    printf("%I64d\n", ans/2);
    return 0;
}
