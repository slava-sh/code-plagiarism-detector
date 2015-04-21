#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

int a,b,n,i,j,x[160400],cur,z,z1,k,comp[401],last[440],cur1,cur2,y1,y2;
ld eps,d[401];
set <int> s;

struct mys
{
	int x[401],y[401],id,l;
}chain[401];

ld get(int i,int j,int x)
{
	ld k,b,y;
	k=(ld)(chain[i].y[j]-chain[i].y[j-1])/(ld)(chain[i].x[j]-chain[i].x[j-1]);
	b=(ld)chain[i].y[j]-k*(ld)chain[i].x[j];
	y=(ld)k*x+b;
	return y;
}

bool cmp(mys a,mys b)
{
	cur1=1;
	cur2=1;
	while (cur1<=a.l+1 && cur2<=b.l+1)
	{
		if (a.x[cur1]==b.x[cur2])
		{
			y1=a.y[cur1];
			y2=b.y[cur2];
			cur1++;
			cur2++;
			if (y1>y2) return true;
			if (y1<y2) return false;
			continue;			
		}
		if (a.x[cur1]<b.x[cur2])
		{
			y1=a.y[cur1];
			y2=get(b.id,cur2,a.x[cur1]);
			cur1++;
			if (y1-eps>y2) return true;
			if (y1+eps<y2) return false;
			continue;
		}
		y1=get(a.id,cur1,b.x[cur2]);
		y2=b.y[cur2];
		cur2++;
		if (y1-eps>y2) return true;
		if (y1+eps<y2) return false;
		continue;		
	}
	return a.id<b.id;
}

int getz(ld x,ld y)
{
	if (fabs(x-y)<=eps) return 0;
	if (x<y) return -1;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>a>>b;
	cin>>n;
	for (i=1; i<=n; i++)
	{
		cin>>chain[i].l;
		for (j=1; j<=chain[i].l+1; j++)
		{
			cin>>chain[i].x[j]>>chain[i].y[j];					
			s.insert(chain[i].x[j]);
		}
		chain[i].id=i;
	}
	sort(chain+1,chain+1+n,cmp);
	eps=1e-7;
	cur=1;
	while (!s.empty())
	{
		x[cur]=*s.begin();
		cur++;
		s.erase(s.begin());
	}
	for (i=1; i<=n; i++)
		last[i]=1;
	for (i=1; i<=n; i++)
	{
		while (1)
		{
			if (x[1]==chain[i].x[last[i]])
			{
				d[i]=chain[i].y[last[i]];
				break;
			}
			if (last[i]!=1 && chain[i].x[last[i]]>x[1] && chain[i].x[last[i]-1]<x[1])
			{
				d[i]=get(i,last[i],x[1]);
				break;
			}
			last[i]++;
		}
	}
	for (i=1; i<n; i++)
		comp[i]=getz(d[i],d[i+1]);
	for (j=2; j<cur; j++)
	{
		for (i=1; i<=n; i++)
		{
			while (1)
			{			
				if (x[j]==chain[i].x[last[i]])
				{
					d[i]=chain[i].y[last[i]];
					break;
				}
				if (last[i]!=1 && chain[i].x[last[i]]>x[j] && chain[i].x[last[i]-1]<x[j])
				{
					d[i]=get(i,last[i],x[j]);
					break;
				}
				last[i]++;
		   	}
			
		}
		for (i=1; i<=n; i++)
		{
		
			z=getz(d[i],d[i+1]);
			if ((comp[i]==1 && z==-1) || (comp[i]==-1 && z==1))
			{
				cout<<"No"<<endl;
				cout<<chain[i].id<<' '<<chain[i+1].id<<endl;
				return 0;
			}
			if (z!=0)
				comp[i]=z;
		}
    }
	
	
	cout<<"Yes"<<endl;
	
	return 0;
}



