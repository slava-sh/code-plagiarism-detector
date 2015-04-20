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

char c[111][15], d[111][111][15], s[25];

int n, i, j, k, l, t, v, m[111], ln[111], ln2[111][111], id, id2;

bool ok, found;

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin>>n;
	for (i=1; i<=n; i++)
	{
		scanf("%s", &c[i]);
		ln[i]=strlen(c[i]);
		scanf("%d", &m[i]);
		for (j=1; j<=m[i]; j++)
		{
			scanf("%s", &d[i][j]);
			ln2[i][j]=strlen(d[i][j]);
		}
	}
	int ttt;
	cin>>ttt;
	for (int tt=1; tt<=ttt; tt++)
	{
		scanf("%s", &s);
		id=-1, id2=-1;
		for (i=1; i<=n; i++)
		{
			ok=1;
			for (j=0; j<ln[i]; j++)
			{
				if (c[i][j]!=s[j]) 
				{
					ok=0;
					break;
				}
			}
			if (ok)
			{
				for (l=1; l<=m[i]; l++)
				{
					found=1;
					for (j=0; j<ln2[i][l]; j++)
					{
						if (d[i][l][j]!=s[ln[i]+j])
						{
							found=0;
							break;
						}
					}
					if (found)
					{
						if (s[ln[i]+ln2[i][l]]!='0')
						{
							id=i;
							id2=l;
							break;
						}
					}
				}
				if (id!=-1) break;
			}
		}	
		if (id==-1)
		{
			printf("Incorrect\n");
			continue;
		}
		printf("+");
		printf("%s", c[id]);
		printf("(");
		printf("%s", d[id][id2]);
		printf(")");
		t=ln[id]+ln2[id][id2];
		if (t==8)
		{
			cout<<s[8]<<s[9]<<s[10]<<endl;
			continue;
		}	
		if (t==7)
		{
			cout<<s[7]<<s[8]<<"-"<<s[9]<<s[10]<<endl;
			continue;
		}	
		if (t==6)
		{
			cout<<s[6]<<s[7]<<s[8]<<"-"<<s[9]<<s[10]<<endl;
			continue;
		}	
		if (t==5)
		{
			cout<<s[5]<<s[6]<<"-"<<s[7]<<s[8]<<"-"<<s[9]<<s[10]<<endl;
			continue;
		}	
		if (t==4)
		{
			cout<<s[4]<<s[5]<<s[6]<<"-"<<s[7]<<s[8]<<"-"<<s[9]<<s[10]<<endl;
			continue;
		}	
		printf("\n");
	}	

			
			                    	

	return 0;
}
