#include <iostream>
#include <stdio.h>
__int64 n=0;
 __int64 d=0,s=0;
 __int64 summ=0;
__int64 a[100011];
int main(){

	freopen("sochi.in","r", stdin);
	freopen("sochi.out","w", stdout);
	scanf("%d %d", &n, &d);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);

	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++){
			if(a[i]>a[j]) {s=a[i];a[i]=a[j];a[j]=s; }
		};

	for(int i=1; i<=n; i++) {
		if((i==1) || (i==n))a[i]=a[i]-d;else{ a[i]=a[i]-(d*2);}

	summ+=a[i];
	}

	printf("%d",summ);
}