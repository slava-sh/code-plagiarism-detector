#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <cstdlib>

#define SC(x) scanf("%d",&x)
#define mp make_pair
#define time success

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,a[1000500],s[4000500],mx,l,r,col,t,tm[4000500],time;

void add(int i){
	while (i<4000000){
		if (tm[i]!=time){
			tm[i]=time;
			s[i]=0;
		}
		s[i]++;
		i=((i-1)|i)+1;
	}
}

int get(int i){
	int ans=0;
	while (i){
		if (tm[i]!=time){
			tm[i]=time;
			s[i]=0;
		}
		ans+=s[i];
		i=i&(i-1);
	}
	return ans;
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(n);
	for (i=1; i<=n; ++i)
		SC(a[i]);
	l=r=mx=-1;
	time=0;
	for (i=1; i<n; ++i){
		col=0;
		for (j=i+1; j<=n; ++j){
			if (a[j]>a[i]) continue;
			t=col-get(a[j]);
			if (t>mx){
				mx=t;
				l=i;
				r=j;
			}
			add(a[j]);
			++col;
		}
		++time;
	}
	printf("%d %d\n",l,r);
	return 0;
}
