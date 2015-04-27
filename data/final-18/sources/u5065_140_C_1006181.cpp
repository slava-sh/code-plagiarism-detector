#include <map> 
#include <set> 
#include <list>
#include <stack>
#include <cmath> 
#include <queue> 
#include <ctime>
#include <cfloat>
#include <vector> 
#include <string> 
#include <cstdio>
#include <bitset>
#include <climits> 
#include <cstdlib> 
#include <cstring> 
#include <cassert> 
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL

#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

template<typename T> T inline SQR( const T &a ){ return a*a; }
template<typename T> T inline ABS( const T &a ){ return a < 0 ? -a : a; }
template<typename T> T inline MIN( const T& a, const T& b){ if( a < b ) return a; return b; }
template<typename T> T inline MAX( const T& a, const T& b){ if( a > b ) return a; return b; }

const double EPS = 1e-9;
inline int SGN( double a ){ return ((a > EPS) ? (1) : ((a < -EPS) ? (-1) : (0))); }
inline int CMP( double a, double b ){ return SGN(a - b); }

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

#define MAXN 100000

int r[MAXN];
struct triple_t{
	int x, y, z;
	triple_t( int xx = 0, int yy = 0, int zz = 0 ){
		int a[3]; a[0] = xx, a[1] = yy, a[2] = zz;
		sort( a, a+3 );
		x = a[2];
		y = a[1];
		z = a[0];
	}
};

int main( int argc, char* argv[] ){
	
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	map< int, int > occ;
	REP( i, n ){
		int x; cin >> x;
		occ[x]++;
	}
	set< pair<int,int> > av;
	FORIT( x, occ ) av.insert( MP(-(x->second), x->first) );
	
	int ans = 0;
	vector< triple_t > aans;
	while( SIZE(av) >= 3 ){
		ans++;
		pair< int, int > x, y, z;
		x = *av.begin(); av.erase(x);
		y = *av.begin(); av.erase(y);
		z = *av.begin(); av.erase(z);
		aans.PB( triple_t(x.second, y.second, z.second) );
		x.first++; if( x.first ) av.insert(x);
		y.first++; if( y.first ) av.insert(y);
		z.first++; if( z.first ) av.insert(z);
	}
	cout << ans << "\n";
	REP( i, ans ) cout << aans[i].x << " " << aans[i].y << " " << aans[i].z << "\n";
	
	return 0;
}




















