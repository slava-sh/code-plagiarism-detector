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

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

int ans,x,y,i,n,a[100100],q;

int get(int x)
{
	if (x==1)
	{
		if (n==1 || a[1]==a[2]) return 1;
		return 2;
	}
	if (x==n)
	{
		if (a[n]==a[n-1]) return 1;
		return 2;
	}
	int ans=1;
	if (a[x]!=a[x-1]) ans++;
	if (a[x+1]!=a[x]) ans++;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for (i=1; i<=n; i++)
		cin>>a[i];
	ans=1;
	for (i=2; i<=n; i++)
		if (a[i]!=a[i-1]) ans++;
	cin>>q;
	while (q--)
	{
		cin>>x>>y;
		ans-=get(x);
		a[x]=y;
		ans+=get(x);
		cout<<ans<<endl;
	}
	return 0;
}



