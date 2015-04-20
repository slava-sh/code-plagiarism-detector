#include <stdio.h>
#include <iostream>
using namespace std;
__int64 d[100000000];
int main()
{__int64 r,n;
__int64 s;
int i;

	freopen("che.in","r", stdin);
	freopen("che.out","w", stdout);
	cin>>n>>r;
	for(i=1; i<=n; i++) cin>>d[i];
	s=d[n]/4;
	cout<<s;
}