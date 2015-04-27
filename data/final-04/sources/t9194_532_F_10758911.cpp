#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int n, m;
vector<int> ans;
long long p=5, st[200022], h1[26][200022], h2[26][200022];
int pos[333];
string s1, s2;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n>>m; getline(cin,s1);
	getline(cin,s1);
	getline(cin,s2);
	st[0]=1;
	for(int i=1; i<s1.size(); ++i)
		st[i]=st[i-1]*p;
	for(char c='a'; c<='z'; ++c)
	{
		int j=c-'a';
		for(int i=0; i<s1.size(); ++i)
			h1[j][i+1]=h1[j][i]*p+(s1[i]==c);
		for(int i=0; i<s2.size(); ++i)
			h2[j][i+1]=h2[j][i]*p+(s2[i]==c);
	}
	for(int i=0;i<256;++i)
		pos[i]=-1;
	for(int i=0;i<s2.size();++i)
		if (pos[s2[i]-'a']==-1)
			pos[s2[i]-'a']=i;
	for(int i=0;i<s1.size()-s2.size()+1;++i)
	{
		bool t=true;
		vector<int> d(26,-1);
		for(int j=0;j<26;++j)
		{
			int x=pos[j];
			if (x==-1) continue;
			int y=x+i;
			int k=s1[y]-'a';
			if (d[j]!=-1 && d[j]!=k)
			{
				t=false;
				break;
			}
			if (d[k]!=-1 && d[k]!=j)
			{
				t=false;
				break;
			}
			d[j]=k;
			d[k]=j;
			if (h2[j][s2.size()] != h1[k][i+s2.size()]-h1[k][i]*st[s2.size()])
			{
				t=false;
				break;
			}
		}
		if (t)
			ans.push_back(i+1);
	}
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();++i)
		cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
/*
11 5
abacabadaba
acaba

21 13
paraparallelogramgram
qolorreraglom

6 3
aaaaaa
aaa

6 3
abcdef
ghi

5 5
abbab
cdc
*/