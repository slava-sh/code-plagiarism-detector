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

int a,b,n,i,j,x[500],cur,z,z1,k;
ld eps,d[500][500];
set <int> s;

struct mys
{
	int x[500],y[500],id,l;
}chain[500];

int get(int i,int j,int x)
{
	ld k,b,y;
	k=(ld)(chain[i].y[j]-chain[i].y[j-1])/(ld)(chain[i].x[j]-chain[i].x[j-1]);
	b=(ld)chain[i].y[j]-k*chain[i].x[j];
	y=(ld)k*x+b;
	return y;
}

bool cmp(mys a,mys b)
{
	if (a.y[1]>b.y[1]) return true;
	if (a.y[1]<b.y[1]) return false;
	return a.id<b.id;	
}

int getz(int x,int y)
{
	if (fabs(x-y)<=eps) return 0;
	if (x<y) return -1;
	return 1;
}

int main()
{
	//ios_base::sync_with_stdio(false);
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
		for (j=1; j<cur; j++)
		{
			for (k=1; k<=chain[i].l+1; k++)
			{
				if (x[j]==chain[i].x[k])
				{
					d[i][j]=chain[i].y[k];
					break;
				}
				if (k!=1 && chain[i].x[k]>x[j] && chain[i].x[k-1]<x[j])
				{
					d[i][j]=get(i,k,x[j]);
					break;
				}
			}
        }
	}
	for (i=1; i<n; i++)
	{
		z=getz(d[i][1],d[i+1][1]);
		
		for (j=2; j<cur; j++)
		{
			z1=getz(d[i][j],d[i+1][j]);
			if ((z==1 && z1==-1) || (z==-1 && z1==1))
			{
				cout<<"No"<<endl;
				cout<<i<<' '<<i+1<<endl;
				return 0;
			}	
			z=z1;
		}
	}
	cout<<"Yes"<<endl;
	
	return 0;
}



