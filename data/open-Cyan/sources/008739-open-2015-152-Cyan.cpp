#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct line
{
	long double x;
	long double y;
	long double x1;
	long double y1;
	int id;
};

bool is(line a,line b)
{
	if (a.x<b.x)
	{
		swap(a,b);
	}
	if (a.x1<=b.x)
		return false;
	if (a.x1>=b.x1)
	{
		if ((a.y-b.y)*(a.y1-b.y1)<0)
			return true;
		return false;
	}
	long double tt=a.y+(b.x-a.x)*(a.y1-a.y)/(a.x1-a.x);
	long double tt2=a.y1+(b.x1-a.x)*(a.y1-a.y)/(a.x1-a.x);
	if ((tt-b.y)*(tt2-b.y1)<0)
			return true;
		return false;
}
	

vector <line> x;
long double a,b;
int main()
{
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	
	cin>>a>>b;
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int l;
		cin>>l;
		for (int j=0;j<l;j++)
		{
			long double x1,x2,y1,y2;
			cin>>x1>>x2>>y1>>y2;
			line r;
			r.id=i;
			r.x=x1;
			r.x1=x2;
			r.y=y1;
			r.y1=y2;
			x.push_back(r);
		}
	}
	for (int i=0;i<x.size();i++)
		for (int j=0;j<i;j++)
		{
			if (is(x[i],x[j])==true)
				if (x[i].id!=x[j].id)
				{
					cout<<"No"<<endl;
					cout<<x[i].id+1<<" "<<x[j].id+1<<endl;
					return 0;
				}
		}
	cout<<"Yes"<<endl;
		
	return 0;
}