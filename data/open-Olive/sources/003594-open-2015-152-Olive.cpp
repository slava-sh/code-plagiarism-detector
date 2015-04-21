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
vector <vector <int> > kol;
vector <vector <int> > kol2;
int ans1(int i,int j,int st)
{
	return kol[i][st]-kol[i][j];
}


int ans2(int j,int i)
{
	return kol2[j][i-1]-kol2[j][j];
}
int delta(int i,int j)
{
	return ans1(i,j,i)-ans1(j,j,i)+ans2(j,i);
}

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;
	cin>>n;
	vector <int> a(n);
	for (int i=0;i<n;i++)
		cin>>a[i];
	kol.resize(n);
	for (int i=0;i<n;i++)
	{
		if (a[0]>a[i])
			kol[i].push_back(1);
		else
			kol[i].push_back(0);
		for (int j=1;j<n;j++)
		{
			if (a[j]>a[i])
				kol[i].push_back(kol[i][kol[i].size()-1]+1);
			else
				kol[i].push_back(kol[i][kol[i].size()-1]);
		}
	}
	kol2.resize(n);
	for (int i=0;i<n;i++)
	{
		if (a[0]<a[i])
			kol2[i].push_back(1);
		else
			kol2[i].push_back(0);
		for (int j=1;j<n;j++)
		{
			if (a[j]<a[i])
				kol2[i].push_back(kol2[i][kol2[i].size()-1]+1);
			else
				kol2[i].push_back(kol2[i][kol2[i].size()-1]);
		}
	}
	long long ans=0;
	long long f=-2;
	long long f1=-2;
	for (int i=0;i<n;i++)
		for (int j=0;j<i;j++)
		{
			if (a[j]>a[i])
			{
				int y=delta(i,j);
				if (ans<y)
				{
					ans=y;
					f=i;
					f1=j;
				}
			}
		}
	cout<<f1+1<<" "<<f+1<<endl;

	return 0;
}