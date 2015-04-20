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
#define INF 10000000000
#define pb push_back
#define pob pop_back
#define sz size()
#define eps 1e-6
#define fname ""
#define pof pop_front
#define mp make_pair
#define pus empty()
using namespace std;
long long a[200005],n,m,mini=INF,sum=0;
int main ()
{
 freopen("fence.in","r",stdin);
 freopen("fence.out","w",stdout);
cin>>n>>m;
for (int i=1;i<=n;i++)
{
	cin>>a[i];
	sum+=a[i];
	if (a[i]<mini)
	{
		mini=a[i];
	}
}
if (m>=sum)
{
	cout<<mini;
	return 0;
}
else
{
	cout<<min(m/n,mini);
	return 0;
}
return 0;
}
