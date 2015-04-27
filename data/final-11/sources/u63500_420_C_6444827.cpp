#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

const int MAX_N=300000+10;

int a[MAX_N];
int t[MAX_N];

vector <int> G[MAX_N];

int mm[MAX_N][2];

int main(){
	long long n,p;
	cin>>n>>p;
	for(long long i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		mm[i][0]=x;
		mm[i][1]=y;
		a[x]++;
		a[y]++;
		G[x].push_back(i);
		G[y].push_back(i);
	}
	for(int i=1;i<=n;i++){
		t[a[i]+1]-=1;
	}
	int x=n;
	for(int i=0;i<=n;i++){
		x+=t[i];
		t[i]=x;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<G[i].size();j++){
			int x=mm[G[i][j]][0];
			if(x==i){
				x=mm[G[i][j]][1];
			}
			t[a[x]]-=1;
			a[x]--;
		}
		int y=p-G[i].size();
		y=max(y,0);
		if(a[i]>=y){
			ans+=t[y]-1;
		}else{
			ans+=t[y];
		}
		for(int j=0;j<G[i].size();j++){
			int x=mm[G[i][j]][0];
			if(x==i){
				x=mm[G[i][j]][1];
			}
			a[x]++;
			t[a[x]]+=1;
		}
	}
	cout<<ans/2<<endl;
}

