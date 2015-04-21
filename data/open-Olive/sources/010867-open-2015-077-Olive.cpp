#include<stdio.h>
#include<iostream>
using namespace std;
int n,f[1000],u=0,ans,x=-1,y=-1;
int bubble(){
	int res=0;
	for(int i=1;i<n;++i)
		for(int j=0;j<i;++j)
			if(f[i]<f[j]){
				++res;
				++u;
				if(u==1000000000){
					printf("%d %d",x,y);
					exit(0);
				}
			}
	return res;
}
int main(){
	int ans,x=-1,y=-1;
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&f[i]);
	ans=bubble();
	for(int i=0;i<n-1;++i)
		for(int j=i+1;j<n;++j){
			swap(f[i],f[j]);
			int e=bubble();
			if(e<ans){
				ans=e;
				x=i+1;
				y=j+1;
			}
			swap(f[i],f[j]);
		}
	printf("%d %d",x,y);
}