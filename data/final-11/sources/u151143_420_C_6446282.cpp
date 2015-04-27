#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
const int N=3000005;
struct arr{
	int x,y;
}a[N];
int n,m,num[N];
long long tot=0;
bool cmp(arr x,arr y)
{
	if(x.x==y.x)return x.y<y.y;
	return x.x<y.x;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(a[i].x>a[i].y)swap(a[i].x,a[i].y);
		num[a[i].x]++;
		num[a[i].y]++;
		//b[i].x=i;
	}
	sort(a+1,a+n+1,cmp);
	//cout<<endl;
	for(int i=1;i<=n;i++){
		int p=1;
		while(a[i].x==a[i+1].x && a[i].y==a[i+1].y && i<n)i++,p++;
		//cout<<a[i].x<<" "<<a[i].y<<" "<<num[1]<<" "<<num[2]<<" "<<p<<endl;
		if(num[a[i].x]+num[a[i].y]-p<m && num[a[i].x]+num[a[i].y]>=m)tot--;
	}//cout<<tot<<endl;
	sort(num+1,num+n+1);
	int t=n+1;
	for(int i=1;i<=n;i++){
		//cout<<num[i]<<endl;
		while(t>1 && num[i]+num[t-1]>=m)t--;
		if(t>i)tot+=n-t+1;
		else tot+=n-i;
	}
	printf("%I64d\n",tot);

    //system("pause");
    return 0;
}
