#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#define fi first
#define se second
#define PA pair<int,int>
#define VI vector<int>
#define VP vector<PA >
#define mk(x,y) make_pair(x,y)
#define mo 1000000007
#define N 100010
#define int64 long long
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m;
int a[N],h[N],w[N],v[N],an;
char p[N];
inline int64 pow(int64 x,int64 y) {
	int64 an=1;
	for (;y;y/=2) {
		if (y&1) an=an*x%mo;
		x=x*x%mo;
	}
	return an;
}
inline int64 C(int n,int m) {
	if (n<0||n<m) return 0;
	return 1ll*h[n]*w[m]%mo*w[n-m]%mo;
}
int main() {
	h[0]=1; For(i,1,N-1) h[i]=1ll*h[i-1]*i%mo;
	w[N-1]=pow(h[N-1],mo-2);
	for (i=N-2;i>=0;i--) w[i]=1ll*w[i+1]*(i+1)%mo;
	v[0]=1; For(i,1,N-1) v[i]=1ll*v[i-1]*10%mo;
	
	scanf("%d%d%s",&n,&m,p+1);
	For(i,1,n) a[i]=a[i-1]+p[i]-'0';
	For(i,1,n) {
		an=(1ll*v[i-1]*a[n-i]%mo*C(n-i-1,m-1)+an)%mo;
		an=(1ll*v[i-1]*(p[n-i+1]-'0')%mo*C(n-i,m)+an)%mo;
	}
	printf("%d\n",an);
	return 0;
}
