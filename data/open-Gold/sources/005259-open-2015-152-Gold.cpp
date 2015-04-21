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
	unsigned long long n,k,c,d;
	cin>>n>>k>>c>>d;
	unsigned long long dp[350][350];
	for (unsigned long long i=0;i<320;i++)
		for (unsigned long long j=0;j<320;j++)
			dp[i][j]=100000000000000;
	unsigned long long st,fin;
	unsigned long long fold;
	cin>>st>>fin;
	dp[0][1]=d*(fin-st);
	fold=fin;
	for (unsigned long long i=1;i<n;i++)
	{
		cin>>st>>fin;
		for (unsigned long long j=0;j<n+1;j++)
		{
			dp[i][j]=min(dp[i][j],dp[i-1][j-1]+d*(fin-st));
			if (d*(fin-fold)<c)
				dp[i][j]=min(dp[i][j],dp[i-1][j]+d*(fin-fold));
		}
		fold=fin;
	}
	unsigned long long ans=100000000000000;
	for (unsigned long long i=0;i<=n;i++)
	{
		unsigned long long w=i/k;
		if (i%k!=0)
			w++;
		w--;
		ans=min(ans,dp[n-1][i]+c*w);
	}
	cout<<ans<<endl;

	return 0;
}