#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
using namespace std;
typedef long long ll;

const int N = 2e5+5;

ll X1=277, X2=2887, M1 = 1777777777, M2 = 1444444447;

int h1[26][N];
int h2[26][N];
int f1[26][N];
int f2[26][N];
ll p1[N], p2[N];

char s[N], t[N];
int nx[26][N];
int u[333];

void get(int *h1, int *h2, int l, int r, ll&g1, ll&g2){
    g1 = h1[l] - h1[r+1]*p1[r-l+1]%M1;
    if(g1<0) g1+=M1;
    g2 = h2[l] - h2[r+1]*p2[r-l+1]%M2;
    if(g2<0) g2+=M2;
}

ll get(int *h1, int *h2, int l, int r){
    ll g1, g2;
    get(h1,h2,l,r,g1,g2);
    return (g1<<32) | g2;
}

int us[26];

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d%d",&n,&m);
    scanf("%s%s",&s,&t);
    
    int d = 0;
    string z;
    for(int i=0;i<m;++i){
        if(!u[t[i]]){
            u[t[i]] = 'a'+d;
            z+=t[i];
            ++d;
        }
    }
    //cout<<t<<endl;
    //cout<<z<<endl;
    
    for(int i=p1[0]=1;i<=n;++i) p1[i]=p1[i-1]*X1%M1;
    for(int i=p2[0]=1;i<=n;++i) p2[i]=p2[i-1]*X2%M2;
    
    ll t1 = 0, t2 = 0;
    for(int i=m-1;i>=0;--i){
        t1 = (t1*X1 + t[i])%M1;
        t2 = (t2*X2 + t[i])%M2;
    }
    
    for(int x=0;x<26;++x){
        h1[x][n] = 0;
        for(int i=n-1;i>=0;--i) h1[x][i] = ((s[i]==x+'a') + h1[x][i+1]*1LL*X1)%M1;
        h2[x][n] = 0;
        for(int i=n-1;i>=0;--i) h2[x][i] = ((s[i]==x+'a') + h2[x][i+1]*1LL*X2)%M2;
    }/*
    for(int x=0;x<26;++x){
        f1[x][m] = 0;
        for(int i=m-1;i>=0;--i) f1[x][i] = ((t[i]==x+'a') + f1[x][i+1]*1LL*X1)%M1;
        f2[x][m] = 0;
        for(int i=m-1;i>=0;--i) f2[x][i] = ((t[i]==x+'a') + f2[x][i+1]*1LL*X2)%M2;
    }*/
    
    int inf = 1e9;
    for(int x=0;x<26;++x){
        nx[x][n] = inf;
        for(int i=n-1;i>=0;--i) if(s[i]==x+'a') nx[x][i] = i; else nx[x][i] = nx[x][i+1];
    }
    
    vector<int> ans;
    for(int i=0;i+m<=n;++i){
        vector<pair<int,int>> v;
        for(int x=0;x<26;++x) v.push_back({nx[x][i], x});
        sort(v.begin(), v.end());
        
        bool ok = true;
        int c = 0;
        for(int j=0;j<=26;++j){
            if(j==26 || v[j].first>=i+m){
                c = j;
                break;
            }
        }
        if(c!=z.size()) continue;
        memset(us, -1, sizeof us);
        for(int j=0;j<c;++j){
            int x = z[j]-'a';
            int y = v[j].second;
            if(us[x]==-1) us[x] = y; else if(us[x]!=y) ok=false;
            if(us[y]==-1) us[y] = x; else if(us[y]!=x) ok=false;
        }
        if(!ok) continue;
        int l = i, r = i+m-1;
        ll s1 = 0;
        ll s2 = 0;
        for(int j=0;j<c;++j){
            ll g1, g2;
            get(h1[v[j].second], h2[v[j].second], l, r, g1, g2);
            s1 = (s1+g1*z[j])%M1;
            s2 = (s2+g2*z[j])%M2;
        }
        //cout<<s1<<' '<<s2<<' '<<t1<<' '<<t2<<endl;
        if(s1==t1 && s2==t2) ans.push_back(i);
        
    }
    
    printf("%d\n",ans.size());
    for(int i : ans) printf("%d ",i+1);
    
    return 0;
}

