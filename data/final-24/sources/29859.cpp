#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<memory.h>
#include<set>
#include<map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<ctime>
#include<cstdlib>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;

#define abs(a) ((a)>0?(a):-(a))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define fill(a,k) memset(a,k,sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pii pair<int,int>
#define for(i,a,n) for(int i=a;i<n;i++)
#define inf 2e+18

#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)

/*
int dsu_get(int v)
{
	return (p[v]==v?v:p[v]=dsu_get(p[v])); 
}

void dsu_union(int a,int b)
{
	a=dsu_get(a);
	b=dsu_get(b);
	if(rand()&1)
		swap(a,b);
	p[a]=b;
}
*/

/*
void add(int a,int k)
{
	for(int i=a;a<n;i|=i+1)
		fen[i]+=k;
}

int get(int a)
{
	int s=0;
	for(int i=a;i>=0;i=(i&i+1)-1)
		s+=fen[i];
	return s;
}
*/

int main()
{
	fr("input.txt");
	fw("output.txt");
	int k;
	string s;
	cin>>k>>s;

	bool a=0,b=0,c=0;
	int rk=0;
	for(i,0,(int)s.length())
	{
		if(s[i]=='a' && !a)
			{
				a=1;
				rk++;
			}
		if(s[i]=='b' && !b)
			{
				b=1;
				rk++;
			}
		if(s[i]=='c' && !c)
			{
				c=1;
				rk++;
			}
	}

	string tm;
	for(l,0,k)
	{
		tm+=s[l];
		bool j=0;
		if(!((int)s.length()%(l+1)))
		{
			string gh;
			while(gh.size()<s.size())
				gh+=tm;
			if(gh==s)
			{
				cout<<1<<endl<<tm;
				return 0;
			}
		}
	}
	if(s.length()<=k)
	{
		cout<<1<<endl<<s;
		return 0;
	}
	if(rk==2)
	{
		cout<<2;
		if(a)
			cout<<endl<<'a';
		if(b)
			cout<<endl<<'b';
		if(c)
			cout<<endl<<'c';
		return 0;
	}
	cout<<3<<endl<<'a'<<endl<<'b'<<endl<<'c';
	return 0;
}