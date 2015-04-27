#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
#include <functional>
#include <numeric>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <set>
#include <stack>
#include <iterator>
#include <memory>
#include <utility>
#include <string>
#include <sstream>
 
using namespace std;
 
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define mset(a) memset(a,0,sizeof(a))
#define mmset(a) memset(a,-1,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
 
typedef double lf;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<lf,lf> pdd;
typedef pair<int,pii> pip;
typedef pair<pii,int> ppi;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<pii> vpii;
 
const int inf=1000000007;
const ll linf=1000000000000000000LL;
const ull ulinf=(1ULL<<63)-10ULL;
const lf eps=0.000001;
const lf pi=3.14159265358979323846;
 
template <class T> T abs(T a){return a>=0?a:-a;}
template <class T> int sign(T a){return a>eps?1:a<-eps?-1:0;}
template <class T> T sqr(T a){return a*a;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){T ret=a%b;if(ret<0)ret+=b;return ret;}
template <class T> T lowbit(T x){return x&-x;}
ll addmod(ll a,ll b,ll c){return ((a+b)%c+c)%c;}
ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}
ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}
ll modinv(ll a,ll b){return powmod(a,b-2LL,b);}
template <class T> void maxe(T &a,T b){if(a<b)a=b;}
template <class T> void mine(T &a,T b){if(a>b)a=b;}
int iszero(lf a){return a<=eps&&a>=-eps;}
 
template <class T> void geti(T &a){a=0;int b=0;char c;while((c=getchar())==' '||c=='\n');if(c=='-')b=1;else a=c-48;while((c=getchar())!=' '&&c!='\n')a=a*10+c-48;if(b)a=-a;}
 
void fileio_in_out(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
void fileio_txt(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}
 
//==================================================
 
#define DEBUG(X) 
 
const int N=100010;
const int M=2222222;
const int K=20;
const ll md=inf;
 
int test;
int n,m,k;
ll ans;
char s[N];
ll fac[N],finv[N];
ll dp[N],p10[N];

ll C(int n,int m)
{
    return fac[n]*finv[m]%md*finv[n-m]%md;
}

int main()
{
    //fileio_in_out();
    //fileio_txt();
    //ios::sync_with_stdio(false);cout<<setprecision(15);
    
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    
    if(k==0)
    {
        for(int i=1;i<=n;i++)
            ans=(ans*10+s[i]-'0')%md;
        printf("%I64d\n",ans);
        return 0;
    }
    fac[0]=1;
    p10[0]=1;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i%md;
        p10[i]=p10[i-1]*10%md;
    }
    finv[n]=modinv(fac[n],md);
    for(int i=n-1;i>=0;i--)
        finv[i]=finv[i+1]*(i+1)%md;
    for(int i=0;i<=n-k-1;i++)
    {
        dp[i]=p10[i]*C(n-i-2,k-1)%md;
        if(i)
            dp[i]=(dp[i]+dp[i-1])%md;
    }
    for(int i=1;i<=n;i++)
    {
        ll t=i==n?C(n-1,k):((n-k-1<n-i)?dp[n-k-1]:((dp[n-i-1]+p10[n-i]*C(i-1,k))%md));
        ans=(ans+t*(s[i]-'0'))%md;
    }
    
    printf("%I64d\n",ans);
    
    //system("pause");
    return 0;
}
