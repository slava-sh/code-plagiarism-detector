#include<iostream>
#include<stdio.h>
#include<vector>
#include<ctime>
using namespace std;
int n;
int bubble(vector<int>&f){
	int res=0;
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(f[i]<f[j])
				res++;
	return res;
}
int main(){
	int ans,t=clock();
	pair<int,int>x=make_pair(-1,-1);
	scanf("%d",&n);
	vector<int>f(n);
	for(int i=0;i<n;i++)
		scanf("%d",&f[i]);
	ans=bubble(f);
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++){
			swap(f[i],f[j]);
			int e=bubble(f);
			if(e<ans){
				ans=e;
				x=make_pair(i+1,j+1);
			}
			swap(f[i],f[j]);
		}
	printf("%d %d",x.first,x.second);
}