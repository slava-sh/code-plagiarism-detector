// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) for(int i=0; i<(int)n;i++)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define sortv(a) sort(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define DRT()  int t; cin>>t; while(t--)
#define DRI(n)  int n; cin>>n; 
#define DRII(n,m)  int n,m; cin>>n>>m; 
#define TRACE
using namespace std;

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);


#ifdef TRACE
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

#define trace1(x)
#define trace2(x, y)
#define trace3(x, y, z)
#define trace4(a, b, c, d)
#define trace5(a, b, c, d, e)
#define trace6(a, b, c, d, e, f)

#endif


typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;

LL DP[501][501];
int C[500];
int N,M,mod; 
LL nc2(int x)
{
    LL ret = x; ret*=(x-1); ret/=2; return ret%mod;
}
int main()
{
    cin>>N>>M>>mod;
    repi(i,M)
    {
        string s; cin>>s; repi(j,N) if(s[j]=='1') C[j]++;
    }
    int n = 0; int m = 0;
    repi(i,N){if(C[i]==0)n++; if(C[i]==1)m++; }
    DP[0][0] = 1;
    for(int s = 1; s<=N;s++)
    {
        for(int i=0; i<=s;i++)
        {
            int j = s-i;
            DP[i][j] = 0;
            if(i>0 && j>0) DP[i][j] += ((i*j)*DP[i-1][j])%mod;
            if(i>=2) DP[i][j] += (nc2(i)*DP[i-2][j+2]) % mod;
            if(j>=2) DP[i][j] += (nc2(j)*DP[i][j-2])%mod;
            DP[i][j]%=mod;
        }
    }
    cout<<DP[n][m]<<endl;
    return 0;
}

