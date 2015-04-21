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
	cin>>n>>k>>d>>c;
	long long dp[350][350];
	for (int i=0;i<320;i++)
		for (int j=0;j<320;j++)
			dp[i][j]=1000000000000000000;
	int st,fin;
	int fold;
	cin>>st>>fin;
	dp[0][1]=c*(fin-st);
	fold=fin;
	for (int i=1;i<n;i++)
	{
		cin>>st>>fin;
		for (int j=0;j<n+1;j++)
		{
			dp[i][j]=min(dp[i-1][j]+c*(fin-fold),dp[i-1][j-1]+c*(fin-st));
		}
	}
	long long ans=1000000000000000000;
	for (int i=1;i<=n+2;i++)
	{
		int w=i/k;
		if (i%k!=0)
			w++;
		w--;
		ans=min(ans,dp[n-1][i]+d*w);
	}
	cout<<ans<<endl;

	return 0;
}