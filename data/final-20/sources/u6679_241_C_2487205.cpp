#include <cstdio>
#include <complex>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

int nextint()
{
	int t;
	scanf("%d",&t);
	return t;
}

struct mirror
{
	double a,b;
	int score;
	mirror(double a=0, double b=0, int score=0):a(a),b(b),score(score){}
	bool operator<(const mirror& s) const
	{
		return a<s.a;
	}
};

int h=100;
int xl=0;
double xr=100000;

int solve(double hl, double hr, vector<mirror>& top, vector<mirror>& bottom)
{
	vector<mirror> v[2]={bottom,top};
	int res=0;
	for(int i=0;i<=400;i++)
	{
		double tanalpha[2];
		if(i%2==1)
		{
			tanalpha[1]=tanalpha[0]=xr/((i+1)*h+hl-hr);
		}
		else
		{
			tanalpha[1]=tanalpha[0]=xr/((i)*h+hl+hr);
		}
		REP(type,1)
		{
			int curcnt=0;
			int it[2]={0,0};
			double xx=hl*tanalpha[type];
			double x1;
			double P2=h*tanalpha[type];
			int j=0;
//			printf("%lf %lf\n",xx+(i)*P2,P2);
			for(;j<=i;j++)
			{
				x1=xx+P2*j;
				while(it[j%2]<v[j%2].size()&&v[j%2][it[j%2]].b<x1)
					it[j%2]++;
				if(it[j%2]==v[j%2].size()||v[j%2][it[j%2]].a>x1)
				{
					curcnt=-1000;
					break;
				}
				curcnt+=v[j%2][it[j%2]].score;
				it[j%2]++;
			}
			x1-=xx+P2*j;
			//if(curcnt>=0&&((i%2==1&&fabs(((xr-x1))*tanalpha[type]-hr)<1e-7)||(i%2==0&&fabs((xr-x1)/tanalpha[type]-h+hr)<1e-7)))
			{
				res=max(res,curcnt);
			}
		}
	}
	return res;
}

int main()
{
	vector<mirror> top,bottom;
	int hl=nextint();
	int hr=nextint();

	int n=nextint();
	REP(i,n)
	{
		int a, b,c;
		char buf[10];
		scanf("%d%s%d%d",&a,buf,&b,&c);
		if(buf[0]=='T')
			top.push_back(mirror(b,c,a));
		else
			bottom.push_back(mirror(b,c,a));
	}
	sort(top.begin(),top.end());
	sort(bottom.begin(),bottom.end());
	printf("%d\n",max(solve(hl,hr,top,bottom),solve(h-hl,h-hr,bottom,top)));
}
