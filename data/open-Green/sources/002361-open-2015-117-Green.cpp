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

int INF,n,k,i,x,j,dp[1000100][12],cur;
vector <int> a[1000100];


int dfs(int lvl,int x)
{
	if (lvl==1)
	{
		dp[x][lvl]=(x+1)/2;
		return dp[x][lvl];
	}
	if (dp[x][lvl]!=0)
		return dp[x][lvl];
   	int ans=INF,cur=1;
   	for (int i=0; i<a[x].size(); i++)
   	{
   		cur=a[x][i];
   		if (cur>x/cur)
   		{
   			dp[x][lvl]=ans;
   			return ans;
   		}	
   		ans=min(ans,dfs(max(1,lvl-1),cur)*dfs(max(1,lvl-2),x/cur));
   	}
   	dp[x][lvl]=ans;
   	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k;
	k++;
	/*for (i=1; i<=n; i++)
		used[i]=false;
	for (i=1; i*i<=n; i++)
	{
		if (n%i==0)
		{
			used[i]=true;
			used[n/i]=true;	
		}
	}  */
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
	for (i=1; i<=n; i++)
		for (j=1; j<=k; j++)
			dp[i][j]=0;
	cur=1;
	dp[n][k]=INF;
	for (i=0; i<a[n].size(); i++)
	{
		cur=a[n][i];
		if (cur>n/cur) break;
		dp[n][k]=min(dp[n][k],dfs(max(1,k-1),cur)*dfs(max(1,k-2),n/cur));
	}           
	cout<<dp[n][k]<<endl;
	return 0;
}



