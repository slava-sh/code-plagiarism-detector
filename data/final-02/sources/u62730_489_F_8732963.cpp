#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>
#include <map>

#define foru(i,l,r) for(int i=l; i<=r; i++)
#define ford(i,r,l) for(int i=r; i>=l; i--)
#define vi vector < int >
#define pi pair < int, int >
#define pb push_back
#define ll long long

using namespace std;

const int MAXN = 505;

int M, N, P, a0, a1;
int d[MAXN];
int f[MAXN][MAXN];

void nhap()
{
    scanf("%d%d%d\n",&N,&M,&P);
    memset(d,0,sizeof(d));
    for(int i=1; i<=M; i++)
    {
        for(int j=1; j<=N; j++)
        {
            char c; scanf("%c",&c);
            d[j]+=(c-'0');
        }
        scanf("\n");
    }
}

void pre()
{
    a1=0; a0=0;
    for(int i=1; i<=N; i++)
    {
        a1+=(d[i]==1);
        a0+=(d[i]==0);
    }
}

int dp(int a1, int a0)
{
    if (a1==0&&a0==0)
        return 1;
    if (f[a1][a0]!=-1)
        return f[a1][a0];
    int res = 0;
    if (a1>=2)
    {
        int hs=((a1*(a1-1))/2)%P;
        int t=dp(a1-2,a0);
        res=(res+(hs*1ll*t)%P)%P;
    }
    if (a0>=2)
    {
        int hs=((a0*(a0-1))/2)%P;
        int t=dp(a1+2,a0-2);
        res=(res+(hs*1ll*t)%P)%P;
    }
    if (a1>=1&&a0>=1)
    {
        int hs=(a1*a0)%P;
        int t=dp(a1,a0-1);
        res=(res+(hs*1ll*t)%P)%P;
    }
    f[a1][a0]=res;
    return res;
}

void tinh()
{
    memset(f,255,sizeof(f));
    int res=dp(a1,a0);
    printf("%d\n",res);
}

int main()
{
    nhap();
    pre();
    tinh();
    return 0;
}
