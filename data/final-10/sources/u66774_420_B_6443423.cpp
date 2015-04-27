#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
char s1[3];
set<int>s;
set<int>st;
int f[100100];
int used[100100];
int jud[100100];
int cnt;
int main()
{
    int n,m,i,j,k,l,flag;
    scanf("%d%d",&n,&m);
    memset(used,0,sizeof(used));
    cnt=0;
    flag=0;
    for (i=1;i<=n;i++)
        f[i]=1;
    for (i=1; i<=m; i++)
    {
        scanf("%s%d",s1,&k);
        used[k]=1;
        if (s1[0]=='+')
        {
            if (!s.empty()||(flag==1&&cnt!=k)) f[k]=0;
            s.insert(k);flag=1;
            if (f[k])st.insert(k);
            if (cnt>0)
            {
                if (cnt!=k)f[cnt]=0;
                cnt=0;
            }
        }
        else
        {
            flag=1;
            if (cnt>0)
            {
                f[cnt]=0;
                cnt=0;
            }
            if (s.find(k)!=s.end())
            {
                s.erase(k);
            }
            else
            {
                while (!st.empty())
                {
                    int u=*(st.begin());
                    f[u]=0;
                    st.erase(u);
                }
            }
            if (!s.empty())f[k]=0;
            else cnt=k;
        }
    }
    int ans=0;
    for (i=1; i<=n; i++)
    {
        if (f[i]==1)ans++;
    }
    printf("%d\n",ans);
    for (i=1; i<=n; i++)
    {
        if (f[i]==1)printf("%d ",i);
    }
    printf("\n");
}
