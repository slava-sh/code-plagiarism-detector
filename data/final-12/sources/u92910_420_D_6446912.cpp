#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define pb push_back
#define sz(x) (int)x.size()
#define scf scanf
#define ptf printf
#define fst first
#define scd second
#define forp(i,j,k) for(int i=j;i<k;i++)
#define form(i,j,k) for(int i=j;i>k;i--)
using namespace std;
typedef long long LL;

const int M=3e6+10;

int h[M],hps[M],pw[50],tr[M+10],used[M],hh[M];

void ud(int x,int v)
{
    if(!x){tr[0]+=v;return;}
    for(;x<M;x+=x&-x)tr[x]+=v;
}

int qy(int x)
{
    int res=tr[0];
    for(;x;x-=x&-x)res+=tr[x];
    return res;
}

int find(int x,int l,int r)
{
    int t0=qy(l);
    if(t0>=x)return l;
    for(int mid;;)
    {
        if(r-l<2)return r;
        mid=(l+r)/2;
        if(qy(mid)>=x)r=mid;else l=mid;
    }
}

int main()
{
    forp(i,0,30)pw[i]=1<<i;
    int n,q;
    scf("%d%d",&n,&q);
    int top=1e6;
    forp(i,0,n)
    {
        ud(top+i,1);
        hps[top+i]=i+1;
    }
    int ed=top+n+1,x,y,t0;
    memset(h,-1,sizeof(h));
    memset(hh,-1,sizeof(hh));
    memset(used,0,sizeof(used));

    int fg=0;
    forp(i,0,q)
    {
        scf("%d%d",&x,&y);
        t0=find(y,top,ed);
        if(h[hps[t0]]!=-1&&h[hps[t0]]!=x)
        {
            fg=1;break;
        }
        else
        {
            if(hh[x]!=-1&&hh[x]!=hps[t0]){fg=1;break;}
            h[hps[t0]]=x;
            hh[x]=hps[t0];
            used[x]=1;
        }
        ud(t0,-1);
        ud(--top,1);
        hps[top]=hps[t0];
    }
    if(fg){puts("-1");return 0;}
    //forp(i,1,n)ptf("%d ",h[i]);
    //ptf("%d\n",h[n]);
    int p=1;
    forp(i,1,n+1)
        if(h[i]==-1)
        {
            for(;used[p];p++);
            h[i]=p;used[p]=1;
        }
    forp(i,1,n)ptf("%d ",h[i]);
    ptf("%d\n",h[n]);
    return 0;
}
