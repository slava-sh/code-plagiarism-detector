#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include <iomanip>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<stack>
#include<cstring>
#include<map>
#include<set>
using namespace std;
int x[333333];
int y[333333];
vector<int> v[333333];
vector<int>::iterator it;
int main()
{
	int i,j,n,p;
	int s,e;
	int need;
	long long sum=0;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)
		x[i]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&s,&e);
		x[s]++;x[e]++;
		v[s].push_back(e);
		v[e].push_back(s);
	}
	for(i=1;i<=n;i++)
	{
		y[i-1]=x[i];
	}
	sort(y,y+n);
	j=n-1;
	for(i=0;i<n;i++)
	{
		if(y[i]*2>=p)
			sum--;
		while(y[i]+y[j]>=p&&j>=0)
			j--;
		sum+=n-j-1;
	}
	for(i=1;i<=n;i++)
	{
		s=i;
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			e=*it;
			if(x[s]+x[e]==p)
			{
				sum--;
			}
			x[e]--;
		}
		for(it=v[i].begin();it!=v[i].end();it++)
		{
			e=*it;
			x[e]++;
		}
	}
	cout<<sum/2<<endl;
	//system("pause");
    return 0;
}