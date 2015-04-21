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

ll mn,d,a[3030],b[3030],dp[3030][3030][2],cur,c,INF;
int n,k,i,j;

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k>>c>>d;
	for (i=1; i<=n; i++)
		cin>>a[i]>>b[i];
	INF=(ll)1e18+1;
	for (i=1; i<=n; i++)
		for (j=1; j<=k; j++)
			dp[i][j][0]=dp[i][j][1]=INF;
	dp[1][1][0]=dp[1][1][1]=(b[1]-a[1])*d;
	for (i=2; i<=n; i++)
	{
		for (j=1; j<=k; j++)
		{
			cur=INF;
			if (dp[i-1][j][1]!=INF)
			{
				//cur=dp[i-1][j][1]+(a[i]-b[i-1])*d+(b[i]-a[i])*d;
				cur=dp[i-1][j][1]+(b[i]-b[i-1])*d;
			}
			if (j==1)
			{
				if (dp[i-1][k][0]!=INF)
					cur=min(cur,dp[i-1][k][0]+c+(b[i]-a[i])*d);
			}
			else
			{
				if (dp[i-1][j-1][0]!=INF)
					cur=min(cur,dp[i-1][j-1][0]+(b[i]-a[i])*d);
			}
			dp[i][j][0]=dp[i][j][1]=cur;
		}
	}
	mn=INF;
	for (j=1; j<=k; j++)
	{
		mn=min(mn,dp[n][j][0]);
		mn=min(mn,dp[n][j][1]);
	}
	cout<<mn<<endl;
	return 0;
}



