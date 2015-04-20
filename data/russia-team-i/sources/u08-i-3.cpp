#include <iostream>
#include <stdio.h>
long int n=0;
long int d=0,s=0;
long int summ=0;
long int a[100001];
int main(){

	freopen("sochi.in","r", stdin);
	freopen("sochi.out","w", stdout);
	scanf("%d %d", &n, &d);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);

	for(int i=1; i<=n; i++) s+=a[i];
	summ=s-((n-1)*2*d);
	printf("%d",summ);
}