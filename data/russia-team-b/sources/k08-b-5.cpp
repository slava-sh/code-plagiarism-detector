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
ll n,r,a[400000],d[400000],b[400000],kol=0,mini=INF,mini1;
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
	b[0]=0;
	for (int i=1;i<=n;i++)
	{
		while (a[mini1]+r<a[i] && mini1<=n)
		{
			d[mini1]=i;
			mini1++;
		}
	}
	kol=0;
	for (int i=1;i<=n;i++)
	{
	
		if (d[i])
		{
			kol+=n-d[i]+1;
		}
	}
	cout<<kol;
	return 0;
}