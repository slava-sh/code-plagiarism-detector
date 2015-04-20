#include<map>
#include<ctime>
#include<cmath>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>

#define y1 google
#define INF 2147483647
#define fname "fence"

using namespace std;

  int i,mn=INF,mx,n,k,x;

int main()	{
	freopen(fname".in","r",stdin);
	freopen(fname".out","w",stdout);

	cin>>n>>k;
	mx = k / n;

	 for(i = 1; i <= n; i++)
	 {
	      cin>>x;
	      mn = min(mn,x);
	 }
	 cout<<min(mn,mx);

	return 0;
}

