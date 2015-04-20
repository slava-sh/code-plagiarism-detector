#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n,d,a[100000],sum=0,ans=0;

int main()
{
 freopen("sochi.in", "r", stdin);
 freopen("sochi.out", "w", stdout);

 cin >> n >> d;

 for (int i = 1; i <= n; i++) {
 cin >> a[i];
 }
 if ( n == 2 ) {
 cout<<a[1]+a[2]-2*d;
 return 0;
 }

 int sum = a[1]+a[2]-2*d; 
 
 for (int i = 3; i <= n; i++) {
 if ( sum > d) {
 sum += a[i]-2*d;
 }
}
 if ( sum <= 0) {
 cout <<0;
 return 0;
 }
 cout <<sum;
 return 0;
 
}