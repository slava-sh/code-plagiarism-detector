#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long n,r,a[100000],ans=0;

int main()

{

 freopen("che.in", "r", stdin);
 freopen("che.out", "w", stdout);

 cin >> n >> r;

 for (int i = 1; i <= n; i++) {
 cin >>a[i];
 }

 long long t = n,i=1;
 long long y = n;
 long long  u = n;


 for (int i = y; i > 0; i--) {
 while (u >= 1) {
 if (a[t]-a[n] > r) {
 ans++;
 }
 n--;
 u--;
 }
 t--;
// cout <<a[i]<<" ";
 }
 cout <<ans;
  return 0;
}
 