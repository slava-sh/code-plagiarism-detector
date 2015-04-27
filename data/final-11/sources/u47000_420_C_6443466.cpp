#include <bits/stdc++.h>

#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lli long long int
#define all( gg )	gg.begin(),gg.end()
#define foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define FP( ii,aa,bb ) for( int ii=aa;ii<=bb;ii++ )
#define FM( ii,aa,bb ) for( int ii=aa;ii>=bb;ii-- )

#define maxn 400000

using namespace std;

int n,p,s[maxn];
int arr[maxn];
vector< pair<int,int> >	v2[maxn],v[maxn];

int main(){

	scanf("%d %d",&n,&p);
	
	int x,y;
	FP( i,1,n ){
		scanf("%d %d",&x,&y);
		s[x]++;
		s[y]++;
		v2[x].pb( mp(y,1) );
		v2[y].pb( mp(x,1) );
	}
	FP( i,1,n ){
		sort( all( v2[i] ) );
		foreach( v2[i],it ){
			if( !v[i].size() or v[i].back().st!=it->st )	v[i].pb( *it );
			else	v[i].back().nd++;
		}
	}
	FP( i,1,n )	arr[i] = s[i];
	
	sort( arr+1,arr+n+1 );
	
	lli res=0,k;
	FP( i,1,n ){
		k = p-s[i];
		res += arr+n+1-lower_bound( arr+1,arr+n+1,k );
		if( s[i]>=k )	res--;
		foreach( v[i],it )
			if( it->st!=i and s[it->st]>=k and s[it->st]-it->nd<k )	res--;
	}
	
	cout << res/2 << endl;

}


