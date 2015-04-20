#include <stdio.h>
#include <iostream>
using namespace std;
long long d[100000000];
long long d1[100000000];
int main()
{long long r,n;
long long s,j,i,c;
s=c=0;
	freopen("che.in","r", stdin);
	freopen("che.out","w", stdout);
	cin>>n>>r;
	for(i=1; i<=n; i++) cin>>d[i];
	j=1;
	for(i=n; i>=1; i--){
	d1[j]=d[i];j++;
	}

	for(i=1; i<=n; i++){
		s=d[i];
		for(j=1; j<=n; j++){
if(((s-d[j])>r) & (i!=j) )c=c+1;
	
		}
	}
		cout<<c;
		return 0;
}