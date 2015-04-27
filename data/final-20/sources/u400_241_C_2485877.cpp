#include <bits/stdc++.h>

using namespace std;

bool used[105][2];
int id[100005][2];
int n1, n2, v[105][2], x1[105][2], x2[105][2];

int main()
{
	int hL, hR, n;
	while(cin>>hL>>hR>>n)
	{
		memset(id, -1, sizeof(id));
		
		n1 = n2 = 0;
		for(int i=0; i<n; i++)
		{
			int sc, a, b;
			string pos;
			cin>>sc>>pos>>a>>b;
			
			if(pos == "T")
			{
				v[n1][0] = sc, x1[n1][0] = a, x2[n1][0] = b;
				
				for(int x=a; x<b; x++)
					id[x][0] = n1;
				
				n1++;
			}
			else 
			{
				v[n2][1] = sc, x1[n2][1] = a, x2[n2][1] = b;
				
				for(int x=a; x<b; x++)
					id[x][1] = n2;
				
				n2++;
			}
		}
		
		int best = 0;
		
		for(int it=1; it<1000; it++)
		{
			int H, W = 100000;
			
			if(it % 2 == 1) H = hL + hR + 100*(it-1);
			else H = hL - hR + 100*it;
			
			memset(used, 0, sizeof(used));
			bool ok = 1;
			int cur = 0;
			
			for(int i=0; i<it; i++)
			{
				int k = 1 - (i % 2);
				
				int h = hL + 100*i;
				int x = 1LL*h*W/H;
				
				int hit = -1;
				
				if(1LL*x*H == 1LL*h*W)
				{
					hit = id[x][k];
					if(hit == -1 && x-1>=0) hit = id[x-1][k];
				}
				else hit = id[x][k];
				
				if(hit == -1 || used[hit][k])
				{
					ok = 0;
					break;
				}
				else 
				{
					used[hit][k] = 1;
					cur += v[hit][k];
				}
			}
			
			if(ok) best = max(best, cur);
		}
		
		for(int it=1; it<1000; it++)
		{
			int H, W = 100000;
			
			if(it % 2 == 1) H = 100-hL - hR + 100*it;
			else H = 100-hL + hR + 100*(it-1);
			
			memset(used, 0, sizeof(used));
			bool ok = 1;
			int cur = 0;
			
			for(int i=0; i<it; i++)
			{
				int k = (i % 2);
				
				int h = 100-hL + 100*i;
				int x = 1LL*h*W/H;
				
				int hit = -1;
				
				if(1LL*x*H == 1LL*h*W)
				{
					hit = id[x][k];
					if(hit == -1 && x-1>=0) hit = id[x-1][k];
				}
				else hit = id[x][k];
				
				if(hit == -1 || used[hit][k])
				{
					ok = 0;
					break;
				}
				else 
				{
					used[hit][k] = 1;
					cur += v[hit][k];
				}
			}
			
			if(ok) best = max(best, cur);
		}
		
		cout<<best<<endl;
	}
  
	return 0;
}