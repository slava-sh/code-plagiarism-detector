//#pragma comment(linker, "/STACK:102400000,102400000")
#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned long long
#define eps 1e-11
#define NMAX 200005
#define MOD 1000000007
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
ll dp[2][505][505],c[505][505];
int cal[505];
int main()
{
#ifdef GLQ
    freopen("input.txt","r",stdin);
//    freopen("o4.txt","w",stdout);
#endif // GLQ
    int n,m;
    ll mod;
    scanf("%d%d%I64d",&n,&m,&mod);
    for(int i = 0; i <= 500; i++)
    {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++)
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
    }
    char tmp[505];
    for(int i = 1; i <= m; i++)
    {
        scanf("%s",tmp);
        for(int j = 0; j < n; j++) if(tmp[j] == '1')
            cal[j]++;
    }
    int t0=0,t1=0;
    for(int i = 0; i < n; i++)
    {
        if(cal[i] == 0) t0++;
        if(cal[i] == 1) t1++;
    }
    dp[0][t0][t1] = 1;
    ll sum = t0+t1;
    for(int p = m; p < n; p++)
    {
        for(int i = t0; i >= 0; i--)
            for(int j = 0; j <= sum-i; j++) if(dp[0][i][j] != 0)
            {
                ll d = dp[0][i][j];
                if(i >= 2) dp[1][i-2][j+2] = (dp[1][i-2][j+2]+(d*c[i][2])%mod)%mod;
                if(i >= 1 && j >= 1) dp[1][i-1][j] = (dp[1][i-1][j]+((d*(ll)i)%mod*(ll)j)%mod)%mod;
                if(j >= 2) dp[1][i][j-2] = (dp[1][i][j-2]+(d*c[j][2])%mod)%mod;
            }
        memcpy(dp[0],dp[1],sizeof(dp[1]));
        memset(dp[1],0,sizeof(dp[1]));
    }
    printf("%I64d\n",dp[0][0][0]);
    return 0;
}
