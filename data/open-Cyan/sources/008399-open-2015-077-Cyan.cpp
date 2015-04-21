#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct pt{
	long double x,y;
};
vector<vector<pt> >f;
int main(){
	int n;
	long double a,b;
	scanf("%Lf%Lf%d",&a,&b,&n);
	f.resize(n);
	for(int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		f[i].resize(l+1);
		for(int j=0;j<=l;j++)
			scanf("%Lf%Lf",&f[i][j].x,&f[i][j].y);
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			int ix=1,jx=1;
			char flag=2;
			for(long double x=a;x<=b;x+=0.1){
				while(x>f[i][ix].x)
					ix++;
				while(x>f[j][jx].x)
					jx++;
				char cur=0;
				long double y1=(f[i][ix].y-f[i][ix-1].y)/(f[i][ix].x-f[i][ix-1].x)*(x-f[i][ix-1].x)+f[i][ix-1].y,
							y2=(f[j][jx].y-f[j][jx-1].y)/(f[j][jx].x-f[j][jx-1].x)*(x-f[j][jx-1].x)+f[j][jx-1].y;
				if(y1>=y2)
					cur=1;
				if(flag==2)
					flag=cur;
				else
					if(flag!=cur){
						printf("No\n%d %d",i+1,j+1);
						return 0;
					}
			}
		}
		
	printf("Yes");
}