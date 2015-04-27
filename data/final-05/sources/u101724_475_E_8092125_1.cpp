#include<bits/stdc++.h>
#define MAX   2222
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define iterme(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define fi   first
#define se   second
#define SQR(x) ((x)*(x))

using namespace std;

typedef pair<int,int> ii;

vector<ii> Graph[MAX];
int niz[MAX],indexn[MAX];
bool kusok[MAX*MAX*2],most[MAX*MAX*2];
int n,m,nComp,cnt;
vector<int> derevo[MAX];
int compSZ[MAX],compID[MAX];
int treeSZ[MAX],nPair[MAX];

class DisjointSetUnion {
    public:
    vector<int> up;
    void join(int a,int b) {
        int x=find(a);
        int y=find(b);
        if (x==y) return;
        up[x]+=up[y];
        up[y]=x;
    }
    int find(int x) {
        if (up[x]<0) return (x);
        up[x]=find(up[x]);
        return (up[x]);
    }
    DisjointSetUnion(int n) {
        up.assign(n+7,-1);
    }
    DisjointSetUnion(){}
};

bool dp[MAX][MAX];

void poset(int u) {
    indexn[u]=++cnt;
    niz[u]=n+1;
    FORE(it,Graph[u]) if (!kusok[it->se]) {
        int v=it->fi;
        kusok[it->se^1]=true;
        if (indexn[v]==0) {
            poset(v);
            if (niz[v]>indexn[u]) most[it->se]=true;
            niz[u]=min(niz[u],niz[v]);
        }
        else niz[u]=min(niz[u],indexn[v]);
    }
}

void zagruz(void) {
    scanf("%d%d",&n,&m);
    iterme(i,m) {
        int u,v;
        scanf("%d%d",&u,&v);
        Graph[u].push_back(ii(v,i*2));
        Graph[v].push_back(ii(u,i*2+1));
    }
}

void zgruztree(void) {
    FOR(i,1,n)
    if
    (indexn[i]==0)
    poset(i);
    DisjointSetUnion dsu(n);
    FOR(u,1,n)
    FORE(it,Graph[u])
    if (!most[it->se] && !most[it->se^1])
    dsu.join(u,it->fi);
    FOR(i,1,n)
    if (dsu.up[i]<0) {
        nComp++;
        compID[i]=nComp;
        compSZ[nComp]=-dsu.up[i];
    }
    FOR(u,1,n)
    FORE(it,Graph[u])
    if (most[it->se]) {
        int v=it->fi;
        int x=compID[dsu.find(u)];
        int y=compID[dsu.find(v)];
        derevo[x].push_back(y);
        derevo[y].push_back(x);
    }
}

void dfs(int u,int p) {
    treeSZ[u]=compSZ[u];
    nPair[u]=SQR(treeSZ[u]);
    FORE(it,derevo[u]) if (*it!=p) {
        int v=*it;
        dfs(v,u);
        treeSZ[u]+=treeSZ[v];
        nPair[u]+=nPair[v]+treeSZ[v]*compSZ[u];
    }
}

int maxProduct(const vector<int> &v) {
    iterme(i,v.size()+1) iterme(j,n+1) dp[i][j]=false;
    dp[0][0]=true;
    iterme(i,v.size()) iterme(j,n+1) if (dp[i][j]) {
        dp[i+1][j]=true;
        dp[i+1][j+v[i]]=true;
    }
    int res=0;
    int sum=0;
    FORE(it,v) sum+=*it;
    iterme(j,n+1) if (dp[v.size()][j]) res=max(res,j*(sum-j));
    return (res);
}

int chooseRoot(int u) {
    dfs(u,-1);
    vector<int> tmp;
    FORE(it,derevo[u]) tmp.push_back(treeSZ[*it]);
    return (nPair[u]+maxProduct(tmp));
}

void process(void) {
    int res=0;
    FOR(i,1,nComp) res=max(res,chooseRoot(i));
    printf("%d",res);
}

int main(void) {
    zagruz();
    zgruztree();
    process();
    return 0;
}
