#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stdio.h>

#define LL long long

using namespace std;

LL w,h,n,i,j,indi,indj,res,resi,resj,p,nowans,num;
char a[1100][1100],from[1100][1100];
LL ans[1100][1100];
string s;

void print(int ii,int jj)
 {
  while (ii != indi || jj != indj)
   {
    s+=from[ii][jj];
    if (from[ii][jj] == 'N') {ii++; continue;}
    if (from[ii][jj] == 'S') {ii--; continue;}
    if (from[ii][jj] == 'W') {jj++; continue;}
    if (from[ii][jj] == 'E') {jj--; continue;}
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
  res=500000;
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
    if (ans[i][j] <= n &&
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
  for (i=1;i<=w;i++)
   for (j=1;j<=h;j++)
    if (ans[i][j] <= n && a[i][j] == 'T')
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
     s.clear();
    print(resi,resj);
  reverse(s.begin(),s.end());
  
  cout<<s;
  if (p == 2)
   {
    if (resj < h && a[resi][resj+1] != 'T')
     {
      for (i=1;i<=num;i++)
       cout<<"EW";
      cout<<endl;
      return 0;
     }
    if (resj > 1 && a[resi][resj-1] != 'T')
     {
      for (i=1;i<=num;i++)
       cout<<"WE";
      cout<<endl;
      return 0;
     }
    if (resi > 1 && a[resi-1][resj] != 'T')
     {
      for (i=1;i<=num;i++)
       cout<<"NS";
      cout<<endl;
      return 0;
     }
    if (resi < w && a[resi+1][resj] != 'T')
     {
      for (i=1;i<=num;i++)
       cout<<"SN";
      cout<<endl;
      return 0;
     }
   }
  if (p == 3)
   {
    while (num > 0)
     {
      if (a[resi][resj-1] == 'T' && resj > 1) {cout<<"W"; resj--; num--; continue;}
      if (a[resi][resj+1] == 'T' && resj < h) {cout<<"E"; resj++; num--; continue;}
      if (a[resi-1][resj] == 'T' && resi > 1) {cout<<"N"; resi--; num--; continue;}
      if (a[resi+1][resj] == 'T' && resi < w) {cout<<"S"; resi++; num--; continue;}
     }
    cout<<endl;
   }
  if (p == 0) {while(true) {}}
 }

