#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cout<<#x<<":"<<x<<"\n"
#define lim 101

int ll,r,n,num,den,i,y,j,mx,s,k;
char t;
int S[lim],A[lim],B[lim],C[lim];
char T[lim];

void f()
{
  for(i=1;i<=n;i++)
  {
    if(i&1)
    {
      y=100-r;
      t='T';
    }
    else
    {
      y=r;
      t='F';
    }
    y+=i*100;
    j=i;
    memset(C,0,sizeof C);
    s=0;
    while(j)
    {
      num=(j*100-ll)*100000;
      den=y-ll;
      if(den<0)
      {
        num*=-1;
        den*=-1;
      }
      for(k=0;k<n;k++)
        if(T[k]==t && A[k]*den<=num && B[k]*den>=num)
          break;
      if(k==n)
        break;
      C[k]++;
      s+=S[k];
      if(C[k]>1)
        break;
      if(j>0)
        j--;
      else
        j++;
      if(t=='F')
        t='T';
      else
        t='F';
    }
    if(!j)
      mx=max(mx,s);
  }
}
int main()
{
  scanf("%d%d%d",&ll,&r,&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&S[i]);
    cin>>T[i];
    scanf("%d%d",&A[i],&B[i]);
  }
  f();
  for(i=0;i<n;i++)
    if(T[i]=='F')
      T[i]='T';
    else
      T[i]='F';
  ll=100-ll;
  r=100-r;
  f();
  printf("%d\n",mx);
  return 0;
}
