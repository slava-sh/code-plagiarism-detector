#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>

#define pb push_back
#define mp make_pair
#define F first
#define S second

using namespace std;

const int INF=2000000000;

int n, m;
vector <pair <int, int> > a[5050];
int t[5050], d[5050], p[5050];
int k[3];
priority_queue <pair <int, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i){
        scanf("%d", &t[i]);
        k[t[i]]++;
    }
    if (k[1]==0||k[2]==0){
        puts("-1");
        return 0;
    }
    int x, y, z;
    while (m--){
        scanf("%d%d%d", &x, &y, &z);
        a[x].pb(mp(y, z));
        a[y].pb(mp(x, z));
    }
    for (int i=1; i<=n; ++i){
        d[i]= (t[i]==1) ? 0 : INF;
        p[i]=i;
        q.push(mp(-d[i], i));
    }
    for (int i=0; i<n-1; ++i){
        int v=q.top().S;
        q.pop();
        if (d[v]>=INF) break;
        for (int j=0; j<a[v].size(); ++j){
            int to=a[v][j].F;
            if (d[to]>d[v]+a[v][j].S){
                d[to]=d[v]+a[v][j].S;
                p[to]=p[v];
                q.push(mp(-d[to], to));
            }
        }
    }
    int ans=INF, v=0;
    for (int i=1; i<=n; ++i)
        if (t[i]==2&&ans>d[i]) ans=d[i], v=i;
    if (ans==INF)
        puts("-1");
    else
        printf("%d %d %d\n", p[v], v, ans);
    return 0;
}
