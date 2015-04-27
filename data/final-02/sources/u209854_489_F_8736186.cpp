#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int const N=501;

int n,m,mod,map[N][N],one,two,v[N][N],dp[N][N];

int rec(int y, int curtwo, int curone)
{
    if(v[y][curtwo])
        return dp[y][curtwo];
    int res = 0;
    if(curone > 1)
    {
        res += (rec(y+1,curtwo,curone-2)*1LL*((curone*(curone-1))/2))%mod;
        res %= mod;
    }
    if(curtwo > 1)
    {
        res += (rec(y+1,curtwo-2,curone+2)*1LL*((curtwo*(curtwo-1))/2))%mod;
        res %= mod;
    }
    if(curtwo > 0 && curone > 0)
    {
        res += (rec(y+1,curtwo-1,curone)*1LL*(curone*curtwo))%mod;
        res %= mod;
    }
    v[y][curtwo]=1;
    return dp[y][curtwo] = res;
}

int main()
{
#ifdef _DEBUG
    freopen("in.in","r",stdin);
#endif
    scanf("%d %d %d",&n,&m,&mod);
    for(int i=0;i<m;++i)
    {
        getchar();
        for(int j=0;j<n;++j)
        {
            map[i][j]=(getchar()-48);
        }
    }
    
    for(int i=0;i<n;++i)
    {
        int cnt = 0;
        for(int j=0;j<m;++j)
        {
            cnt += map[j][i];
        }
        if(cnt == 1)
            one++;
        else
            if(cnt == 0)
                two++;
    }

    if(two*2 + one != (n-m)*2)
    {
        cout<<0;
        return 0;
    }

    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
        {
            dp[i][j]=0;
            v[i][j]=0;
        }
    v[n][0] = dp[n][0] = 1;
    rec(m, two, one);
    printf("%d",dp[m][two]);

    return 0;
}