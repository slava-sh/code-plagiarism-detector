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

int f,s,n,i,mx,j,a[1000100],cur,b[1000100],x,c[1000100];

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (i=1; i<=n; i++)
	{
		cin>>a[i];
		b[a[i]]=fabs(a[i]-i);
		c[a[i]]=i;
	}
	mx=0;
	for (i=1; i<=n; i++)
		for (j=i+1; j<=n; j++)
		{
			x=b[i]+b[j]-fabs(i-c[j])-fabs(j-c[i]);
			if (x>mx)
			{
				mx=x;
				f=c[i];
				s=c[j];
				
			}
		}
	if (mx==0)
		cout<<-1<<' '<<-1<<endl;
	else
		cout<<f<<' '<<s<<endl;
	return 0;
}



