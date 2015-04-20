#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n,d,a[100000],ans=0;

int main()
{
 freopen("sochi.in", "r", stdin);
 freopen("sochi.out", "w", stdout);

 cin >> n >> d;

 for (int i = 1; i <= n; i++) {
 cin >> a[i];
 }

 for (int i = 2; i < n; i++) {
 a[i] = a[i]-2*d;
 ans += a[i];
}

 cout <<ans+a[1]+a[n]-2*d;

 return 0;
 
}