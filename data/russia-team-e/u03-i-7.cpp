#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100001];
int l=0;
bool boolcha(int a, int b)
{
  return a > b;
}
int main()
{
  int i,n,k,m, M;
  int t;
  __int64 s=0;
freopen("sochi.in", "r", stdin);
freopen("sochi.out", "w", stdout);
  cin>>n>>k;
    m=0; M=0;
  for(i=0;i<n;i++)
  {
    cin>>t;
    if (M < t) M=t;
    if (t <= 2*k) continue;
    if (t >= 3*k) m+=t-2*k;
                 else a[l++]=t;
  }
  sort(a, a+l, boolcha); 
  if (m==0)
  {
    if (l==0) s=0; 
       else
           if  (l==1) s=a[0]; 
               else
                  s=a[0]+a[1] - 2*k;
  }else
  {
    if (l==0) s=m+2*k; 
       else
             if (l==1) s=m+a[0];
                 else
                  s=m+a[0]+a[1] - 2*k;
  }
  if (s!=0) cout<<s; 
            else cout<<M;
  return 0;
}
