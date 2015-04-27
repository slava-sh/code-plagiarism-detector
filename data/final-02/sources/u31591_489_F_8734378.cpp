#define filer() freopen("in.txt","r",stdin)
#define filew() freopen("out.txt","w",stdout)

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include <map>
#include<ctime>
#define INF 1<<29
#define SET(a, x) memset((a), (x), sizeof(a))
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define i64 ll
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))
#define MAX
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef vector<ll> VL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
const int inf=0x20202020;
const ll mod=1000000007;
const double eps=1e-9;
const double pi=3.1415926535897932384626;

const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}


template<class X>void debug(vector<X>&v){for(int i=0;i<v.size();i++)cout<<v[i]<<" ";cout<<endl;}

i64 N,M,MOD,nCr[510][510],DP[510][510];

string m[510];

i64 func(int two, int one)
{
    if(DP[two][one]!=-1)return DP[two][one];
    if(two==0 && one==0)return 1;

    i64 ans=0;
    if(two>=2)
    {
        ans+=(nCr[two][2]*func(two-2,one+2));
        ans%=MOD;
    }
    if(one>=2 )
    {
        ans+=(nCr[one][2]*func(two,one-2));
        ans%=MOD;
    }
    if(one>=1 && two>=1)
    {
        ans+=(nCr[one][1]*nCr[two][1]*func(two-1,one));
        ans%=MOD;
    }
    return DP[two][one]=ans;
}

int main()
{
    //filer();

    //freopen("","r",stdin);
    //freopen("","w",stdout);

    int i,j,k ,T,cas=0;
    //scanf("%d",&T);


    cin>>N>>M>>MOD;

    for(i=0;i<=500;i++)nCr[i][0]=1;
    for(i=0;i<=500;i++)nCr[i][i]=1;

    for(i=2;i<=500;i++)
    {
        for(j=1;j<i;j++)nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
    }


    SET(DP,-1);
    int two=0,one=0,cnt;
    bool t=1;
    for(i=0;i<M;i++)
    {
        cin>>m[i];
        cnt=0;
        for(j=0;j<m[i].size();j++)
        {
            if(m[i][j]==1)cnt++;
        }
        if(cnt>2)t=0;

    }
    if(!t)
    {
        cout<<0<<endl;
        return 0;
    }


    for(j=0;j<N;j++)
    {
        cnt=0;
        for(i=0;i<M;i++)
        {
            if(m[i][j]=='1')cnt++;
        }
        if(cnt==0)two++;
        else if(cnt==1)one++;
    }
    i64 ans=func(two,one);
    cout<<ans<<endl;
    return 0;
}
/*Test Cases


*/
