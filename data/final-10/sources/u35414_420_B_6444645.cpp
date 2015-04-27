#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef pair<pii,char> entry;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define t first.first
#define d first.second
#define p second

#define pb push_back

const int inv=1000000000;
const int minv=-inv;

const int max_n=100010;
const int max_m=100010;

const entry noentry=entry(pii(-1,-1),'?');

int n,m;
char tmp[5]; int cid;
entry E[max_m+1];
entry first[max_n],last[max_n];

int curr;
int only;
bool res[max_n]={0};
int nres;

int main()
{
	gi(n); gi(m);

	fill(first,first+n,noentry);
	fill(last,last+n,noentry);

	forup(i,1,m+1)
	{
		gs(tmp); gi(cid); --cid;

		//cout<<"@@ "<<tmp[0]<<" "<<cid<<"\n";

		if(first[cid]==noentry) first[cid]=entry(pii(i,cid),tmp[0]);
		last[cid]=entry(pii(i,cid),tmp[0]);

		E[i]=entry(pii(i,cid),tmp[0]);
	}

	curr=0; only=-1;
	rep(i,n)
	{
		if(first[i]==noentry)
			res[i]=true;
		else if(first[i].p=='-')
			++curr;
	}

	/*rep(i,n)
		cout<<res[i]<<" ";
	pnl();*/

	if(curr==0)
		only=E[1].d;
	else
	{
		forup(i,1,m+1)
		{
			if(E[i].p=='-') --curr;
			else ++curr;

			if(curr==0)
			{
				only=E[i].d;
				break;
			}
		}
	}

	if(only!=(-1))
	{
		bool check=true;
		bool status;
		if(first[only].p=='-') status=true;
		else status=false;

		curr=0;
		rep(i,n)
			if(first[i].p=='-')
				++curr;

		if(curr>0 and (not status))
			check=false;
		else
		{
			forup(i,1,m+1)
			{
				if(E[i].p=='-') --curr;
				else ++curr;

				if(E[i].d==only) status=(not status);

				if(curr>0 and (not status))
				{
					check=false;
					break;
				}
			}
		}

		if(check)
			res[only]=true;
	}

	nres=0;
	rep(i,n)
		nres+=res[i];

	pin(nres);
	if(nres)
	{
		rep(i,n)
			if(res[i])
				pis(i+1);
		pnl();
	}
	
	return 0;
}