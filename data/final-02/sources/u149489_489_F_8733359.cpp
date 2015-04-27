#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
long long n,m,md,i,j;
char a[602][602];
long long dp[602][602];
bool z = false;
long long x,u;
int main()
{
	cin>>n>>m>>md;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			cin>>a[i][j];
	for(i=1;i<=m;i++)
	{
		long long q = 0;
		for(j=1;j<=n;j++) q+=(a[i][j]-'0');
		if(q!=2) z = true;
	}
	for(j=1;j<=n;j++)
	{
		long long q = 0;
		for(i=1;i<=m;i++) q+=(a[i][j]-'0');
		if(q>2) z = true;
		if(q==0) x++;
		if(q==1) u++;
	}
	if(z)
	{
		cout<<0<<endl;
		return 0;
	}
	dp[0][0] = 1;
	if(m==0) x = n;
	//cout<<x<<" "<<u<<endl;
	if((x*2+u)%2==1 || (x*2+u)/2 != n-m) 
	{
		cout<<0<<endl;
		return 0;
	}
	int x1 = x;
	int u1 = u;
	x = 500;
	u = 500;
	for(i=0;i<=x;i++)
	{
		//cout<<i<<": ";
		for(j=0;j<=u;j++)
		{
			if(i == j && j == 0)
			{
				//cout<<1<<" ";
				continue;
			}
			long long A1,A2,A3,Q1,Q2,Q3;
			Q1 = j*(j-1)/2;
			Q1%=md;
			Q2 = i*(i-1)/2;
			Q2%=md;
			Q3 = i*j; 
			Q3%=md;

			if(j>=2) A1 = Q1*dp[i][j-2];
			else A1 = 0;
			A1%=md;
			if(i>=2) A2 = Q2*dp[i-2][j+2];
			else A2 = 0;
			A2%=md;
			if(i>=1) A3 = Q3*dp[i-1][j];
			else A3 = 0;
			A3%=md;

			dp[i][j] += A1;
			dp[i][j]%=md;
			dp[i][j] += A2;
			dp[i][j]%=md;
			dp[i][j] += A3;
			dp[i][j]%=md;
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	cout<<dp[x1][u1]<<endl;
	//cin>>i;
	return 0;
}











/*
ID: mushegh1
PROG: shopping
LANG: C++11               
*/
/*
#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int s,n,c1[102][7],k1[102][7],p1[102];
int b,c[7],k[7],p[7],i,j,k;
int dp[7][7][7][7][7];
int main()
{
	//freopen("shopping.in", "r", stdin);
	//freopen("shopping.out", "w", stdout);
	cin>>s;
	for(i=1;i<=s;i++)
	{
		cin>>n;
		for(j=1;j<=n;j++)
			cin>>c1[i][j]>>k1[i][j];
		cin>>p1[i];
	}
	cin>>b;
	for(i=1;i<=b;i++)
	{
		cin>>c[i]>>k[i]>>p[i];
	}
	return 0;
}*/
/*
10
0 1000000000000000000
*/