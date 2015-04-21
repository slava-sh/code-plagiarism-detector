#include<iostream>
#include<stdio.h>
#include<vector>
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
bool operator !=(pt a, pt b){
	return a.x!=b.x || a.y!=b.y;
}
bool operator ==(pt a, pt b){
	return a.x==b.x && a.y==b.y;
}
inline bool check(pt a, pt b, pt c, pt d){
	if(a>b)
		swap(a,b);
	if(c>d)
		swap(c,d);
	if(a>c){
		swap(a,c);
		swap(b,d);
	}
	if(a==b || c==d)
		return 0;
	return c!=d;
}
bool intersect(pt a, pt b, pt c, pt d){
	if(!area(a,b,d) && !area(a,b,d) && !area(c,d,a) && !area(c,d,b))
		return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && check(a,b,c,d);
	return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && 
		   area(a,b,c)*area(a,b,d)<0 && area(c,d,a)*area(c,d,b)<0;
}
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	vector<vector<pt> >f(n);
	for(int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		f[i].resize(l+1);
		for(int j=0;j<=l;j++)
			scanf("%d%d",&f[i][j].x,&f[i][j].y);
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			for(int k=1;k<f[i].size();k++)
				for(int l=1;l<f[j].size();l++)
					if(intersect(f[i][k-1], f[i][k], f[j][l-1], f[j][l])){
						printf("No\n%d %d",i+1,j+1);
						return 0;
					}
	printf("Yes");
}