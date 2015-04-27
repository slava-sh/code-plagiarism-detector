#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define pb push_back
#define mp make_pair
#define out(x) cout<<(#x)<<'='<<x<<endl
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
vector<map<int, int> > E;
vi x, y;
int deg[312345], CAP, pos[312345];
pii a[312345];
int cnt[800][800];
vi big;
inline bool Big(int x){
    return deg[x]>=CAP;
}
int main(){
    int n, p;
    scanf("%d%d", &n, &p);
    E.resize(n);
    x.reserve(n);
    y.reserve(n);
    REP(i,n){
        int xx, yy;
        scanf("%d%d", &xx, &yy);
        xx--; yy--;
        x.pb(xx); y.pb(yy);
        deg[xx]++; deg[yy]++;
    }
    CAP = sqrt(2*n);
    REP(i,n){
        if(!Big(x[i]))E[x[i]][y[i]]++;
        if(!Big(y[i]))E[y[i]][x[i]]++;
        if(Big(i)){pos[i]=big.size();big.pb(i);}
        else pos[i]=-1;
    }
    REP(i,n){
        int xx=x[i], yy=y[i];
        if(~pos[xx] && ~pos[yy]){
            cnt[pos[xx]][pos[yy]]++;
            cnt[pos[yy]][pos[xx]]++;
        }
    }
    LL ans=0;
    REP(i,big.size())REP(j,i){ //big and big
        if(deg[big[i]]+deg[big[j]]-cnt[i][j]>=p)
            ans+=2;
    }
    int m_small=n;
    REP(i,n){
        a[i].first=deg[i];
        a[i].second=i;
    }
    sort(a, a+n);
    for(int i=n-1; ~i; i--)
        if(a[i].first>=CAP)m_small=i;
    for(int l=0, r=n; l<n; l++){//small and any
        int i=a[l].second;
        int left=p-deg[i];
        for(; r>0 && a[r-1].first>=left; r--);
        if(Big(i))continue;
        map<int, int> &e=E[i];
        for(auto x: e){
            int j=x.first, comm=x.second;
            bool ok=(deg[j]+deg[i]-comm)>=p;
            if(deg[j]>=left && !ok){
                if(Big(j))ans-=2;
                else ans--;
            }
        }
        int t=0;
        if(r<=m_small){
            t=(n-m_small)*2;
            t+=m_small-r;
            if(r<=l)t--;
        } else {
            t=2*(n-r);
        }
        ans+=t;
    }
    ans/=2;
    cout<<ans<<endl;
}
