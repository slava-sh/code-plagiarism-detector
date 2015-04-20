#include <stdio.h>
#include <iostream>
using namespace std;
int d[100000000];
int d1[100000000];
int main()
{ int r,n;
int s,j,i,c;
s=c=0;
	freopen("che.in","r", stdin);
	freopen("che.out","w", stdout);
	scanf("%d %d", &n, &r);
	for(i=n; i>=1; i--) scanf("%d",&d[i]);
	

	for(i=1; i<=n; i++){
		s=d[i];
		for(j=i; j<=n; j++){
if(((s-d[j])>r) & (i!=j) )c=c+1;
	
		
		}}
		printf("%d", c);
		return 0;
}