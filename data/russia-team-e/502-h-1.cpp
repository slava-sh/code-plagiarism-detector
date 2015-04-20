#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF=1000000000;

int getint() {
    int x;
    scanf("%d",&x);
    return x;
}

const int MAXN=5005;

const long long LINF=1000000000LL*1000000000LL;

set<pair<long long,int> > s;

void dijkstra(int v, int n, vector<pair<int,long long> > * g, long long * d) {
    for (int i=1;i<=n;i++)
        d[i]=LINF;
    d[v]=0;
    s.insert(make_pair(d[v],v));
    while (!s.empty()) {
        v=s.begin()->second;
        s.erase(s.begin());
        for (size_t i=0;i<g[v].size();i++) {
            int to=g[v][i].first;
            long long c=g[v][i].second;
            if (d[v]+c<d[to]) {
                s.erase(make_pair(d[to],to));
                d[to]=d[v]+c;
                s.insert(make_pair(d[to],to));
            }
        }
    }
}

int a[MAXN];

long long d[MAXN];

vector<pair<int,long long> > g[MAXN];

void add_edge(int x, int y, long long c) {
    if (a[y]!=1)
        g[x].push_back(make_pair(y,c));
    if (a[x]!=1)
        g[y].push_back(make_pair(x,c));
}

int main()
{
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int n,m;
    cin >> n >> m;

    for (int i=1;i<=n;i++)
        cin >> a[i];

    while (m--) {
        int x,y,c;
        cin >> x >> y >> c;
        add_edge(x,y,c);
    }
    long long glMi=LINF;
    int x,y;
    for (int i=1;i<=n;i++) {
        if (a[i]!=1) continue;
        dijkstra(i,n,g,d);
        long long mi=LINF;
        int xx,yy;
        for (int j=1;j<=n;j++)
            if (a[j]==2 && d[j]<mi) {
                xx=i,yy=j,mi=d[j];
            }
        if (mi<glMi) {
            glMi=mi;
            x=xx,y=yy;
        }
    }

    if (glMi==LINF) cout << -1;
    else cout << x << ' ' << y << ' ' << glMi;

    return 0;
}
