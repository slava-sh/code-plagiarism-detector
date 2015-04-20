#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
  return a > b;
}
int main()
{
  int a[100011],i,n,k,m;
  __int64 s = 0;
  freopen("sochi.in", "r", stdin);
  freopen("sochi.out", "w", stdout);
  cin>>n>>k;
  for(i=0;i<n;i++) cin>>a[i];
  sort(a, a+n, cmp);
  m = s = a[0];
  for(i=1;i<n;i++)
  {
    if (m > 2*k && a[i] > 2*k) s+=a[i]-2*k, m=a[i]-k;
    else break;
  }
  cout<<s<<endl;
  return 0;
}

