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

int a,b,n,i,j,x[160400],cur,z,z1,k,comp[401][401];
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
	if (a.y[1]>b.y[1]) return true;
	if (a.y[1]<b.y[1]) return false;
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
	//sort(chain+1,chain+1+n,cmp);
	eps=1e-7;
	cur=1;
	while (!s.empty())
	{
		x[cur]=*s.begin();
		cur++;
		s.erase(s.begin());
	}
	for (i=1; i<=n; i++)
	{
		for (k=1; k<=chain[i].l+1; k++)
		{
			if (x[1]==chain[i].x[k])
			{
				d[i]=chain[i].y[k];
				break;
			}
			if (k!=1 && chain[i].x[k]>x[1] && chain[i].x[k-1]<x[1])
			{
				d[i]=get(i,k,x[1]);
				break;
			}
		}
	}
	for (i=1; i<=n; i++)
		for (j=i+1; j<=n; j++)
		{
			comp[j][i]=comp[i][j]=getz(d[i],d[j]);			
		}
	for (j=2; j<cur; j++)
	{
		for (i=1; i<=n; i++)
		{
			for (k=1; k<=chain[i].l+1; k++)
			{
				if (x[j]==chain[i].x[k])
				{
					d[i]=chain[i].y[k];
					break;
				}
				if (k!=1 && chain[i].x[k]>x[j] && chain[i].x[k-1]<x[j])
				{
					d[i]=get(i,k,x[j]);
					break;
				}
			}
		}
		for (i=1; i<=n; i++)
			for (k=i+1; k<=n; k++)
			{
				z=getz(d[i],d[k]);
				if ((comp[i][k]==1 && z==-1) || (comp[i][k]==-1 && z==1))
				{
					cout<<"No"<<endl;
					cout<<i<<' '<<k<<endl;
					return 0;
				}
				if (z!=0)
					comp[i][k]=comp[k][i]=z;
			}
    }
	
	
	cout<<"Yes"<<endl;
	
	return 0;
}



