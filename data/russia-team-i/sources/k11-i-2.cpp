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

 for (int i = 1; i <= n; i++) {
 sum += a[i];
}

 cout <<sum-((n-2)*2*d+2*d);

 return 0;
 
}