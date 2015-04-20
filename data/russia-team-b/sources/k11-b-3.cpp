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

 long long t = n;
 long long y = n;
 
 for (int i = y; i > 0; i--) {
 long long u = n;
 while (u >= 1) {
 if (a[t]-a[n] > r) {
 ans++;
// cout <<a[n]<<" ";
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
 