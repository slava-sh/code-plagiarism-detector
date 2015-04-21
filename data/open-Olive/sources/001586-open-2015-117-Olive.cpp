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

int f,s,mn,i,j,n,pref[5050][5050],suff[5050][5050],a[5050],cur,x;

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
			pref[i][j]=suff[i][j]=0;
	}
	for (i=1; i<=n; i++)
	{
		for (j=i; j<=n; j++)
		{
			pref[i][j]=pref[i][j-1]+(a[j]<a[i] ? 1 : 0);
		}
	}
	for (i=n; i>=1; i--)
	{
		for (j=i; j>=1; j--)
		{
			suff[i][j]=suff[i][j+1]+(a[j]>a[i] ? 1 : 0);
		}
	}
	mn=(int)2e9;
	for (i=1; i<=n; i++)
		for (j=i+1; j<=n; j++)
		{
			if (a[i]>a[j])
			{
				//cur=-(pref[i][j-1]-pref[i][i])-(suff[j][i+1]-suff[j][j])-1;
				x=pref[i][j-1]-pref[i][i];
				cur=-x+(j-i-1-x);
				x=suff[j][i+1]-suff[j][j];
				cur=cur-x+(j-i-1-x);
				cur--;
				if (cur<mn)
				{
					mn=cur;
					f=i;
					s=j;
				}
			}
		}
	if (mn==(int)2e9)
		cout<<-1<<' '<<-1<<endl;
	else
		cout<<f<<' '<<s<<endl;
	return 0;
}



