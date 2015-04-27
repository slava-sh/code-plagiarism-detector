#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;

struct pnt {
	int a,b;
}p[300005];

int num[300005],to[300005];

int cmp(pnt x,pnt y) {
	if(x.b==y.b) return x.a<y.a;
	return x.b<y.b;
}

int a[300005];

int n;

void upd(int x) {
	int i;
	for(i=x;i<=n;i+=(i&-i)) a[i]++;
}

int get(int x) {
	int ans=0,i;
	for(i=x;i>0;i-=(i&-i)) ans+=a[i];
	return ans;
}


int main() {
	int m,i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) {
		scanf("%d%d",&x,&y);
		if(x>y) swap(x,y);
		p[i].a=x; p[i].b=y;
		to[x]++; to[y]++;
	}
	sort(p,p+n,cmp);
	long long ans=0;
	for(i=0;i<n;i++) {
		int c=0;
		x=p[i].a; y=p[i].b;
		for(j=i;j<n&&p[j].a==x&&p[j].b==y;j++) c++;
		if(to[x]+to[y]-c>=m) ans++;
		if(to[x]+to[y]>=m) num[y]++;
		i=j-1;
	}
	for(i=1;i<=n;i++) {
		if(to[i]>=m) {
			ans+=i-1-num[i];
		}
		else {
			int t=m-to[i];
			int tmp;
			if(t==1) tmp=get(n);
			else tmp=get(n)-get(t-1);
			ans+=tmp-num[i];
		}
		if(to[i]) upd(to[i]);
	}
	printf("%I64d\n",ans);
}


		

	
	
