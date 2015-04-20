#include <iostream>
#include <vector>
#include <set>
#include <cstdio>

using namespace std;

const long long LINF=1000000000LL*1000000000LL;

const int MAXN=200005;

vector<int> g[MAXN],g2[MAXN];

bool met[MAXN];
int p[MAXN],d[MAXN];

void add_edge(vector<int> * g, int x, int y) {
    g[x].push_back(y);
    g[y].push_back(x);
}

void buildG2(int v, int pp, int depth) {
    p[v]=pp;
    d[v]=depth;
    for (size_t i=0;i<g[v].size();i++) {
        int to=g[v][i];
        if (pp==to) continue;
        g2[v].push_back(to);
        buildG2(to,v,depth+1);
    }
}

int getMaxD(int v) {
    int res=1;
    for (size_t i=0;i<g2[v].size();i++) {
        int to=g2[v][i];
        if (met[to]) continue;
        res=max(res,getMaxD(to)+1);
    }
    return res;
}

int main()
{
    freopen("dwarfs.in","r",stdin);
    freopen("dwarfs.out","w",stdout);
    int n,m,x,y,u,v,ans=0;
    cin >> n;
    m=n-1;
    while (m--) {
        cin >> x >> y;
        add_edge(g,x,y);
    }
    cin >> v >> u;
    buildG2(v,v,1);
	x=u;
    int carry=0;
	int h=0;
    while (true) {
        if (x!=u) {
		int tmp=d[x]-1+getMaxD(x);
		ans=max(ans,min(tmp,h));
        }
		if (x!=v) {
			int zz=getMaxD(x)+carry;
			carry++;
			h=zz;
		}
		if (x==v) break;
        met[x]=true;
        x=p[x];
    }
    cout << ans;
    return 0;
}
