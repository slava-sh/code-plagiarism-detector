#include<iostream>
#include<fstream>
using namespace std;
int main()
{
   __int64 n, d, max, t=0, a, i, ans = 0;
   freopen("sochi.in", "r", stdin);
   freopen("sochi.out", "w", stdout);
   cin>>n>>d;
   max = 0; t = 0;
   for(i=0;i<n;i++){
      cin>>a;
      if(a > 2*d) { ans +=a; t++;}
      if(a > d && a<=2*d && a > max) max = a;
  }
  ans -= 2*d*t;
  ans += d;
  if(max != 0) ans += max - d; else ans += d;
  cout<<ans;
//   system("pause >> int");
   return 0;
}
