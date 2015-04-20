#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

long long n,d,i,a[500000],j,last,ans;

main ()
 {
  freopen("sochi.in","r",stdin);
  freopen("sochi.out","w",stdout);
  cin>>n>>d;
  for (i=1;i<=n;i++)
   cin>>a[i];
  sort(a+1,a+n+1);
 ans=max(ans,a[n]);
 for (i=1;i<=n;i++)
  if (a[i] >= d) break;
 if (i > n) {cout<<ans<<endl; return 0;}
 for (j=i;j<=n;j++)
  if (a[j] >= 3*d) break;
 j--;
 j--;
 for (i=j;i<=n;i++)
  if (a[i] >= 2*d)
  {
   if (last == 0) { last=a[i]; ans=max(ans,last); continue;}
   last=last+a[i]-2*d;
   ans=max(ans,last);
  }
 cout<<ans<<endl;
 
 }
     
