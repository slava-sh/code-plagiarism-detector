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
	if (a[1]==0)
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
			return 0;
		}
		}
	}
	if (a[0]==0)
	{
			vector <pair <int,char> > a2;
			a2.push_back(make_pair(0,'a'));
			a2.push_back(make_pair(0,'b'));
			a2.push_back(make_pair(0,'c'));
			for (int i=0;i<n;i++)
			{
				if (s[i]=='a')
					a2[0].first++;
				if (s[i]=='b')
					a2[1].first++;
				if (s[i]=='c')
					a2[2].first++;
			}
			sort(a2.begin(),a2.end());
			cout<<"2\n"<<a2[1].second<<endl<<a2[2].second<<endl;
			return 0;
	}
	fl=0;
	if (l>n)
		l=n;
	for (int i=1;i<=l;i++)
		for (int j=1;j<=l;j++)
		{
			int ff=0;
			int st0=0;
			int st2=0;
			int cur=0;
			int kol1=0;
			int kol2=0;
			int fff=0;
			int yy=0;
			for (int w=i;w<n;)
			{
				if (cur==0)
				{
					if (s[w]!=s[kol1])
					{
						/*if (kol1!=0)
						{
							ff=1;
							break;
						}*/
						cur=1;
						if (yy==1)
						{
							ff=1;
							break;
						}
						w=(w-kol1);
						yy=1;
						kol1=0;
						if (fff==0)
						{
							st2=w;
							kol2=1;
							kol2%=j;
							if (kol2==0)
								yy=0;
							kol1=0;
							fff=1;
						}
						else
						{
							kol2=0;
							if (s[w]!=s[st2+kol2])
							{
								ff=1;
								break;
							}
							kol2++;
							kol2%=j;
							if (kol2==0)
								yy=0;
						}
					}
					else
					{
						kol1++;
						kol1%=i;
						if (kol1==0)
								yy=0;
					}
				}
				else
				{
					if (s[w]!=s[st2+kol2])
					{
						/*if (kol2!=0)
						{
							ff=1;
							break;
						}*/
						cur=0;
						w=(w-kol2);
						kol2=0;
						yy=1;
						if (s[w]!=s[kol1])
						{
							ff=1;
							break;
						}
						kol1++;
						kol1%=i;
						if (kol1==0)
								yy=0;
					}
					else
					{
						kol2++;
						kol2%=j;
						if (kol2==0)
								yy=0;
					}
				}
				w++;
			}
			if ((ff!=1)&&(kol1==0)&&(kol2==0))
			{
				cout<<"2"<<endl;
				for (int w=0;w<i;w++)
					cout<<s[w];
				cout<<endl;
				for (int w=st2;w<st2+j;w++)
					cout<<s[w];
				cout<<endl;
				return 0;
			}
		}
	cout<<"3\na\nb\nc\n";
	return 0;
}