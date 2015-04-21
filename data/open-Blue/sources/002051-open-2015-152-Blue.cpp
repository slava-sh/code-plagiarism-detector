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
	int l;
	cin>>l;
	string s;
	cin>>s;
	int n=s.length();
	int a[3]={0};
	for (int i=0;i<n;i++)
	{
		if (s[i]=='a')
			a[0]++;
		if (s[i]=='b')
			a[1]++;
		if (s[i]=='c')
			a[2]++;
	}
	sort(a,a+3);
	if (a[2]==0)
	{
		cout<<1<<endl<<s[0]<<endl;
		return 0;
	}
	int fl=0;
	for (int i=1;i<=l;i++)
	{
		if (n%i==0)
		{
		int kol=0;
		int ff=0;
		for (int j=i;j<n;j++)
		{
			if (s[j]!=s[kol])
			{
				ff=1;
				break;
				
			}
			kol++;
			kol%=i;
		}
		if (ff!=1)
		{
			cout<<1<<endl;
			for (int j=0;j<i;j++)
				cout<<s[j];
			cout<<endl;
			fl=1;
			break;
		}
		}
	}
	if (fl==0)
		cout<<"2\na\nb\n";
	return 0;
}