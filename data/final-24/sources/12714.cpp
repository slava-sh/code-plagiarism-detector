#include<iostream>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
long k, l;
pair<char, bool> p[5];
string s;
int main()
{
	cin>>l;
	cin>>s;
	p[1].first='a';
	p[2].first='b';
	p[3].first='c';
	for(long long i=0;i<s.length();i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(s[i]==p[j].first && p[j].second==false) {k++; p[j]. second=true;}
		}
	}
	cout<<k<<endl;
	for(int i=1;i<=3;i++)
	{
		if(p[i].second==true) {cout<<p[i].first<<endl;}
	}
	return 0;
}