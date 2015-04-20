#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
   __int64 n, d, max, t=0, i, ans = 0,a[100005];
   freopen("sochi.in", "r", stdin);
   freopen("sochi.out", "w", stdout);
   cin>>n>>d;
   max = 0; t = 0;
   for(i=0;i<n;i++){
      cin>>a[i];
  }
  sort(a, a+n);
  ans = a[n-1];
  for(i=n-2; i>=0; i--){
    if(ans + a[i] > 2*d && a[i] > 2*d){
      ans += a[i]-2*d;
    }
  }
  cout<<ans;
//   system("pause >> int");
   return 0;
}
