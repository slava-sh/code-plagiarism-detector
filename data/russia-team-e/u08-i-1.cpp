#include <iostream>
#include <stdio.h>
int main(){
int n;
int d,s=0;
int summ;
int a[100000];
	freopen("sochi.in","r", stdin);
	freopen("sochi.out","w", stdout);
	scanf("%d %d", &n, &d);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);

	for(int i=1; i<=n; i++) s+=a[i];
	summ=s-((n-1)*2*d);
	printf("%d",summ);
}