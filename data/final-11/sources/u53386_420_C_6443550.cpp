#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define M 310010
using namespace std;
vector<int> vec[M];

int in[M];
int n, p;
int vis[M];
int sum[M];
void add( int i, int v )
{
	while( i )
		sum[i] += v, i -= i & -i;
}
int query( int i )
{
	int ans = 0;
	while( i <= n )
		ans += sum[i], i += i & -i;
	return ans;
}
long long solve()
{
	long long ans = 0;
	int tmp = 0;
	int v;
	for( int i = 1; i <= n; ++i ){
		if( in[i] >= p ) ans += i - 1, ++tmp;
		else{
			for( int j = 0; j < vec[i].size(); ++j ){
				v = vec[i][j];
				add( in[v], -1 );
				--in[v];
				add( in[v], 1 );
			}
			ans += query( p - in[i] );
			for( int j = 0; j < vec[i].size(); ++j ){
				v = vec[i][j];
				add( in[v], -1 );
				++in[v];
				add( in[v], 1 );
			}
		}
		add( in[i], 1 );
	}
	return ans;
}

int main()
{
	int u, v;
	scanf( "%d%d", &n, &p );
	for( int i = 1; i <= n; ++i ){
		scanf( "%d%d", &u, &v );
		++in[u], ++in[v];
		if( u < v ) swap( u, v );
		vec[u].push_back( v );
	}
	cout<<solve()<<endl;
}
