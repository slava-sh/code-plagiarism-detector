#include<stdio.h>
#include<string.h>

#define eps 1e-12

int t[128][3],b[128][3];
int n1,n2,n,h1,h2;
int v1[128],v2[128];

int main() {
	int i,j,k1,k2,k,d,ret=0,f;
	char tmp[4];

	scanf("%d %d %d",&h1,&h2,&n);
	n1=n2=0;
	for(i=0;i<n;i++) {
		scanf("%d %s",&d,tmp);
		if (tmp[0]=='F') {
			scanf("%d %d",&b[n2][0],&b[n2][1]);
			b[n2][2]=d;
			n2++;
		} else {
			scanf("%d %d",&t[n1][0],&t[n1][1]);
			t[n1][2]=d;
			n1++;
		}
	}
	for(i=0;i<n1-1;i++) for(j=i+1;j<n1;j++) if (t[i][0]>t[j][0]) {
		for(k=0;k<3;k++) d=t[i][k],t[i][k]=t[j][k],t[j][k]=d;
	}
	for(i=0;i<n2-1;i++) for(j=i+1;j<n2;j++) if (b[i][0]>b[j][0]) {
		for(k=0;k<3;k++) d=b[i][k],b[i][k]=b[j][k],b[j][k]=d;
	}

	for(i=1;i<=n;i++) {
		int y1;
		if (i&1) y1=200-h2+(i/2)*200; else y1=h2+(i/2)*200;
		double a=100000./(y1-h1);
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(j=f=1,d=k1=k2=0;j*100<y1 && f;j++) {
			double x=(j*100-h1)*a;
			if (j&1) {
				while(k1<n1 && t[k1][1]+eps<x) k1++;
				if (k1>=n1 || x+eps<t[k1][0] || v1[k1]) f=0;
				else v1[k1]=1,d+=t[k1][2];
			} else {
				while(k2<n2 && b[k2][1]+eps<x) k2++;
				if (k2>=n2 || x+eps<b[k2][0] || v2[k2]) f=0;
				else v2[k2]=1,d+=b[k2][2];
			}
		}
		if (f && d>ret) ret=d;

		if (i&1) y1=-h2-(i/2)*200; else y1=h2-(i/2)*200;
		a=100000./(h1-y1);
		memset(v1,0,sizeof(v1));
		memset(v2,0,sizeof(v2));
		for(f=1,j=d=k1=k2=0;j*100>y1 && f;j--) {
			double x=(h1-j*100)*a;
			if (j&1) {
				while(k1<n1 && t[k1][1]+eps<x) k1++;
				if (k1>=n1 || x+eps<t[k1][0] || v1[k1]) f=0;
				else v1[k1]=1,d+=t[k1][2];
			} else {
				while(k2<n2 && b[k2][1]+eps<x) k2++;
				if (k2>=n2 || x+eps<b[k2][0] || v2[k2]) f=0;
				else v2[k2]=1,d+=b[k2][2];
			}
		}
		if (f && d>ret) ret=d;
	}

	printf("%d\n",ret);
	return 0;
}