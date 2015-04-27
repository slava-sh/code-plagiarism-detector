#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
#include<map>
#include<vector>
#include<bitset>
using namespace std;
#define M 4000010
#define N 2010
#define MP make_pair
#define PB push_back

int vv[M], nxt[M], h[N], e;
int dfn[N], low[N], sta[N], deep, flag, col[N];
int top;
int num[N], cnt[N];
void add( int u, int v )
{
	vv[e] = v, nxt[e] = h[u], h[u] = e++;
	vv[e] = u, nxt[e] = h[v], h[v] = e++;
}

bitset< 2010 > bb;
void dfs( int u, int f )
{
	dfn[u] = low[u] = ++deep;
	sta[++top] = u;
	int v, x;
	for( int i = h[u]; i + 1; i = nxt[i] ) if( i - f ){
		v = vv[i];
		if( !dfn[v] ){
			dfs( v, i ^ 1 );
			low[u] = min( low[u], low[v] );
			if( low[v] > dfn[u] ){
				++flag; num[flag] = 0;
				x = v;
				while( top ){
					v = sta[top--];
					col[v] = flag;
					++num[flag];
					if( v == x ) break;
				}
			}
		}
		else low[u] = min( low[u], dfn[v] );
	}
}

long long cal( int u, int f )
{
	cnt[u] = num[u];
	int v;
	long long ans = ( num[u] - 1LL ) * num[u];
	for( int i = h[u]; i + 1; i = nxt[i] ){
		v = vv[i];
		if( v == f ) continue;
		ans += cal( v, u );
		ans += 1LL * num[u] * cnt[v];
		cnt[u] += cnt[v];
	}
	return ans;
}
long long cal( int u )
{
	long long tmp = 0;
	int v;
	bb.reset();
	bb[0] = 1;
	long long sum = ( num[u] - 1LL ) * num[u] ;
	int s = 0;
	for( int i = h[u]; i + 1; i = nxt[i] ){
		v = vv[i];
		tmp = cal( v, u );
		sum += tmp;
		bb = bb | ( bb << cnt[v] );
		sum += 1LL * cnt[v] * num[u];
		s += cnt[v];
	}
	long long maxv = 0;
	for( int i = 1; i <= s; ++i ) if( bb[i] ){
		maxv = max( maxv, 1LL * i * ( s - i ) );
	}
	return sum + maxv;
}
long long solve( int n, int m )
{
	memset( dfn, 0, sizeof(dfn) );
	deep = flag = top = 0;
	dfs( 1, -1 );
	memset( h, -1, sizeof(h) ), e = 0;
	int u, v;
	if( top ){
		++flag; num[flag] = 0;
		while( top ){
			v = sta[top--];
			col[v] = flag;
			num[flag]++;
		}
	}
	long long ans = 0, tmp;
	for( int i = 0; i < 2 * m; i += 2 ){
		u = vv[i], v = vv[i^1];
		if( col[v] - col[u] ) 
			add( col[u], col[v] );
	}
	for( int i = 1; i <= flag; ++i ){
		tmp = cal( i );
		ans = max( ans, tmp );
	}
	return ans + n;
}
int main()
{
	int u, v;
	int n, m;
	cin>>n>>m;
	memset( h, -1, sizeof(h) ), e = 0;
	for( int i = 1; i <= m; ++i ){
		scanf( "%d%d", &u, &v );
		add( u, v );
	}
	long long ans = solve( n, m );
	printf( "%I64d\n", ans );
}