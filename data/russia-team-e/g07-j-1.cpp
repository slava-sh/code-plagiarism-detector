#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>

#define LL long long

using namespace std;

LL w,h,n,i,j,indi,indj,res,resi,resj,p,nowans,num;
char a[700][700],from[700][700];
LL ans[700][700];
string s;

void print(int i,int j)
 {
  while (i != indi || j != indj)
   {
    s+=from[i][j];
    if (from[i][j] == 'N') {i++; continue;}
    if (from[i][j] == 'S') {i--; continue;}
    if (from[i][j] == 'W') {j++; continue;}
    if (from[i][j] == 'E') {j--; continue;}
   }
 }

main ()
 {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>w>>h>>n;
  swap(w,h);
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
     {
      cin>>a[i][j];
      if (a[i][j] == 'V')
       {
        indi=i;
        indj=j;
       }
     }
  for (j=indj+1;j<=h;j++)
   {
    ans[indi][j]=ans[indi][j-1];
    from[indi][j]='E';
    if (a[indi][j] == 'T') ans[indi][j]++;
   }
  for (j=indj-1;j>=1;j--)
   {
    ans[indi][j]=ans[indi][j+1];
    from[indi][j]='W';
    if (a[indi][j] == 'T') ans[indi][j]++;
   }
  for (i=indi+1;i<=w;i++)
   {
    ans[i][indj]=ans[i-1][indj];
    from[i][indj]='S';
    if (a[i][indj] == 'T') ans[i][indj]++;
   }
  for (i=indi-1;i>=1;i--)
   {
    ans[i][indj]=ans[i+1][indj];
    from[i][indj]='N';
    if (a[i][indj] == 'T') ans[i][indj]++;
   }
  for (i=indi+1;i<=w;i++)
   for (j=indj+1;j<=h;j++)
    {
     if (ans[i-1][j] > ans[i][j-1])
      {
       from[i][j]='S';
       ans[i][j]=ans[i-1][j];
      } else
      {
       from[i][j]='E';
       ans[i][j]=ans[i][j-1];
      }
     if (a[i][j] == 'T') ans[i][j]++;
    }
  for (i=indi+1;i<=w;i++)
   for (j=indj-1;j>=1;j--)
    {
     if (ans[i-1][j] > ans[i][j+1])
      {
       from[i][j]='S';
       ans[i][j]=ans[i-1][j];
      } else
      {
       from[i][j]='W';
       ans[i][j]=ans[i][j+1];
      }
     if (a[i][j] == 'T') ans[i][j]++;
    }
  for (i=indi-1;i>=1;i--)
   for (j=indj-1;j>=1;j--)
    {
     if (ans[i+1][j] > ans[i][j+1])
      {
       from[i][j]='N';
       ans[i][j]=ans[i+1][j];
      } else
      {
       from[i][j]='W';
       ans[i][j]=ans[i][j+1];
      }
     if (a[i][j] == 'T') ans[i][j]++;
    }
  for (i=indi-1;i>=1;i--)
   for (j=indj+1;j<=h;j++)
    {
     if (ans[i+1][j] > ans[i][j-1])
      {
       from[i][j]='N';
       ans[i][j]=ans[i+1][j];
      } else
      {
       from[i][j]='E';
       ans[i][j]=ans[i][j-1];
      }
     if (a[i][j] == 'T') ans[i][j]++;
    }
  res=5000;
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
    { 
     if (ans[i][j] == n && abs(indi-i)+abs(indj-j) < res)
      {
       res=abs(indi-i)+abs(indj-j);
       resi=i;
       resj=j;
       p=1;
      }
    }
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
    if (ans[i][j] < n)
     {
      nowans=abs(indi-i)+abs(indj-j)+2*(n-ans[i][j]);
      if (nowans < res)
       {
        res=nowans;
        resi=i;
        resj=j;
        p=2;
        num=n-ans[i][j];
       }
     }
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
    if (ans[i][j] < n &&
      (a[i-1][j] == 'T' || a[i+1][j] == 'T' || a[i][j-1] == 'T' || a[i][j+1] == 'T') &&
       a[i][j] == 'T' )
       {
        nowans=abs(indi-i)+abs(indj-j)+n-ans[i][j];
        if (nowans < res)
         {
          res=nowans;
          resi=i;
          resj=j;
          p=3;
          num=n-ans[i][j];
         }
       }
  print(resi,resj);
  reverse(s.begin(),s.end());
  cout<<s;
  if (p == 1)
   {
    cout<<endl;
    return 0;
   }
  if (p == 2)
   {
    if (resj < h)
     {
      for (i=1;i<=num;i++)
       cout<<"EW";
      cout<<endl;
      return 0;
     }
    if (resj > 1)
     {
      for (i=1;i<=num;i++)
       cout<<"WE";
      cout<<endl;
      return 0;
     }
    if (resi > 1)
     {
      for (i=1;i<=num;i++)
       cout<<"NS";
      cout<<endl;
      return 0;
     }
    if (resi < w)
     {
      for (i=1;i<=num;i++)
       cout<<"SN";
      cout<<endl;
      return 0;
     }
   }
  if (p == 3)
   {
    indi=resi;
    indj=resj;
    while (num > 0)
     {
      if (a[indi][indj-1] == 'T') {cout<<"W"; indj--; num--; continue;}
      if (a[indi][indj+1] == 'T') {cout<<"E"; indj++; num--; continue;}
      if (a[indi-1][indj] == 'T') {cout<<"N"; indi--; num--; continue;}
      if (a[indi+1][indj] == 'T') {cout<<"S"; indi++; num--; continue;}
     }
    cout<<endl;
   }
 }
     
