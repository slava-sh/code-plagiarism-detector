#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <fstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>
 
#pragma comment(linker, "/STACK:256000000")

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define EPS 1e-7
#define PI 3.1415926535897932384626433832795

using namespace std;

int aabs(int a){
	if (a<0) return -a;
	return a;
}


int main(){
	//freopen("input.txt","rt",stdin);
	//freopen("output.txt","wt",stdout);
	//cout.setf(ios::fixed);
	//cout.precision(6);
	ll hl,hr,n;
	cin>>hl>>hr>>n;
	ll a[113][4];
	for (int i=0;i<n;i++){
		char ch;
		cin>>a[i][0]>>ch>>a[i][2]>>a[i][3];
		a[i][1]=ch;
	}
	ll aans=0;
	for (ll i=-n-5;i<n+6;i++){
		ll y1=hl,y2=100ll*i+(i%2==0?(0ll+hr):(100ll-hr));
		ll cnt[113];
		memset(cnt,0,sizeof(cnt));
		ll ans=0;
		bool not_ans=0;
		if (i>=0){
			for (int j=1;j<=i;j++){
				bool pp=0;
				for (int k=0;k<n;k++){
					if ((a[k][1]=='T' && j%2!=0) || (a[k][1]=='F' && j%2==0)){
						if (a[k][2]*(y2-y1)<=100000ll*(100ll*j-y1) && 100000ll*(100ll*j-y1)<=a[k][3]*(y2-y1)){
							cnt[k]++;
							pp=1;
						}
					}
				}
				if (!pp) not_ans=1;
			}
		}
		else{
			for (int j=i+1;j<=0;j++){
				bool pp=0;
				for (int k=0;k<n;k++){
					if ((a[k][1]=='T' && j%2!=0) || (a[k][1]=='F' && j%2==0)){
						if (a[k][2]*(-y2+y1)<=100000ll*(-100*j+y1) && 100000ll*(-100*j+y1)<=a[k][3]*(-y2+y1)){
							cnt[k]++;
							pp=1;
						}
					}
				}
				if (!pp) not_ans=1;
			}
		}
		for (int j=0;j<n;j++){
			if (cnt[j]>1){
				ans=0;
				break;
			}
			if (cnt[j]==1){
				ans+=a[j][0];
			}
		}
		if (not_ans) ans=0;
		aans=max(aans,ans);
	}
	cout<<aans;
	return 0;
}