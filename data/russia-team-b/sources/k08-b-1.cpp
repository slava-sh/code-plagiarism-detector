#include <iostream>
#include <cstdio>
#include <set>
#include <queue>
#include <ctime>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#define ll long long
#define MAXN 100000
#define INF 100000000
#define pb push_back
#define pob pop_back
#define sz size()
#define eps 1e-6
#define fname "che"
#define pof pop_front
#define mp make_pair
#define pus empty()
using namespace std;
ll n,r,a[400000],d[400000],ost[400000],kol=0,mini=INF,mini1;
int main()
{
	freopen (fname".in","r",stdin);
	freopen (fname".out","w",stdout);
	cin>>n>>r;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}

	mini1=1;
	
	for (int k=1;k*k<=n;k++)
	{
		for (int i=1;i<=n;i++)
		{
			if (d[i])
			continue;
//			cout<<"mini "<<mini1<<"\n";
			if (a[i]>a[mini1]+r)
			{
				kol=0;
				d[mini1]=i;
				for (int j=mini1+1;j<=n;j++)
				{
					if (a[j]!=a[mini1])
					{
						break;
					}
					kol++;
					d[mini1+kol]=i;
				}
				mini1+=kol+1;		
			}
		}
	}
	kol=0;
	for (int i=1;i<=n;i++)
	{
		if (d[i])	
		kol+=n-d[i]+1;
	}cout<<kol;
	return 0;
}