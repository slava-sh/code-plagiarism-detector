#include<iostream>
#include<map>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<fstream>
#include<math.h>
#include<utility>
#define INF 100000000
using namespace std;
struct o{
       int x,y;
       };
long long n,m,a[1000000]={0};
int main(){
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
  //   freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
    cin>>n>>m; long long s=0;
  if (m>3 && n>3) {cout<<1;return 0;}
  if (n==1 && m>=3) {cout<<1+(m-3)/4;return 0;}
  if (m==1 && n>=3) {cout<<1+(n-3)/4;return 0;};
  if (n==3 && m==3) {cout<<1;return 0;}
  cout<<0;
    return 0;
}
