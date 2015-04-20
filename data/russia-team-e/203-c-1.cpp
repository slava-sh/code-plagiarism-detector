#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void build(int q, int w)
{
    sz++;
    go[sz]=w;
    next[sz]=last[q];
    last[q]=sz;
}

void dfs1(int v)
{
    used[v]=true;
    int res=0, first=0;
    int x=last[v];
    while(x>0)
    {
        int t=go[x];
        if(used[t]==false)
        {
            dfs(t);
            res=max(res, dp[t]);
            a[k++]=res;
        }
        x=next[x];
    }
    dp[v]=res+1;
}

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>q>>w;
        build(q,w);
        build(w,q);
    }
    cin>>v0>>u0;
    dfs1(v0);

}
