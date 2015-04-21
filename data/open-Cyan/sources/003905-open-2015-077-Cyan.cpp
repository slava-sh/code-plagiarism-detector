#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
struct pt{
	int x,y,n;
};
inline int area(pt a, pt b, pt c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
inline bool intersect_1(int a, int b, int c, int d){
	if(a>b)
		swap(a,b);
	if(c>d)
		swap(c,d);
	return max(a,c)<=min(b,d);
}
bool intersect(pt a, pt b, pt c, pt d){
	return intersect_1(a.x,b.x,c.x,d.x) && intersect_1(a.y,b.y,c.y,d.y) && 
		   (long long)area(a,b,c)*area(a,b,d)<0 && (long long)area(c,d,a)*area(c,d,b)<0;
}
bool operator <(pt a, pt b){
	return a.x<b.x;
}
int main(){
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);
	vector<pt>t;
	vector<vector<pt> >f(n+1);
	for(int i=0;i<n;i++){
		int l;
		scanf("%d",&l);
		pt a;
		a.n=i+1;
		for(int j=0;j<=l;j++){
			scanf("%d%d",&a.x,&a.y);
			t.push_back(a);
		}
	}
	sort(t.begin(),t.end());
	for(int i=0;i<t.size();i++){
		if(i==5)
			i=i;
		if(!f[t[i].n].empty())
			for(int j=1;j<=n;j++)
				if(j!=t[i].n && f[j].size()>1)
					for(int k=1;k<f[j].size();k++)
						if(intersect(f[t[i].n].back(), t[i], f[j][k-1], f[j][k])){
							printf("No\n%d %d",t[i].n,j);
							return 0;
						}
		f[t[i].n].push_back(t[i]);
	}
	printf("Yes");
}