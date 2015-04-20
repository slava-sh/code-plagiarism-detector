#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
#include <set>
#include <map>
using namespace std;

#define TASK "numbers"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
set<string> C,O[110];
map<string,int> CID;
string s;
bool F1(int i);
bool F2(int i,int id);
bool F3(int i);

string ans="";
bool F1(int i)
{
	for(int j=i;j<=s.size();j++)
	{
		if(C.count(s.substr(i,j-i))!=0)
			
		{
			string t=s.substr(i,j-i);
			int id=CID[t];
			if(t.size()>=1&&t.size()<=3)
				if(F2(j,id))
				{
					ans='+'+t+ans;
					return true;
				}
		}
		
	}
	return false;
}
bool F2(int i,int id)
{
	for(int j=i;j<=s.size();j++)
	{
		if(O[id].count(s.substr(i,j-i))!=0)
		{
			string t=s.substr(i,j-i);
			if(t.size()>=1&&t.size()<=5)
				if(F3(j))
				{
					ans='('+t+')'+ans;
					return true;
				}
		
		}
	}
	return false;
}
string mag(char s)
{
	string S="";
	S+=s;
	return S;
}
bool F3(int i)
{
	string t=s.substr(i);
	ans="";
	if(t.size()==0)return false;
	if(t[0]=='0')return false;
	if(t.size()==3)
	{
		ans+=mag(t[0])+mag(t[1])+mag(t[2]);
		return 1;
	}
	if(t.size()==4)
	{
		ans+=mag(t[0])+mag(t[1])+'-'+mag(t[2])+mag(t[3]);
		return 1;
	}
	if(t.size()==5)
	{
		ans+=mag(t[0])+mag(t[1])+mag(t[2])+'-'+mag(t[3])+mag(t[4]);
		return 1;
	}
	if(t.size()==6)
	{
		ans+=mag(t[0])+mag(t[1])+'-'+mag(t[2])+mag(t[3])+'-'+mag(t[4])+mag(t[5]);
		return 1;
	}
	if(t.size()==7)
	{
		ans+=mag(t[0])+mag(t[1])+mag(t[2])+'-'+mag(t[3])+mag(t[4])+'-'+mag(t[5])+mag(t[6]);
		return 1;
	}
	return false;
}

int k;
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int n;
	cin>>n;
	forn(i,n)
	{
		cin>>s;
		C.insert(s);
		cin>>k;
		CID[s]=i;
		forn(j,k)
		{
			cin>>s;
			O[i].insert(s);
		}
	}
	int m;
	cin>>m;
	forn(i,m)
	{
		cin>>s;
		if(!F1(0))
			puts("Incorrect");
		else
		{
			cout<<ans<<endl;
		}
	}
}