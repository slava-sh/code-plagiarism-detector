#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <cmath>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <map>
typedef long long LL;
typedef long double LD;
const double pi=acos(-1.0);
const double eps=1e-6;
#define INF 0x3f3f3f3f
#define lson l, m, rt<<1
#define rson m+1, r, rt<<1|1
typedef pair<int, int> PI;
typedef pair<int, PI>PP;
const LL mod=1e9+7;
//#pragma comment(linker, "/STACK:1024000000,1024000000")
LL quick(LL a, LL b){LL ans=1;while(b){if(b & 1)ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans%mod;}
//inline int read(){char ch=' ';int ans=0;while(ch<'0' || ch>'9')ch=getchar();while(ch<='9' && ch>='0'){ans=ans*10+ch-'0';ch=getchar();}return ans;}
//inline void print(LL x){printf(LLD, x);puts("");}
//inline void read(int &x){char c=getchar();while(c < '0') c=getchar();x=c-'0'; c=getchar();while(c >='0'){x=x*10+(c-'0'); c=getchar();}}
//inline void out(int x){if(x>9)out(x/10);putchar(x%10+'0');}

int sum[100100];
inline LL inverse(int n)
{
    return quick(n, mod-2);
}

LL C(int n, int b)
{
    if(n-b<b)
        b=n-b;
    LL res=1;
    for(int i=1; i<=b; i++)
    {
        res*=(n-i+1);
        res%=mod;
        res*=inverse(i);
        res%=mod;
    }
    return res;
}
int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    sum[0]=0;
    for(int i=1; i<=n; i++)
        sum[i]=sum[i-1]+s[i-1]-'0';
    LL res=0;
    LL tempC=C(n-2, k-1);
    LL tempC2=C(n-1,k);
    for(int i=1; i<=n-k; i++)
    {
        if(k>0)
            res=(res+tempC*sum[n-i]%mod*quick(10, i-1))%mod;
        tempC=tempC*inverse(n-i-1)%mod*(n-i-k)%mod;
        res=(res+tempC2*(s[n-i]-'0')%mod*quick(10, i-1))%mod;
        tempC2=tempC2*inverse(n-i)%mod*(n-i-k)%mod;
    }
    printf("%I64d\n", (res+mod)%mod);
}
