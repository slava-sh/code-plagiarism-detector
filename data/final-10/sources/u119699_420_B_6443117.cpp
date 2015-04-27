#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
int e[200005],next[200005],head[200005],p[200005],o,anss,ANS,ans[200005],v[200005],now;
int i,a[200005],n,m,st[100005][20],LG,j,Last;
bool FLAG;
char s[200005][5];
void add(int a,int b,int c)
{
    e[a]=c;
    next[a]=head[b];
    head[b]=a;
}
bool MIN(int l,int r)
{
    if (r==-1) r=m;
    int LG=int(log(r-l+1)/log(2)+0.000000001);
    return min(st[l][LG],st[r-(1<<LG)+1][LG]);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (i=1; i<=m; i++)
    {
        scanf("%s",s[i]);
        scanf("%d",&a[i]);
        if (s[i][0]=='-' && !p[a[i]]) p[a[i]]=1;
        if (s[i][0]=='+' && !p[a[i]]) p[a[i]]=2;
    }
    for (i=m; i>=1; i--) add(++o,a[i],i);
    for (i=1; i<=n; i++) if (p[i]==1) anss++;
    if (anss==0) v[0]=1;
    for (i=1; i<=m; i++)
    {
        if (s[i][0]=='+') anss++;
        if (s[i][0]=='-') anss--;
        if (anss==0) v[i]=1;
    }
    for (i=0; i<=m; i++) st[i][0]=v[i];
    LG=int(log(m+1)/log(2)+0.000000001);
    for (i=1; i<=LG; i++)
      for (j=0; j<=m; j++)
        if (j+(1<<i)-1<=m) st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]); else
          break;
    for (i=1; i<=n; i++)
    {
        now=head[i]; FLAG=true; Last=0;
        while (now!=0)
        {
            if (s[e[now]][0]=='-' && !MIN(e[now],e[next[now]]-1)) FLAG=false;
            if (s[e[now]][0]=='+' && !MIN(Last,e[now]-1)) FLAG=false;
            Last=e[now];
            now=next[now];
        }
        if (FLAG) ans[++ANS]=i;
    }
    cout<<ANS<<endl;
    for (i=1; i<=ANS; i++) printf("%d ",ans[i]);
    return 0;
}
