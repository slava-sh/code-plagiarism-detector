#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <algorithm>
//#include <>

using namespace std;
#define fname "numbers"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

struct node
{
	int nx[11];
	bool fn, fn2;
}a[1111111];

int sz, n, i, j, m, k, l, t, x, v, b[22], st, id;

string s;

char c[22];

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin>>n;
	sz=2;
	for (i=1; i<=n; i++)
	{
		scanf("%d%d", &x, &m);
		l=0;
		while (x)
		{
			b[++l]=x%10, x/=10;
		}
		v=1;
		while (1)
		{
			if (!a[v].nx[b[l]])
				a[v].nx[b[l]]=sz++;
		   	v=a[v].nx[b[l]];
		   	l--;
		   	if (!l) break;
		}
//		cout<<endl;
		a[v].fn=1;
		st=v;
		for (j=1; j<=m; j++)
		{
			scanf("%d", &x);
			l=0;
			v=st;
			while (x)
			{
				b[++l]=x%10, x/=10;
			}
			while (1)
			{
//				cout<<b[l];
				if (!a[v].nx[b[l]])
					a[v].nx[b[l]]=sz++;
			   	v=a[v].nx[b[l]];
			   	l--;
			   	if (!l) break;
			}
//			cout<<endl;
			a[v].fn2=1;
	    }
	}
	cin>>n;
	for (i=1; i<=n; i++)
	{
		scanf("%s", &c);
		v=1;
		id=-1;
		for (j=0; j<11; j++)
		{
			if (a[v].fn2)
			{
				if (c[j]!='0')
				{
					id=j-1;
					break;
				}
			}
			if (!a[v].nx[(int)c[j]-'0']) break;
			v=a[v].nx[(int)c[j]-'0'];
		}
		if (id==-1)
		{
			printf("Incorrect\n");
			continue;
		}
		v=1;
		printf("+");
		for (j=0; j<=id; j++)
		{	
			v=a[v].nx[(int)c[j]-'0'];
			cout<<c[j];
			if (a[v].fn)
			{
				printf("(");
			}
	    }
	    printf(")");
	    if (id==7)
	    {
	    	for (j=8; j<=10; j++)
	    	{
	    		cout<<c[j];
	    	}
	    	printf("\n");
	    	continue;
	    }
	    if (id==6)
	    {
	    	cout<<c[7]<<c[8]<<"-"<<c[9]<<c[10]<<"\n";
	    	continue;
	    }
	    if (id==5)
	    {
	    	cout<<c[6]<<c[7]<<c[8]<<"-"<<c[9]<<c[10]<<"\n";
	    	continue;
	    }
	    if (id==4)
	    {
	    	cout<<c[5]<<c[6]<<"-"<<c[7]<<c[8]<<"-"<<c[9]<<c[10]<<"\n";
	    	continue;
	    }
	    if (id==3)
	    {
	    	cout<<c[4]<<c[5]<<c[6]<<"-"<<c[7]<<c[8]<<"-"<<c[9]<<c[10]<<"\n";
	    	continue;
	    }
	}
		   	

		




		
		


	return 0;
}
