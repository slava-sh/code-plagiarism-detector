#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cstdlib>

#define SC(x) scanf("%d",&x)
#define mp make_pair

using namespace std;
const int inf=2147483647, md=1e9+7;
const double eps=1e-7;

int n,m,i,j,k,l[200500],r[200500],K;
long long x[200500],C,D,t,sum,ans,sumtime;

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	scanf("%d%d%lld%lld",&n,&K,&C,&D);
	for (i=1; i<=n; ++i){
		SC(l[i]); SC(r[i]);
		sumtime+=r[i]-l[i];
		if (i>1) x[i-1]=l[i]-r[i-1];
	}
	sumtime*=D;
	sort(x+1,x+n);
	t=0;
	ans=(1ll<<63)-1;
	for (i=0; i<n; ++i){
		sum=t+((int)(n-i-1)/K)*C+sumtime;
		ans=min(ans,sum);
		t+=x[i+1]*D;
	}
	printf("%lld\n",ans);
	return 0;
}
