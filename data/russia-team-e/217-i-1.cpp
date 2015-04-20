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

int n, d;
int a[100100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("sochi.in", "r", stdin);
    freopen("sochi.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for (int i=0; i<n; ++i)
        scanf("%d", &a[i]);
    sort(a, a+n);
    if (n==1||a[n-2]<d) {
        printf("%d", a[n-1]);
        return 0;
    }
    int l=a[n-1]+a[n-2]-2*d, x=a[n-2]-d, y=a[n-1]-d;
    for (int i=n-3; i>=0; --i){
        if (x<d&&y<d||a[i]<d) break;
        l=l+a[i]-2*d;
        x>=d ? x=a[i]-d : y=a[i]-d;
    }
    printf("%d\n", l);
    return 0;
}
