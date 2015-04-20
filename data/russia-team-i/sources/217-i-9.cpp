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
    bool f=0;
    int l=a[n-1];
    if (n==1){
        printf("%d", l);
        return 0;
    }
    for (int i=0; i<n; ++i){
        if (!f){
            if (a[i]>2*d) l=a[i]+a[i+1]-2*d, f=1, ++i;
            continue;
        }
        l=l+a[i]-2*d;
    }
    printf("%d", l);
    return 0;
}
