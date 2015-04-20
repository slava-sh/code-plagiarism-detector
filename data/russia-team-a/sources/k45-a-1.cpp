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
#define ll long long

using namespace std;
const int inf=1e9;
ll b[1100];

int a[1111][1111];
int mod=1e9+7;
int p[1111];
ll ans=1;


int main(){
   freopen("binary.in","r",stdin);
   freopen("binary.out","w",stdout);
    int n,m,j,i;
    cin>>n;
    for(i=1;i<=n;i++)cin>>b[i],p[i]=-1;;

    for(i=2;i<=n;++i){
        if(b[i]==-1)continue;
        if(b[i]>i){cout<<0;return 0;}
        for(int j=0;j<b[i];++j){
            a[i+j][j+1]=1;
            a[j+1][i+j]=1;
        }
        a[i+b[i]][b[i]+1]=-1;
        a[b[i]+1][i+b[i]]=-1;
    }
    for(i=1;i<=n;++i){
        bool was=0;
        for(j=i-1;j>=1;--j){
            if(a[i][j]!=0 && p[j]!=-1 && p[i]==-1){
                if(a[i][j]==1)p[i]=p[j],was=1;
                else p[i]=1-p[j],was=1;
            }
            if(a[i][j]!=0 && p[j]!=-1 && p[i]!=-1){
                if(a[i][j]==-1 && p[i]==p[j])ans=0;
                if(a[i][j]==1 && p[i]!=p[j])ans=0;
            }
        }

        if(p[i]==-1)p[i]=1,ans=(ans*2ll)%mod;
    }
    cout<<ans;


    return 0;
}
