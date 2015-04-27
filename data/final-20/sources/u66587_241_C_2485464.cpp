#include<cstdio>
#include<cstdlib>
#include<cstring>
typedef long long int64;
int l[105],r[105],w[105],v[105],x[2]={0,100},hl,hr,n,i,ans;
bool bj[105];
char ch;
int64 cha(int64 x1,int64 y1,int64 x2,int64 y2)
{return x1*y2-x2*y1;}
void up(int&a,int b){if(a<b)a=b;}
void change(int&a,int b){if (b)a=200-a;else a=-a;}
int work(int k,int f)
{
    int i,j,nowl=hl,nowr=hr,ss=0;
    for (i=1;i<=k;i++)change(nowr,f),f=1-f;
    f=1-f;
    memset(bj,0,sizeof(bj));
    for (i=1;i<=k;i++)
    {
        for (j=1;j<=n;j++)
          if (w[j]==f&&!bj[j])
            if (f==0&&cha(100000,nowr-nowl,l[j],x[w[j]]-nowl)<=0&&
                cha(100000,nowr-nowl,r[j],x[w[j]]-nowl)>=0)
            {ss+=v[j];bj[j]=1;break;}
            else if (f==1&&cha(100000,nowr-nowl,l[j],x[w[j]]-nowl)>=0&&
                cha(100000,nowr-nowl,r[j],x[w[j]]-nowl)<=0)
            {ss+=v[j];bj[j]=1;break;}
        if (j<=n)change(nowl,f),change(nowr,f),f=1-f;
        else return 0;
    }
    return ss;
}
int main()
{
    scanf("%d%d%d",&hl,&hr,&n);
    for (i=1;i<=n;i++)scanf("%d %c%d%d",&v[i],&ch,&l[i],&r[i]),w[i]=ch=='T';
    for (i=n;i;i--)
      up(ans,work(i,0)),up(ans,work(i,1));
    printf("%d",ans);
    return 0;
}
