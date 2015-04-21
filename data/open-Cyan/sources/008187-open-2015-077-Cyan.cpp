#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct pt{
	int x,y;
};
inline long long area(pt a, pt b, pt c){
	return ((long long)b.x-a.x)*(c.y-a.y)-(long long)(b.y-a.y)*(c.x-a.x);
}
inline bool intersect_1(int a, int b, int c, int d){
	if(a>b)
		swap(a,b);
	if(c>d)
		swap(c,d);
	return max(a,c)<=min(b,d);
}
bool operator >(pt a, pt b){
	if(a.x==b.x)
		return a.y>b.y;
	return a.x>b.x;
}
bool operator ==(pt a, pt b){
	return a.x==b.x && a.y==b.y;
}
bool operator !=(pt a, pt b){
	return a.x!=b.x || a.y!=b.y;
}
bool intersect(pt a, pt b, pt c, pt d){
	return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && 
		   area(a,b,c)*area(a,b,d)<0 && area(c,d,a)*area(c,d,b)<0;
}
bool par(pt a, pt b, pt c, pt d){
	return !area(a,b,c) || !area(a,b,d) || !area(c,d,a) || !area(c,d,b);
}
vector<vector<pt> >f;
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	f.resize(n);
	vector<int>t(n);
	for(int i=0;i<n;i++){
		t[i]=i;
		int l;
		scanf("%d",&l);
		f[i].resize(l+1);
		for(int j=0;j<=l;j++)
			scanf("%d%d",&f[i][j].x,&f[i][j].y);
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			int ix=1,jx=1;
			char flag=2;
			for(long double x=a;x<=b;x+=0.5){
				while(x>(long double)f[i][ix].x)
					ix++;
				while(x>(long double)f[j][jx].x)
					jx++;
				char cur=0;
				int y1=(long double)(f[i][ix].y-f[i][ix-1].y)/(long double)(f[i][ix].x-f[i][ix-1].x)*(long double)(x-f[i][ix-1].x)+(long double)f[i][ix-1].y,
					y2=(long double)(f[j][jx].y-f[j][jx-1].y)/(long double)(f[j][jx].x-f[j][jx-1].x)*(long double)(x-f[j][jx-1].x)+(long double)f[j][jx-1].y;
				if(y1>y2)
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