#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <iterator>
#include <queue>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int mn=5005;
long long kol[mn][mn],kol2[mn][mn];
long long ans1(long long i,long long j,long long st)
{
	return kol[i][st]-kol[i][j];
}


long long ans2(long long j,long long i)
{
	return kol2[j][i]-kol2[j][j];
}
long long delta(long long i,long long j)
{
	return ans1(i,j,i)-ans1(j,j,i)+ans2(j,i);
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long n;
	cin>>n;
	int a[mn];
	for (long long i=0;i<n;i++)
		cin>>a[i];
	for (long long i=0;i<n;i++)
	{
		if (a[0]>a[i])
			kol[i][0]=1;
		else
			kol[i][0]=0;
		for (long long j=1;j<n;j++)
		{
			if (a[j]>a[i])
				kol[i][j]=kol[i][j-1]+1;
			else
				kol[i][j]=kol[i][j-1];
		}
	}
	for (long long i=0;i<n;i++)
	{
		if (a[0]<a[i])
			kol2[i][0]=1;
		else
			kol2[i][0]=0;
		for (long long j=1;j<n;j++)
		{
			if (a[j]<a[i])
				kol2[i][j]=kol2[i][j-1]+1;
			else
				kol2[i][j]=kol2[i][j-1];
		}
	}
	long long ans=0;
	long long f=-2;
	long long f1=-2;
	for (long long i=0;i<n;i++)
		for (long long j=0;j<i;j++)
		{
				long long y=delta(i,j);
				if (ans<y)
				{
					ans=y;
					f=i;
					f1=j;
				}
		}
	cout<<f1+1<<" "<<f+1<<endl;

	return 0;
}