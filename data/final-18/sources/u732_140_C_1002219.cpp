#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stack>
#include <cassert>
#include <memory.h>
#ifdef NEV_DEBUG
#include <ctime>
#endif
#pragma comment(linker,"/STACK:64000000")
using namespace std;
const double pi = 3.1415926535897932384626433832795;
double eps = 1e-9;
//double eps=1e-15; // atan up to 1e-15

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

#define sz size()
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=(a),_b(b); i<_b; ++i)
#define RFOR(i,a,b) for(int i=(a)-1,_b(b); i>=_b; --i)
#define CLR(a,b) memset(a,b,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define sqr(a) ((a)*(a))

char ch[1 << 20];
inline string gs() {scanf("%s", ch);return string(ch);}
inline string gl() {gets(ch);return string(ch);}
inline int gi() {int x;scanf("%d", &x);return x;}
void error() {while(1);int ttt = 0;cout << 7 / ttt;}
template<class T> T gcd(T a, T b) { return (!a) ? b : gcd(b % a, a);}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
#ifdef NEV_DEBUG
    freopen("in.txt", "r", stdin);
    //freopen("out.txt","w",stdout);
    clock_t beg = clock();
#else
    //freopen("bsmooth.in","r",stdin);
    //freopen("bsmooth.out","w",stdout);
#endif
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////


    set<PII> Q;
    map<int,int> A;
    int n =gi();
    FOR(i,0,n) ++A[gi()];
    for(map<int,int>::const_iterator it = A.begin(); it!=A.end(); ++it) {
    	Q.insert(mp(-it->second,it->first));
    }

    vector<pair<PII,int> > R;
    while(Q.sz>=3) {
    	PII v1 = *Q.begin(); Q.erase(Q.begin());
    	PII v2 = *Q.begin(); Q.erase(Q.begin());
    	PII v3 = *Q.begin(); Q.erase(Q.begin());
    	v1.first ++ ;
    	v2.first ++ ;
    	v3.first ++ ;
    	int a = v1.second;
    	int b = v2.second;
    	int c = v3.second;
    	if (a<b) swap(a,b);
    	if (a<c) swap(a,c);
    	if (b<c) swap(b,c);
    	R.pb(mp(mp(a,b),c));
    	if (v1.first<0) Q.insert(v1);
    	if (v2.first<0) Q.insert(v2);
    	if (v3.first<0) Q.insert(v3);
    }
    printf("%d\n",R.sz);
    FOR(i,0,R.sz) printf("%d %d %d\n",R[i].first.first,R[i].first.second,R[i].second);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef NEV_DEBUG
    fprintf(stderr, "*** Total time: %.3lf ***\n",
            1.0 * (clock() - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}
