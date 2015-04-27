#include<math.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define oo 1000000000
#define pi 3.14159265359
#define zero(a) (abb(a)<=1e-7)
#define lowbit(a) ((a)&(-(a)))
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abb(a) ((a)>0?(a):(-(a)))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y2))
#define dj(x1,y1,x2,y2) ((x1)*(y1)+(y1)*(y2))
#define dis(x1,y1,x2,y2) sqrt(((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))

long gh[2][201]={0},gt[2][201]={0},dis[40001]={0},d[40001]={0},du[40001]={0},num[201][201]={0},head[40001]={0},e[16000001]={0},next[16000001]={0};
long totm=0;

long add(long a,long b)
{
   e[++totm]=b;
   next[totm]=head[a];
   head[a]=totm;
   du[b]++;
}

int main()
{
   long i,j,k,h,t,r,n,m,a,b,now,st=1,en=0,s=0;
   scanf("%ld%ld%ld%ld",&h,&t,&r,&n);
   for (i=1;i<=n;i++)
       scanf("%ld%ld",&gh[0][i],&gt[0][i]);
   scanf("%ld",&m);
   for (i=1;i<=m;i++)
       scanf("%ld%ld",&gh[1][i],&gt[1][i]);
   for (i=0;i<=r;i++)
      for (j=0;i+j<=r;j++)
         num[i][j]=++s;
   for (i=0;i<=r;i++)
      for (j=0;i+j<=r;j++)
      {
         for (k=1;k<=n&&k<=i;k++)
         {
            a=i-k+gh[0][k];
            b=j+gt[0][k];
            if (a+b<=r)
               add(num[a][b],num[i][j]);
         }
         for (k=1;k<=m&&k<=j;k++)
         {
            a=i+gh[1][k];
            b=j-k+gt[1][k];
            if (a+b<=r)
               add(num[a][b],num[i][j]);
         }
      }
   for (i=2;i<=s;i++)
      if (!du[i])
      {
         d[++en]=i;
         dis[i]=1;
      }
   while (st<=en)
   {
      now=d[st++];
      for (i=head[now];i;i=next[i])
      {
         du[e[i]]--;
         if (!du[e[i]])
         {
            dis[e[i]]=dis[now]+1;
            d[++en]=e[i];
         }
      }
   }
   if (dis[num[h][t]])
      printf("Zmey\n%ld\n",dis[num[h][t]]);
   else
   {
      d[st=en=1]=dis[1]=1;
      while (st<=en)
      {
         now=d[st++];
         for (i=head[now];i;i=next[i])
            if (!dis[e[i]])
            {
               dis[e[i]]=dis[now]+1;
               d[++en]=e[i];
            }
      }
      if (dis[num[h][t]])
         printf("Ivan\n%ld\n",dis[num[h][t]]-1);
      else
         printf("Draw\n");
   }
   return 0;
}
