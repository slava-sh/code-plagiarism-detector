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

int a,b,n,i,j,x;
ld eps,d[500];
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
	sort(chain+1,chain+1+n,cmp);
	eps=1e-7;
	while (!s.empty())
	{
		x=*s.begin();
		s.erase(s.begin());
		for (i=1; i<=n; i++)
		{
			for (j=1; j<=chain[i].l+1; j++)
			{
				if (x==chain[i].x[j])
				{
					d[i]=chain[i].y[j];
					break;
				}
				if (j!=1 && chain[i].x[j]>x && chain[i].x[j-1]<x)
				{
					d[i]=get(i,j,x);
				}
			}
		}
		for (i=1; i<n; i++)
		{
			if (!(d[i]<=d[i+1]+eps))
			{
				cout<<"No"<<endl;
				cout<<chain[i].id<<' '<<chain[i+1].id<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;

	return 0;
}



