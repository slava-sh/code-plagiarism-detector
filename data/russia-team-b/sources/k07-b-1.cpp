#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
//#include <>

using namespace std;
#define fname "che"

int n, m, i, j, d[333333], k, l;

long long ans;

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin>>n>>m;
	for (i=1; i<=n; i++)
		scanf("%d", &d[i]);
	l=1;
	for (i=1; i<=n; i++)
	{
		while (l<i && d[i]-d[l]>m) l++;
		ans+=(l-1);
	}
	cout<<ans;
		


	return 0;
}
