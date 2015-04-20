#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int j, f[5001], y, n,m,i,inf=2000000000, ans=inf, color[100001], d[100001], q[100001], w[100001], e[100001];

int main()
{
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++)
        d[i]=inf;

    for(i=1;i<=n;i++)
    {
        cin>>color[i];
        if(color[i]==1)
        {
            d[i]=0;
            f[i]=i;
        }
    }

    for(i=0;i<m;i++)
        cin>>q[i]>>w[i]>>e[i];

    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
        {
            if(d[w[j]]>d[q[j]]+e[j])
            {
                d[w[j]]=d[q[j]]+e[j];
                f[w[j]]=f[q[j]];
            }
            if(d[q[j]]>d[w[j]]+e[j])
            {
                d[q[j]]=d[w[j]]+e[j];
                f[q[j]]=f[w[j]];
            }
        }

    for(i=1;i<=n;i++)
        if(d[i]<ans&&color[i]==2)
        {
            ans=d[i];
            y=i;
        }
    if(ans==inf)
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<f[y]<<" "<<y<<" "<<ans;
}
