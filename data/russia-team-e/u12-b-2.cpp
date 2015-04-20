#include<iostream>
#include<fstream>
using namespace std;
__int64 n, d, i, ind, ans = 0, a[300005]={0}, j;
int main()
{
   
   freopen("ch.in", "r", stdin);
   freopen("che.out", "w", stdout);
   cin>>n>>d;
   for(i=0;i<n;i++){
       cin>>a[i];
   }
   ind = 0;
   for(i=0;i<n;i++){
      for(j = ind;j<n;j++){
        if(a[j] - a[i] > d){
          ans += n - j;
          ind = j-1; break;
        }
      }
   }
   cout<<ans;
//   system("pause >> int");
   return 0;
}
