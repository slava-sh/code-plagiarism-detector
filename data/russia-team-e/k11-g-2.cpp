#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long n,m,ans,k=3;

int main()

{
 freopen("prizes.in", "r", stdin);
 freopen("prizes.out", "w", stdout);

 cin >> n >> m;
 
 cout <<(n+m-1)/3;

 return 0;
}