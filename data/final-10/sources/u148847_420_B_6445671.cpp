#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
typedef __int64 ll;
const int MOD = 1000000007;
const int INF = 1000000007;
const int N = 101000;
char s[5];
int f[N],od,zt[N],qi[N],ki,qo[N],ko,u[N],tp[N],xp[N];
int main()
{
    int n,m,i,fr=0,ct=0,h;
    scanf("%d%d",&n,&m);
    for(h=0;h<m;h++)
    {
        int x;
        scanf("%s%d",s,&x);
        u[x]=true;
        tp[h]=(s[0]!='+');
        xp[h]=x;
    }
    int lst=-1;
    ct=0;
    for(h=0;h<m;h++)
    {
        int x=xp[h];
        if(tp[h]&&!zt[xp[h]])
        {
            if(ct)lst=-2;
            else lst=h;
        }
        if(tp[h])
        {
            if(zt[x])ct--;
            zt[xp[h]]=0;
        }
        else
        {
            ct++;
            zt[xp[h]]=1;
        }
    }
    //printf("lst:%d \n",lst);
    if(lst!=-2)
    {
        if(lst==-1)
        {
            ct=0;
            ki=xp[0];
            memset(zt,0,sizeof(zt));
            for(h=0;h<m;h++)
            {
                int x=xp[h];
                if(tp[h])
                {
                    ct--;
                    zt[xp[h]]=0;
                    if(x==ki&&ct)ki=-1;
                }
                else
                {
                    if(!ct&&x!=ki)ki=-1;
                    ct++;
                    zt[xp[h]]=1;
                }
            }
        }
        else
        {
            ct=0;
            ki=xp[lst];
            memset(zt,0,sizeof(zt));
            for(h=lst+1;h<m;h++)
            {
                int x=xp[h];
                if(tp[h])
                {
                    ct--;
                    zt[xp[h]]=0;
                    if(x==ki&&ct)ki=-1;
                }
                else
                {
                    if(!ct&&x!=ki)ki=-1;
                    ct++;
                    zt[xp[h]]=1;
                }
            }
        }
    }
    int ret=0;
    for(i=1;i<=n;i++)if(!u[i]||i==ki)ret++;
    printf("%d\n",ret);
    for(i=1;i<=n;i++)if(!u[i]||i==ki)printf("%d ",i);
    return 0;
}