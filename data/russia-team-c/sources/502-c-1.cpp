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
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int n,m,x,y,u,v,ans;
    cin >> n;
    m=n-1;
    while (m--) {
        cin >> x >> y;
        add_edge(g,x,y);
    }
    cin >> v >> u;
    buildG2(v,v,1);
    x=u;
    while (x!=v){
        met[x]=true;
        x=p[x];
    }
    int r1=getMaxD(v);//maximal way
    memset(met,0,sizeof(met));
    int z1=getMaxD(u);
    met[u]=true;
    int z2=getMaxD(v);
    ans=min(z1,z2);
    x=p[u];
    int carry=0;
	int h=z1;
    while (true) {
		int tmp=d[x]-1+getMaxD(x);
		ans=max(ans,min(tmp,h));
		if (x!=v) {
			carry++;
			int zz=getMaxD(x)+carry;
			h=zz;
		}
		met[x]=true;
        x=p[x];
		if (x==v) break;
    }
    cout << ans;
    return 0;
}
