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

int INF,n,k,i,x,j,dp[12][1000100],cur,mn;
vector <int> a[1000100];


int dfs(int lvl,int x)
{
	if (lvl==1)
	{
		return (x+1)/2;

	}
	if (dp[lvl][x]!=0) return dp[lvl][x];
	int ans=INF;
	for (int i=0; i<a[x].size(); i++)
	{
		ans=min(ans,dfs(1,a[x][i])*dfs(max(1,lvl-1),x/a[x][i]));
	}
	dp[lvl][x]=ans;
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k;
		
	INF=(int)2e9;
	for (i=1; i<=n; i++)
	{
		if (n%i==0)
		{
			for (j=1; j*j<=i; j++)
			{
				if (i%j==0)
				{
					a[i].pb(j);
					a[i].pb(i/j);
				}
			}
			sort(a[i].begin(),a[i].end());
		}
	}
	for (i=1; i<=1000000; i++)
		for (j=1; j<=k; j++)
			dp[j][i]=0;
	mn=INF;
	for (i=0; i<a[n].size(); i++)
	{
		cur=a[n][i];
		mn=min(mn,dfs(1,cur)*dfs(max(1,k-1),n/cur));
	}           
	cout<<mn<<endl;
	return 0;
}



