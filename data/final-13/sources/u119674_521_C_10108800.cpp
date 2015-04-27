#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<string>
#include<cassert>
#include<set>
#include<cstring>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define mp make_pair
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,b,a) for(int i = (b); i >= (a); --i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
const int maxn = 100000 + 5;
const int mod = 1e9 + 7;
ll A[maxn], rev[maxn];
char digit[maxn];
int sum[maxn];

inline ll add(ll a,ll b) { return (a + b) % mod; }
inline ll mul(ll a,ll b) { return a * b % mod; }

ll qpow(ll base, ll p)
{
    ll ret = 1;
    while (p) {
        if (p & 1) ret = mul(ret,base);
        base = mul(base,base);
        p >>= 1;
    }
    return ret;
}

void pre_init()
{
    A[0] = rev[0] = 1;
    rep(i,1,maxn) {
        A[i] = mul(A[i-1],i);
        rev[i] = qpow(A[i], mod-2);
    }
}

inline ll C(int n,int m)
{
    if (n < m) return 0;
    return mul(A[n],mul(rev[m],rev[n-m]));
}

int main()
{
    #ifdef ACM
        freopen("in.txt","r",stdin);
    #endif
    pre_init();
    int N, K; cin >> N >> K;
    scanf("%s",digit+1);
    rep(i, 1, N+1) sum[i] = sum[i-1] + digit[i] - '0';
    ll pw = 1;
    ll ans = 0;
    rep(i,1,N+1) {
        ll s = sum[N-i];
        ans = add(ans, mul(s,mul(pw, C(N-1-i,K-1))));
        ans = add(ans, mul(digit[N-i+1]-'0',mul(pw, C(N-1-i+1,K))));
        pw = mul(pw, 10);
    }
    cout << ans << endl;
}



