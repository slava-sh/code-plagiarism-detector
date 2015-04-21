#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long n,k,c,d;
	cin>>n>>k>>c>>d;
	long long dp[3500][3500];
	for (int i=0;i<3200;i++)
		for (int j=0;j<3200;j++)
			dp[i][j]=2e15;
	vector <int> st(n);
	vector <int> fin(n);
	for (int i=0;i<n;i++)
		cin>>st[i]>>fin[i];
	dp[0][1]=(fin[0]-st[0])*d;
	for (int i=1;i<n;i++)
		for (int j=1;j<=i+1;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(fin[i]-st[i])*d);
			if ((fin[i]-fin[i-1])*d<=100000000000)
				dp[i][j]=min(dp[i][j],dp[i-1][j]+(fin[i]-fin[i-1])*d);
			
		}
	long long ans=2e15;
	for (int i=1;i<=n+1;i++)
	{
		long long w=(i-1)/k;
		if ((i-1)%k!=0)
			w++;
		ans=min(ans,dp[n-1][i]+c*w);
	}
	cout<<ans<<endl;
	return 0;
}