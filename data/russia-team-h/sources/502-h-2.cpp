#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

const int MAXN=5005;

const long long LINF=1000000000LL*1000000000LL;

set<pair<long long,int> > s;

void bfs(int n, int * a, pair<long long,int> * d, vector<pair<int,long long> > * g) {
    for (int i=1;i<=n;i++)
        d[i]=make_pair(LINF,-1);
    for (int i=1;i<=n;i++)
        if (a[i]==2) {
            s.insert(make_pair(0LL,i));
            d[i]=make_pair(0LL,i);
        }
    while (!s.empty()) {
        int v=s.begin()->second;
        s.erase(s.begin());
        for (size_t i=0;i<g[v].size();i++) {
            int to=g[v][i].first;
            long long c=g[v][i].second;
            if (d[v].first+c<d[to].first) {
                s.erase(make_pair(d[to].first,to));
                d[to]=make_pair(d[v].first+c,d[v].second);
                s.insert(make_pair(d[to].first,to));
            }
        }
    }
}

vector<pair<int,long long> > g[MAXN];
pair<long long,int> d[MAXN];

int a[MAXN];

void add_edge(int x, int y, long long c) {
    if (a[x]!=1)
        g[x].push_back(make_pair(y,c));
    if (a[y]!=1)
        g[y].push_back(make_pair(x,c));
}

int main()
{
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int n,m,i,j;
    cin >> n >> m;
    for (i=1;i<=n;i++)
        cin >> a[i];
    while (m--) {
        int x,y,c;
        cin >> x >> y >> c;
        add_edge(x,y,c);
    }
    bfs(n,a,d,g);
    long long glMi=LINF;
    int x,y;
    for (i=1;i<=n;i++)
        if (a[i]==1) {
            if (d[i].first<glMi) {
                glMi=d[i].first;
                x=i,y=d[i].second;
            }
        }
    if (glMi==LINF) cout << -1;
    else cout << x << ' ' << y << ' ' << glMi;
    return 0;
}
