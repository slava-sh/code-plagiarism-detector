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
const int mn=10001;
int kol[mn][mn],kol2[mn][mn];




int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin>>n;
	int a[mn];
	int fl=0;
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
		if (a[i]-1!=i)
			fl=1;
	}
	if (fl==0)
	{
		cout<<"-1 -1"<<endl;
		return 0;
	}
	for (int i=0;i<n;i++)
	{
		if (a[0]>a[i])
			kol[i][0]=1;
		else
			kol[i][0]=0;
		for (int j=1;j<n;j++)
		{
			if (a[j]>a[i])
				kol[i][j]=kol[i][j-1]+1;
			else
				kol[i][j]=kol[i][j-1];
		}
	}
	for (int i=0;i<n;i++)
	{
		if (a[0]<a[i])
			kol2[i][0]=1;
		else
			kol2[i][0]=0;
		for (int j=1;j<n;j++)
		{
			if (a[j]<a[i])
				kol2[i][j]=kol2[i][j-1]+1;
			else
				kol2[i][j]=kol2[i][j-1];
		}
	}
	int ans=0;
	int f=-2;
	int f1=-2;
	for (int i=0;i<n;i++)
		for (int j=0;j<i;j++)
		{
				int y=kol[i][i];
				if (j!=0)
					y-=kol[i][j-1];
				//
				y-=kol[j][i];
				if (j!=0)
					y+=kol[j][j-1];
				//
				y+=(kol2[j][i]-kol2[j][j]);
				y-=(kol2[i][i]-kol2[i][j]);
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