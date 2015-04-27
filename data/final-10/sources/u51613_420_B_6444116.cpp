#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#define Mod (1000000007LL)
#define eps (1e-10)
#define Pi (acos(-1.0))
using namespace std;
bool sign[100100];
int ans[100100],k,tot;
int a[100100];
bool f[100100];
int n,m;
struct Node
{
    char c[2];
    int id;
}node[100100];
int fuck;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(sign,true,sizeof(sign));
        memset(a,0,sizeof(a));
        memset(f,false,sizeof(f));
        tot=k=0;
        fuck=0;
        for(int i=1;i<=m;i++)
        scanf("%s%d",&node[i].c,&node[i].id);
        for(int i=1;i<=m;i++)
        {
            if(node[i].c[0]=='-')
            {
                if(!f[node[i].id])
                {
                    k++;
                }
            }
            f[node[i].id]=true;
            //else node[i].id
        }
        for(int i=1;i<=m;i++)
        {
            if(node[i].c[0]=='+')
            {
                if(k) sign[node[i].id]=false;//printf("%d %d...\n",i,node[i].id);}
                else
                {
                    if(!fuck) fuck=node[i].id;
                    else if(fuck!=node[i].id) sign[fuck]=sign[node[i].id]=false;
                   // printf("%d %d %d\n",i,fuck,node[i].id);
                }
                k++;
            }
            else
            {
                if(k>1) sign[node[i].id]=false;//printf("%d %d...\n",i,node[i].id);}
                else
                {
                    if(!fuck) fuck=node[i].id;
                    else if(fuck!=node[i].id) sign[fuck]=sign[node[i].id]=false;
                   // printf("%d %d %d,,,\n",i,fuck,node[i].id);
                }
                k--;
            }
        }
        for(int i=1;i<=n;i++)
        if(sign[i]) ans[++tot]=i;
        printf("%d\n",tot);
        for(int i=1;i<=tot;i++)
        printf("%d%c",ans[i],(i==tot)?'\n':' ');
    }
    return 0;
}
