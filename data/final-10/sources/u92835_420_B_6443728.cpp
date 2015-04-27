#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int a,b;
int onl[100005],tmp[100005];
bool can[100005];

bool used[100005];
int lap[100005];
char is[100005][5];

int main()
{
    memset(onl,0,sizeof onl);
    memset(can,true,sizeof can);
    memset(used,false,sizeof used);
    scanf("%d%d",&a,&b);
    int olp=0;

    for (int i=0;i<b;i++)
    {
        scanf("%s%d",is[i],&tmp[i]);
        if (!used[tmp[i]])
        {
            if (is[i][0]=='+')onl[tmp[i]]=-1;
            else onl[tmp[i]]=1,olp++;
            used[tmp[i]]=true;
        }
    }//printf("%d\n",olp);
    for (int i=1;i<=a;i++)if (onl[i]==-1)lap[i]=-1;

    int lston=-1;
    for (int i=0;i<b;i++)
    {
        if (is[i][0]=='+')
        {
            if (olp!=0)can[tmp[i]]=false;
            onl[tmp[i]]=1;
            olp++;
            if (i-lap[tmp[i]]>1)can[tmp[i]]=false;
            lston=i;
        }
        else
        {
            if (olp>1)can[tmp[i]]=false;
            onl[tmp[i]]=-1;
            olp--;
            lap[tmp[i]]=i;
        }
    }
    for (int i=1;i<=a;i++)if (used[i])
    {
        if (onl[i]==-1&&lap[i]<lston)can[i]=false;
    }

    vector<int> ans;
    for (int i=1;i<=a;i++)
    {
        if (can[i])
        {
            ans.push_back(i);
        }
    }
    printf("%d\n",ans.size());
    for (int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
    return 0;
}
