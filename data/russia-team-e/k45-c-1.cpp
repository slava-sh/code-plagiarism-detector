#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<set>
#include<map>

#define F first
#define S second
#define mp make_pair
#define pb push_back
#define sz(A) (int(A.size()))

using namespace std;
const int inf=1e9;
int n;
vector<int> g[222222];
int v1,v2;
int pa[222222],lep=0;

bool used[222222];
bool tr=0;
void dfs1(int v){
    used[v]=1;
    pa[lep++]=v;
    if(v==v2){tr=1;return;}
    for(int i=0;i<g[v].size();++i){
        if(!used[g[v][i]])
            dfs1(g[v][i]);
        if(tr)return;
    }
    lep--;
    //pa.pb(v);
}
int c[222222];
int now;
void dfs2(int v,int le){
    c[v]=le;
    used[v]=1;
    for(int i=0;i<g[v].size();++i){
        if(now!=0 && g[v][i]==pa[now-1])continue;
        if(now!=lep-1 && g[v][i]==pa[now+1])continue;
        if(used[g[v][i]])continue;
        dfs2(g[v][i],le+1);
        c[v]=max(c[v],c[g[v][i]]);
    }
}

int c2[222222];
int c1[222222];

int main(){
    freopen("dwarfs.in","r",stdin);
    freopen("dwarfs.out","w",stdout);
    int i,j,k;
    cin>>n;
    for(i=1;i<n;++i){
        int l,r;
        cin>>l>>r;
        g[l].pb(r);
        g[r].pb(l);
    }
    cin>>v1>>v2;
    for(i=1;i<=n;++i)used[i]=0;
    dfs1(v1);
    //cout<<v1<<' '<<v2<<endl;
    for(i=1;i<=n;++i)used[i]=0;
    for(i=0;i<lep;++i){
        now=i;
        dfs2(pa[i],1);
        //cout<<pa[i]<<' '<<c[pa[i]]<<endl;
    }
    c1[0]=c[pa[0]];
    for(int i=1;i<lep-1;++i){
        c1[i]=max(c1[i-1],i+c[pa[i]]);
    }
    c2[lep-1]=c[pa[lep-1]];
    j=0;
    for(int i=lep-2;i>0;--i){
        ++j;
        c2[i]=max(c2[i+1],c[pa[i]]+j);
    }
    int ans=0;
    for(i=0;i<lep-1;++i){
        ans=max(ans,min(c1[i],c2[i+1]));
    }
    cout<<ans;


    return 0;
}
