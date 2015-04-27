///===========================///
///                           ///
///    ID     : FlaminRage    ///
///    School : JU            ///
///                           ///
///===========================///

#include<bits/stdc++.h>

#define sz(a) ((int)a.size())
#define repv(i,a) for(int i=0;i<sz(a);i++)
#define revv(i,a) for(int i=sz(a)-1;i>=0;i--)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define countbit(x) __builtin_popcount(x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi (2.0*acos(0.0))
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define setinf(ar) memset(ar,126,sizeof ar)
#define in(a,x,y) (a>=x && a<=y)
#define out(a,x,y) (!in(a,x,y))
#define eq(a,b) (fabs(a-b)<eps)
#define less(a,b) (a+eps<b)
#define great(a,b) (a>b+eps)
#define xx first
#define yy second
#define root 1

#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))

#define LB(a,x) (lower_bound(all(a),x)-a.begin())
#define UB(a,x) (upper_bound(all(a),x)-a.begin())

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;

template< class T > inline T _sq(T a) { return a * a; }
template< class T > inline T _sqrt(T a) { return (T) sqrt( (double) a); }
template< class T, class X > inline T _pow(T a,X y) {T z=1; rep(i,1,y){z*=a;} return z; }
template< class T > inline T _gcd(T a,T b) {a=abs(a);b=abs(b); if(!b) return a; return _gcd(b,a%b);}
template< class T > inline T _lcm(T a,T b) {a=abs(a);b=abs(b); return (a/_gcd(a,b))*b;}

template< class T > inline T _extended(T a,T b,T &x,T &y) {a=abs(a);b=abs(b); T g,x1,y1; if(!b) {x=1;y=0;g=a; return g;} g=_extended(b,a%b,x1,y1); x=y1; y=x1-(a/b)*y1; return g;}

template< class T, class X > inline bool getbit(T a, X i) { T t=1; return ((a&(t<<i))>0); }
template< class T, class X > inline T setbit(T a, X i) { T t=1;return (a|(t<<i)); }
template< class T, class X > inline T resetbit(T a, X i) { T t=1;return (a&(~(t<<i))); }
template< class T, class X > inline T togglebit(T a, X i) { T t=1;return (a^(t<<i)); }

template< class T > void pv(T v) { repv(i,v) cout<<v[i]<<" "; cout<<endl; }

///========CONSTANT=========///
///  power    0123456789    ///
#define MX  ( 1000  +3 )
#define inf   2000000000
//#define MOD   1000000007

#define eps 1e-9
///=========================///

//template< class T,class X > inline T _bigmod(T n,X m){ull ret=1, a = n%MOD ; while(m){ if(m&1)ret=(ret*a)%MOD; m>>=1; a=(a*a)%MOD; }ret%=MOD;return (T)ret;}
//template< class T > inline T _modinv(T n) {return _bigmod(n,MOD-2);}

///===============///
///End of template///
///===============///

int n,m,MOD;

ll dp[MX][MX];

string s[MX];

ll go(int z,int o) {
    if(z<0 || o<0) return 0;
    if(!z && !o) return 1;
    ll &ret=dp[z][o];
    if(ret!=-1) return ret;
    ret=0;

    if(o>=2) ret = (ret + (ll)o*(o-1)/2ll * go(z,o-2))%MOD;
    if(z>=2) ret = (ret + (ll)z*(z-1)/2ll * go(z-2,o+2))%MOD;
    if(o>=1 && z>=1) ret = (ret + (ll)o*z*go(z-1,o))%MOD;

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>n>>m>>MOD;

    bool ok=true;

    rep(i,0,m-1) {
        cin>>s[i];
        int cnt=0;
        repv(j,s[i]) cnt+=s[i][j]=='1';
        ok&=cnt==2;
    }

    if(!ok) cout<<0<<endl;
    else {
        SET(dp);
        int z,o;
        z=o=0;
        rep(j,0,n-1) {
            int cnt=0;
            rep(i,0,m-1) {
                cnt+=s[i][j]=='1';
            }
            if(cnt==1) o++;
            else if(!cnt) z++;
        }

//        cerr<<z<<" "<<o<<endl;

        cout<<go(z,o)<<endl;
    }


return 0;
}
