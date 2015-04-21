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

int a,b,n,i,j,x[160400],cur,z,z1,k,comp[401][401],last[440],cur1,cur2;
ld eps,d[401],y1,y2;
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
	//double time1=clock();
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
	eps=1e-7;
	for (i=1; i<=n; i++)
		for (j=i+1; j<=n; j++)
		{
			z=getz(chain[i].y[1],chain[j].y[1]);
			cur1=2;
			cur2=2;
			while (cur1<=chain[i].l+1 && cur2<=chain[j].l+1)
			{
				if (chain[i].x[cur1]==chain[j].x[cur2])
				{
					y1=chain[i].y[cur1];
					y2=chain[j].y[cur2];
					cur1++;
					cur2++;
					z1=getz(y1,y2);
					if ((z==1 && z1==-1)||(z==-1 && z1==1))
					{
						cout<<"No"<<endl;
						cout<<i<<' '<<j<<endl;
						return 0;
					}
					if (z1!=0) z=z1;
					continue;
				}
				if (chain[i].x[cur1]<chain[j].x[cur2])
				{
					y1=chain[i].y[cur1];
					y2=get(j,cur2,chain[i].x[cur1]);
					cur1++;
					z1=getz(y1,y2);
					if ((z==1 && z1==-1)||(z==-1 && z1==1))
					{
						cout<<"No"<<endl;
						cout<<i<<' '<<j<<endl;
						return 0;
					}
					if (z1!=0) z=z1;
					continue;
				}
				//y1=chain[i].y[cur1];
				//y2=get(j,cur2,chain[i].x[cur1]);
				y1=get(i,cur1,chain[j].x[cur2]);
				y2=chain[j].y[cur2];
				cur2++;
				z1=getz(y1,y2);
				if ((z==1 && z1==-1)||(z==-1 && z1==1))
				{
					cout<<"No"<<endl;
					cout<<i<<' '<<j<<endl;
					return 0;
				}
				if (z1!=0) z=z1;
				continue;
			}
		}
	
	
	cout<<"Yes"<<endl;
	
	return 0;
}



