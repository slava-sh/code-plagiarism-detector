#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <ctime>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#define ll long long
#define MAXN 100000
#define INF 100000000
#define pb push_back
#define pob pop_back
#define sz size()
#define eps 1e-6
#define fname ""
#define pof pop_front
#define mp make_pair
#define pus empty()
using namespace std;
long long a[300005];
int main ()
{
 freopen("sochi.in","r",stdin);
 freopen("sochi.out","w",stdout);
  long long n,d,ans=0,i,j,l=0;
cin>>n>>d;
for (i=1;i<=n;i++)cin>>a[i];
sort(a+1,a+n+1);
l=a[n];
ans=a[n];
for (i=n-1;i>=1;i--){
 if (l>ans)ans=l;
 if (a[i]-d>=d&&a[i+1]-2*d>=d){
  l-=d;
  l+=a[i]-d;
  if (l>ans)ans=l;
 }
  else break;
}
 cout<<ans;
 return 0;
}
