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
int n,m;
int t[5555];
vector<pair<int,int > > g[5555];

int d[5555];

set<pair<int,int> > s;

int kol[3];
int st=1;

int main(){
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);//cin>>n>>m;
    for(i=1;i<=n;++i){
        scanf("%d",&t[i]);//cin>>t[i];
        kol[t[i]]++;
    }
    for(i=1;i<=m;++i){
        int l,r,d;
        scanf("%d%d%d",&l,&r,&d);//cin>>l>>r>>d;
        g[l].pb(mp(r,d));//c[l][r]=d;
        g[r].pb(mp(l,d));//c[r][l]=d;
    }
    if(kol[1]>kol[2])st=2;

    int a1,a2,a3=inf;
    for(int k=1;k<=n;++k){
        if(t[k]!=st)continue;
        for(i=1;i<=n;++i)
            d[i]=inf;
        d[k]=0;
        s.clear();
        s.insert(mp(0,k));
        //for(i=1;i<=n;++i)if()s.insert(mp(d[i],i));
        for(;!s.empty();){
            i=(s.begin()->S);
            s.erase(s.begin());
            if(d[i]==inf)break;
            if(t[i]==st && i!=k)continue;

            for(int j=0;j<sz(g[i]);++j){
                int to=g[i][j].F;
                if(t[to]!=st){
                    if(d[to]>d[i]+g[i][j].S){
                        if(s.count(mp(d[to],to)))s.erase(mp(d[to],to));
                        d[to]=d[i]+g[i][j].S;
                    }
                }
                if(t[to]==0){
                    s.insert(mp(d[to],to));
                }
            }
        }
        for(i=1;i<=n;++i){
            if(t[i]==3-st && d[i]<a3){a3=d[i];a1=k;a2=i;}
        }
    }
    if(a3==inf)cout<<-1;
    else cout<<a1<<' '<<a2<<' '<<a3;

    return 0;
}
