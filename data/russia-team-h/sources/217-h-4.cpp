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

const long long INF=1000000000000000000ll;

int n, m;
vector <pair <int, int> > a[10050];
int t[10050], p[10050];
long long d[10010];
priority_queue <pair <long long, int> > q;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; ++i){
        scanf("%d", &t[i]);
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
    for (int i=0; i<10*n; ++i){
        if (q.empty()) break;
        int v=q.top().S;
        if (-q.top().F!=d[v]){
            q.pop();
            continue;
        }
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
    long long ans=INF;
    int v=0;
    for (int i=1; i<=n; ++i)
        if (t[i]==2&&ans>d[i]) ans=d[i], v=i;
    if (ans==INF)
        puts("-1");
    else
        printf("%d %d %I64d\n", p[v], v, ans);
    return 0;
}
