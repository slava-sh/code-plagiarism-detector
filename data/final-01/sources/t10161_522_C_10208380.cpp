#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int a[200001], t[200001], r[200001];
bool can[200001];
int mx[200001];

void solve()
{
    int m, k;
    scanf("%d%d", &m, &k);
    for (int i=1; i<=k; i++) {
        scanf("%d", &a[i]);
        can[i]=false;
        mx[i]=0;
    }
    for (int i=1; i<m; i++) {
        scanf("%d%d", &t[i], &r[i]);
        if (t[i] && mx[t[i]]<i) mx[t[i]]=i;
    }

    int p=0;
    bool wasempty=false;
    for (int i=1; i<m; i++) {
        if (r[i]==1 && !wasempty) {
            wasempty=true;
            int x=2000000000;
            for (int j=1; j<=k; j++)
                if (mx[j]<i && p>=a[j]) {
                    can[j]=true;
                    if (a[j]<x) x=a[j];
                }
            p-=x;
        }
        if (t[i]==0) p++;
        else a[t[i]]--;
    }

    for (int i=1; i<=k; i++)
        if (can[i] || a[i]<=p) printf("Y");
        else printf("N");
    printf("\n");
}

int main()
{
    int g;
    scanf("%d", &g);
    while (g) {
        solve();
        g--;
    }
}
