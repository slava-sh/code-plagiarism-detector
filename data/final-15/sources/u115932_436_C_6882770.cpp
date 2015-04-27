//#pragma comment(linker,"/STACK:102400000,102400000")
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
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
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
template <class T> T sqr(T a){return a*a;}
template <class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template <class T> T mod(T a,T b){return (a%b+b)%b;}
template <class T> T lowbit(T x){return x&-x;}
ll addmod(ll a,ll b,ll c){return ((a+b)%c+c)%c;}
ll mulmod(ll a,ll b,ll c){if(b==0LL)return 0LL;ll ret=mulmod(a,b>>1,c);ret=(ret+ret)%c;if(b&1LL)ret=(ret+a)%c;return ret;}
ll powmod(ll a,ll b,ll c){if(b==0LL)return 1LL;ll ret=powmod(a,b>>1,c);ret=ret*ret%c;if(b&1LL)ret=ret*a%c;return ret;}
ll modinv(ll a,ll b){return powmod(a,b-2LL,b);}
template <class T> void maxe(T &a,T b){if(a<b)a=b;}
template <class T> void mine(T &a,T b){if(a>b)a=b;}
int iszero(lf a){return abs(a)<=eps;}

template <class T> void geti(T &a){a=0;T b=1;char c=getchar();if(c=='-')b=-1;else a=c-48;while((c=getchar())!=' '&&c!='\n')a=a*10+c-48;a*=b;}

void fileio_in_out(){freopen(".in","r",stdin);freopen(".out","w",stdout);}
void fileio_txt(){freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);}

//==================================================

#define DEBUG(X) 

const int N=2222;
const int M=2222222;
const int K=33;
const ll md=inf;

int test;
int n,m,k,ans;
int w;
char str[N][22][22];
int a[N][N];
int d[N],f[N],vis[N];
set<pii> s;
vi v[N];

void work()
{
    while(s.size()>0)
    {
        pii t=*s.begin();
        int x=t.Y,dis=t.X;
        ans+=dis;
        //printf("%d %d\n",x,ans);
        v[f[x]].pb(x);
        vis[x]=1;
        s.erase(mp(d[x],x));
        for(int y=1;y<=k;y++)
            if(!vis[y]&&d[y]>a[x][y])
            {
                s.erase(mp(d[y],y));
                d[y]=a[x][y];
                s.insert(mp(d[y],y));
                f[y]=x;
            }
    }
}

void dfs(int x)
{
    for(int i=0;i<v[x].size();i++)
    {
        int y=v[x][i];
        printf("%d %d\n",y,x);
        dfs(y);
    }
}

int main()
{
    //fileio_in_out();
    //fileio_txt();
    //ios::sync_with_stdio(false);
    
    scanf("%d%d%d%d",&n,&m,&k,&w);
    for(int l=1;l<=k;l++)
        for(int i=1;i<=n;i++)
            scanf("%s",str[l][i]+1);
    
    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++)
        {
            for(int x=1;x<=n;x++)
                for(int y=1;y<=m;y++)
                    if(str[i][x][y]!=str[j][x][y])
                    {
                        a[i][j]+=w;
                        a[j][i]+=w;
                    }
        }
    for(int i=1;i<=k;i++)
        d[i]=n*m;
    for(int i=1;i<=k;i++)
        s.insert(mp(d[i],i));
    ans=0;
    work();
    
    printf("%d\n",ans);
    dfs(0);
    
    //system("pause");
    return 0;
}
