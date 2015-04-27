#include <iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#define INF 9999999
using namespace std;
struct list
{
    int mp[11][11];
}node[1100];
int maps[1100][1100];
int vis[1100];
int low[1100];
int pre[1100];
vector<int>vec[1100];
int n,m,k,w;
struct listt{int x,y;}as;
vector<listt>res;
int ans;
void dfs(int x,int pres)
{
   // cout<<x<<" "<<pres<<endl;
    if(vis[x])return;
    if(x==0)return;
    vis[x]=1;
    if(pres==-1)
    {
        as.x=x;
        as.y=0;
        res.push_back(as);
        ans+=n*m;
    }
    else if(maps[x][pres]*w>=n*m)
    {
        as.x=x;
        as.y=0;
        res.push_back(as);
        ans+=n*m;
    }
    else
    {
        as.x=x;
        as.y=pres;
        res.push_back(as);
        ans+=maps[x][pres]*w;
    }
    for(int i=0;i<vec[x].size();i++)
    {
        dfs(vec[x][i],x);
    }
}
int main()
{
    char str[1111];
    while(~scanf("%d%d%d%d",&n,&m,&k,&w))
    {
        ans=0;
        memset(node,0,sizeof(node));
        memset(maps,0,sizeof(maps));
        for(int i=1;i<=k;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%s",str);
                for(int k=1;k<=m;k++)
                {
                    node[i].mp[j][k]=str[k-1];
                }
            }
        }
        int p;
        for(int i=1;i<=k;i++)
        {
            vec[i].clear();
            maps[i][i]=INF+1;
            for(int j=i+1;j<=k;j++)
            {
                p=0;
                for(int a=1;a<=n;a++)
                {
                    for(int b=1;b<=m;b++)
                    {
                        if(node[i].mp[a][b]!=node[j].mp[a][b])p++;
                    }
                }
                maps[i][j]=maps[j][i]=p;
            }
        }

        int minn=INF;
        memset(vis,0,sizeof(vis));
        int ip=1;
        pre[1]=0;
        for(int i=2;i<=k;i++)
        {
            low[i]=maps[1][i];
            pre[i]=1;
        }
        int maxx;
        int pp;
        pp=-1;
        maxx=-1;
        int mp;
        while(1)
        {
            minn=INF;
            for(int i=1;i<=k;i++)
            {
                if(vis[i])continue;
                if(low[i]<minn)
                {
                    minn=low[i];
                    ip=i;
                }
            }
            if(minn==INF)break;
            //cout<<ip<<endl;
            vis[ip]=1;
            int y=low[ip]*w;
            if(maxx<y)
            {
                maxx=y;
                mp=ip;
            }
            for(int i=1;i<=k;i++)
            {
                if(vis[i])continue;
                if(low[i]>maps[ip][i])
                {
                    pre[i]=ip;
                    low[i]=maps[ip][i];
                }
            }
        }
        vec[0].clear();
        for(int i=1;i<=k;i++)
        {
           // cout<<i<<" "<<pre[i]<<endl;
            vec[pre[i]].push_back(i);
            vec[i].push_back(pre[i]);
        }
        memset(vis,0,sizeof(vis));
        res.clear();
        ans=0;
        dfs(mp,-1);
        cout<<ans<<endl;
        for(int i=0;i<res.size();i++)
        {
            printf("%d %d\n",res[i].x,res[i].y);
        }
    }
    return 0;
}
