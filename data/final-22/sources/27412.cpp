#include <stdio.h>
#include <iostream>


using namespace std;

const int N = 1610000;
const int V = 600101;
const int l = V-3;
const int r = V-2;
const int inf=20000000;
                 
int v,was[V],a[13][V],next[N],first[N],en[N],n,m,d[N],cur,x,y,z,u,w[N];

int mulx(int x)
{
	if (x==1) return 12;
	if (x==2) return 6;
	if (x==3) return 4;
	if (x==4) return 3;
	else return -1;
}


void bfs(int  x)
{

	v = x;
	while (true)
	{
		was[v] = 1;
		for (int  i = first[v]; i >= 1; i = next[i])
		{	
			if (was[en[i]] == 0 && d[en[i]]>d[v]+w[i])  
			{
				long long  t =(d[v]+w[i]) % 13;
				a[t][r]++;
				a[t][a[t][r]] = en[i];
				d[en[i]]=(d[v]+w[i]) % inf;	
			}
		}
		int sj = 0;

		while (true) 
		{
			if (a[cur][l] < a[cur][r]) 
			
				break;
			
			a[cur][l] = 1;
			a[cur][r] = 1;
			cur = (cur + 1) % 13;
			sj ++;
			if (sj>13) 
			{
				cur  = inf;
				break;
			}
		}
		if (cur!=inf)
		{
			a[cur][l]++;
			v=a[cur][a[cur][l]];
		} 
		else break;
   }
}



int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	scanf("%d%d", &n, &m);
	for (int  i =0; i<13; i++)
	{
		a[i][l]=1;
		a[i][r]=1;
	}


    for (int  i =1 ; i <= n ; i++)
		d[i] = inf;


	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);

		u++;

		next[u] = first[x];
		first[x] = u;
		en[u] = y;
		w[u] = mulx(z);
        u++;

		next[u] = first[y];
		first[y] = u;
		en[u] = x;
		w[u] = w[u-1];
	}


	d[1] = 0;
	cur = 0;
	bfs(1);



	for (int  i =2; i<=n; i++)
	{
		double ans = d[i];
		ans  /= 12;
		printf("%.9f\n", ans);
	}
	return 0;
}