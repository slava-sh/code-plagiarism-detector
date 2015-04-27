#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <stdio.h>
#include <fstream>
#include <map>
#include <set>
#include <cstdlib>
#include <queue>
#include <math.h>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <stack>
#include <iomanip>
#define ll long long
#define endl '\n'
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pull pair<ull,ull>
ll MOD=1000000007;
ll inf=1e18;
using namespace std;

vector< pair<char,int> > O;
int S[100001];
bool Ans[100001];
int main()
{
	ios::sync_with_stdio(0);
	
	int n,m,i,cnt=0,x;
	bool ALL;
	char c;
	cin>>n>>m;
	map<int,int> E;
	for(i=0;i<n;i++)
	{
		S[i]=-1;
	}
	int g=0;
	for(i=0;i<m;i++)
	{
		cin>>c>>x;
		O.pb(mp(c,x-1));
		if(S[x-1]==-1)
		{
			if(c=='+')
			{
				S[x-1]=0;
			}
			else
			{
				S[x-1]=1;
				cnt+=1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		Ans[i]=true;
		if(S[i]==-1)
		{
			g++;
		}
		if(cnt==1)
		{
			if(S[i]==1)
			{
				E[i]=1;
			}
		}
	}
	
	
	for(i=0;i<m;i++)
	{
		c=O[i].first;
		x=O[i].second;
		if(c=='+')
		{
			if(cnt>0)
			{
				Ans[x]=false;
			}
			else if(cnt==0)
			{
				ALL=false;
				E[x]=1;
			}
			cnt++;
		}
		else
		{
			if(cnt>1)
			{
				Ans[x]=false;
			}
			cnt--;
			if(cnt==1)
			{
				ALL=false;
				S[x]=1-S[x];
				continue;
			}
		}
		S[x]=1-S[x];
	}
	int r=0;
	for(i=0;i<n;i++)
	{
		if(S[i]!=-1 && Ans[i]==true)
		{
			r++;
		}
	}
	if((E.size()>1 || r>1) && g==0)
	{
		cout<<0;
	}
	else if(g!=0 && (E.size()>1 || r>1))
	{
		cout<<g<<endl;
		for(i=0;i<n;i++)
		{
			if(S[i]==-1)
			{
				cout<<i+1<<" ";
			}
		}
	}
	else if(E.size()==1 && Ans[E.begin()->first]!=false)
	{
		cout<<g+1<<endl;
		for(i=0;i<n;i++)
		{
			if(S[i]==-1 || E.begin()->first==i)
			{
				cout<<i+1<<" ";
			}
		}
	}
	else if(r==1)
	{
		cout<<g+1<<endl;
		for(i=0;i<n;i++)
		{
			if(S[i]==-1 || Ans[i])
			{
				cout<<i+1<<" ";
			}
		}
	}
	else
	{
		cout<<g<<endl;
		for(i=0;i<n;i++)
		{
			if(S[i]==-1)
			{
				cout<<i+1<<" ";
			}
		}
	}
	
	return 0;
}