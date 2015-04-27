#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <functional>
#include <queue>
#include <iomanip>
#include <ctime>
#include <cstdlib>

#define pb push_back
#define mp make_pair
#define ll long long
#define ld long double
#define y1 yy1

using namespace std;

set <string> s;
int tt,l,n,bit[20],last,j,i,cur,mn,num,kol;
string st,s1;
set <string> ans;
bool flag;

void divide(int x)
{
	for (int i=0; i<n-1; i++)
	{
		bit[i]=x%2;
		x>>=1;
	}
	return;
}

int main()
{
	//ios_base::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>l;
	cin>>st;
	n=st.length();
	bit[n-1]=1;
	mn=(int)2e9;
	for (tt=0; tt<(1<<(n-1)); tt++)
	{
		divide(tt);
		last=-1;
		flag=true;
		for (j=0; j<n; j++)
		{
			if (bit[j]==1)
			{
				if (j-last>l)
				{
					flag=false;
					break;
				}
				last=j;
			}
		}
		if (!flag) continue;
		s.clear();
		
		for (i=0; i<n; i++)
		{
			j=i;
			s1="";
			while (bit[j]==0)
			{
				s1+=st[j];
				j++;
			}
			cur*=2;
			s1+=st[j];
			s.insert(s1);
			i=j;
		}
		kol=0;
		kol=(int)s.size();
		if (kol<mn)
		{
			mn=kol;
			num=tt;
		}
	}
	cout<<mn<<endl;
	divide(num);
	for (i=0; i<n; i++)
	{
		j=i;
		s1="";
		while (bit[j]==0)
		{
			s1+=st[j];
			j++;
		}
		s1+=st[j];
		ans.insert(s1);
		i=j;
	}
	while (!ans.empty())
	{
		cout<<*ans.begin()<<endl;
		ans.erase(ans.begin());
	}
	return 0;
}



