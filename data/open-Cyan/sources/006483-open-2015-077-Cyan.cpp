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
bool check(pt a, pt b, pt c, pt d){
	if(a>b)
		swap(a,b);
	if(c>d)
		swap(c,d);
	if(a>c)
		swap(a,c);
	return c!=b;
}
bool intersect(pt a, pt b, pt c, pt d){
	if(!area(a,b,c) && !area(a,b,d) && !area(c,d,a) && !area(c,d,b))
		return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && check(a,b,c,d);
	return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && 
		   area(a,b,c)*area(a,b,d)<0 && area(c,d,a)*area(c,d,b)<0;
}
vector<vector<pt> >f;
bool compare(int a, int b){
	return f[a][0].y+(double)(f[a][1].y-f[a][0].y)/2.0>f[b][0].y+(double)(f[b][1].y-f[b][0].y)/2.0;
}
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	f.resize(n);
	vector<int>t(n);
	for(int i=0;i<n;i++){
		t[i]=i;
		int l;
		scanf("%d",&l);
		for(int j=0;j<=l;j++){
			pt a;
			scanf("%d%d",&a.x,&a.y);
			if(f[i].size()>1 && !area(f[i][f[i].size()-2],f[i].back(),a))
				f[i].pop_back();
			f[i].push_back(a);
		}
	}
	sort(t.begin(),t.end(),compare);
	for(int i=1;i<n;i++)
		for(int j=1;j<f[t[i-1]].size();j++)
			for(int k=1;k<f[t[i]].size();k++){
				if(intersect(f[t[i-1]][j-1], f[t[i-1]][j], f[t[i]][k-1], f[t[i]][k])){
					printf("No\n%d %d",t[i-1]+1,t[i]+1);
					return 0;
				}
			}
	printf("Yes");
}