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

	for(int i=1; i<=n; i++) {
		if(i==1 | i==n)a[i]-=d;else a[i]-=d*2;

	summ+=a[i];
	}

	printf("%d",summ);
}