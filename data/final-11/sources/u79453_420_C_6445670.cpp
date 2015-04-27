#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const long long MAXN=2000005;
vector<long long> a[MAXN],b[MAXN];
#define lowbit(i) (i&-i)
long long n;
long long f[MAXN];
long long C[MAXN];
void add(long long x, long long v) {
	++x;
	for (; x <= n + 1; x += lowbit(x)) C[x] += v;
}
long long sum(long long x) {
	++x;
	long long res = 0;
	for (; x > 0; x -= lowbit(x))
		res += C[x];
	return res;
}

int main()
{
	long long p;cin>>n>>p;long long x,y;
	//Set(n);
	for(long long i=1;i<=n;i++){	
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
		f[x]++;f[y]++;
	}
	for(long long i=1;i<=n;i++)add(f[i],1);
	long long ans=0;
	for(long long i=1;i<=n;i++) {
		for(vector<long long>::iterator j=a[i].begin();j!=a[i].end();j++){
			long long x=*j;
			add(f[x],-1);
			--f[x];
			add(f[x],1);
		}
		long long tot=p-f[i];
		long long tmp=sum(n)-sum(tot-1);
		tmp-=(f[i]>=tot);
		ans+=tmp;
		for(vector<long long>::iterator j=a[i].begin();j!=a[i].end();j++){
			long long aid=*j;
			add(f[aid],-1);
			++f[aid];
			add(f[aid],1);
		}
		
	}
	cout<<ans/2<<endl;
	return 0;
}	