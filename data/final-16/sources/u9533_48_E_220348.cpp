#include <cstdio>
#include <cstring>

#define maxn 200 + 10
#define oo 1000000000
#define maxp 40401 + 10
#define maxm 10000000 + 10

#define max(a,b) ( (a) > (b) ? (a) : (b) )
#define min(a,b) ( (a) < (b) ? (a) : (b) )

int st,h,t,r,n,m,tot;
int f[maxn][maxn] = {0},g[maxn][maxn] = {0};
int a[maxn][2] = {0},b[maxn][2] = {0};
bool hash[maxn][maxn] = {0};

int td = 0,top = 0,sum = 0;
int totm[2] = {0},e[2][maxm] = {0},last[2][maxm] = {0},now[2][maxp] = {0};
int stack[maxp] = {0},low[maxp] = {0},dfn[maxp] = {0};
int fa[maxp] = {0};
bool ok[maxp] = {0},used[maxp] = {0};

int dl[maxp] = {0},step[maxp] = {0};

inline void set( bool t, int u, int v )
{
	++totm[t];
	e[t][totm[t]] = v;
	last[t][totm[t]] = now[t][u];
	now[t][u] = totm[t];
}

inline void build()
{
	int i,j,k,p,q;
	tot = (r+1) * (r+1);
	for( i = 0 ; i <= r ; ++i )
		for( j = 0 ; i+j <= r ; ++j )
			{
				for( k = 1 ; k <= n && k <= i ; ++k )
					{	
						p = i-k+a[k][0], q = j+a[k][1];
						if( p+q <= r )
							set( 0, i*(r+1)+j+1, p*(r+1)+q+1 );
					}
				for( k = 1 ; k <= m && k <= j ; ++k )
					{
						p = i+b[k][0], q = j-k+b[k][1];
						if( p+q <= r )	
							set( 0, i*(r+1)+j+1, p*(r+1)+q+1 );
					}
			}
}

inline void bfs()
{
	int l = 0, r = 1;
	int i,j;
	
	dl[0] = st;
	step[st] = 1;
	while( l < r )
		{
			i = dl[l];
			for( j = now[0][i] ; j ; j = last[0][j] )
				if( !step[e[0][j]] )
					{
						step[e[0][j]] = step[i] + 1;
						dl[r++] = e[0][j];
					}
			++l;
		}
}

void tarjan( int i )
{
	int j;

	stack[++top] = i;
	dfn[i] = ++td;
	low[i] = td;

	for( j = now[0][i] ; j ; j = last[0][j] )
		{
			if( !dfn[e[0][j]] )
				{
					tarjan(e[0][j]);
					low[i] = min( low[i], low[e[0][j]] );
				}
			else if( !fa[e[0][j]] )
				low[i] = min( low[i], dfn[e[0][j]] );
		}
	if( low[i] == dfn[i] )
		{
			++sum;
			do fa[stack[top]] = sum;
			while( stack[top--] != i );
		}
}

bool dfs3( int i )
{
	if( ok[i] )
		return(1);
	if( used[i] )
		return(0);
	used[i] = 1;
	int j;
	for( j = now[1][i] ; j ; j = last[1][j] )
		if( dfs3(e[1][j]) )
			return(1);
	return(0);
}

inline bool draw()
{
	int i,j;
	for( i = 1 ; i <= tot ; ++i )
		if( !dfn[i] )
			tarjan(i);
	for( i = 1 ; i <= tot ; ++i )
		for( j = now[0][i] ; j ; j = last[0][j] )
			{
				if( fa[i] != fa[e[0][j]] )
					set(1,fa[i],fa[e[0][j]]);
				else ok[fa[i]] = 1;
			}
	return( dfs3(fa[h*(r+1)+t+1]) );
}

int dfs2( int i, int j )
{
	if( i+j > r )
		return(0);
	if( hash[i][j] )
		return(g[i][j]);
	hash[i][j] = 1;

	int k;
	for( k = 1 ; k <= n && k <= i ; ++k )
		g[i][j] = max( g[i][j], dfs2(i-k+a[k][0],j+a[k][1])+1 );
	for( k = 1 ; k <= m && k <= j ; ++k )
		g[i][j] = max( g[i][j], dfs2(i+b[k][0],j-k+b[k][1])+1 );
	return(g[i][j]);
}

int main()
{
	int i,j;

	scanf("%d%d%d",&h,&t,&r);
	st = h*(r+1)+t+1;
	scanf("%d",&n);
	for( i = 1 ; i <= n ; ++i )
		scanf("%d%d",&a[i][0],&a[i][1]);
	scanf("%d",&m);
	for( i = 1 ; i <= m ; ++i )
		scanf("%d%d",&b[i][0],&b[i][1]);

	build();
	bfs();
	if( step[1] )
		printf("Ivan\n%d\n",step[1]-1);
	else if( draw() )
		printf("Draw\n");
	else
		{
			memset( hash, 0, sizeof(hash) );
			printf("Zmey\n%d\n",dfs2(h,t));
		}

	return(0);
}
