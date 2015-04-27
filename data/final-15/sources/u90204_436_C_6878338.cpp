#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <list>

#define YJP_LD

//general
#ifdef ONLINE_JUDGE
#undef YJP
#endif
#define llx "%I64d"

#ifdef YJP_LD
#define real long double
#else
#define real double
#endif
#define eps 1e-12

#ifdef YJP
FILE *_stderr = freopen("con", "w", stderr);
#else
FILE *_stderr = freopen("nul", "w", stderr);
#endif
#define debug(args...) fprintf(stderr, args)

//loop
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define f2(x, y, z) for(int x = (y), _asdf = (z); x <= asdf; ++x)
#define g(x, y, z) for(int x = (y); x < (z); ++x)
#define g2(x, y, z) for(int x = (y), _asdf = (z); x < asdf; ++x)
#define h(x, y, z) for(int x = (y); x >= (z); --x)
#define h2(x, y, z) for(int x = (y), _asdf = (z); x >= asdf; --x)
#define foreach(x, y) for(__typeof(y.begin()) x = y.begin(), _asdf = y.end(); x != _asdf; ++x)
#define rforeach(x, y) for(__typeof(y.rbegin()) x = y.rbegin(), _asdf = y.rend(); x != _asdf; ++x)

//type
typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef unsigned long long ULL;

//pair
using std::pair;
#define a first
#define b second
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<real, real> PRR;

//vector
using std::vector;
template <class T>
inline vector<T> &operator <<(vector<T> &x, const T &y){
	x.push_back(y); return x;
}
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<real> VR;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<PRR> VPRR;
typedef vector<VI> VVI;

//set & map
using std::set;
using std::map;
template <class T>
inline set<T> &operator <<(set<T> &x, const T &y){
	x.insert(y); return x;
}
typedef set<int> SI;
typedef set<LL> SLL;
typedef set<real> SR;
typedef set<VI> SVI;
typedef vector<SI> VSI;

//list
using std::list;
template <class T>
inline list<T> &operator <<(list<T> &x, const T &y){
	x.push_back(y); return x;
}
template <class T>
inline list<T> &operator >>(list<T> &x, const T &y){
	x.push_front(y); return x;
}

//FastIO
inline void read(int &x){
	char c = getchar();
	while(c < '0') c = getchar();
	x = 0;
	while(c >= '0') x = (x << 3) + (x << 1) + c - '0', c = getchar();
}
inline void read(LL &x){
	char c = getchar();
	while(c < '0') c = getchar();
	x = 0;
	while(c >= '0') x = (x << 3) + (x << 1) + c - '0', c = getchar();
}
inline void read(double &x){
	scanf("%lf", &x);
}
inline void read(long double &x){
	double tmp; scanf("%lf", &tmp); x = tmp;
}
inline void write(int x){
	if(x < 0){putchar('-'); x = -x;}
	if(x >= 1000000000) goto x9;
	else if(x >= 100000000) goto x8;
	else if(x >= 10000000) goto x7;
	else if(x >= 1000000) goto x6;
	else if(x >= 100000) goto x5;
	else if(x >= 10000) goto x4;
	else if(x >= 1000) goto x3;
	else if(x >= 100) goto x2;
	else if(x >= 10) goto x1;
	else goto x0;
	x9: putchar(x / 1000000000 + '0'); x %= 1000000000;
	x8: putchar(x / 100000000 + '0'); x %= 100000000;
	x7: putchar(x / 10000000 + '0'); x %= 10000000;
	x6: putchar(x / 1000000 + '0'); x %= 1000000;
	x5: putchar(x / 100000 + '0'); x %= 100000;
	x4: putchar(x / 10000 + '0'); x %= 10000;
	x3: putchar(x / 1000 + '0'); x %= 1000;
	x2: putchar(x / 100 + '0'); x %= 100;
	x1: putchar(x / 10 + '0'); x %= 10;
	x0: putchar(x + '0');
}
inline void write(const LL x){
	printf(llx, x);
}
#define writeln(x) (write(x), putchar('\n'))

//function
template <class T>
inline T min(const T x, const T y){
	if(x < y) return x; else return y;
}
template <class T>
inline T &min2(const T &x, const T &y){
	if(x < y) return x; else return y;
}
template <class T>
inline T max(const T x, const T y){
	if(x > y) return x; else return y;
}
template <class T>
inline T &max2(const T &x, const T &y){
	if(x > y) return x; else return y;
}
template <class T>
inline T sqr(const T x){
	return x * x;
}
template <class T>
inline T sqr2(const T &x){
	return x * x;
}

int n, m, k, w;
struct M{
	char dat[11][11];
	inline M(){}
	inline void read(){
		g(i, 0, n) scanf("%s", dat[i]);
	}
};
inline int diff(const M &x, const M &y){
	int ans = 0;
	g(i, 0, n) g(j, 0, m) ans += (x.dat[i][j] != y.dat[i][j]);
	return ans;
}
M ma[1001];

struct edge{int s, t, w;} E[1111111], *ce = E;
inline bool operator <(const edge &x, const edge &y){
	return x.w < y.w;
}

int fa[1086];
inline int gf(int x){
	if(x == fa[x]) return x; else return fa[x] = gf(fa[x]);
}
VI adj[1086];

inline void dfs(int x, int p){
	if(x) printf("%d %d\n", x, p);
	foreach(s, adj[x]) if(*s != p) dfs(*s, x);
}

int main(){
	read(n); read(m); read(k); read(w);
	f(i, 1, k) ma[i].read();
	int nm = n * m;
	f(i, 1, k) *(ce++) = (edge) {0, i, nm};
	f(i, 1, k) f(j, i + 1, k) *(ce++) = (edge) {i, j, diff(ma[i], ma[j]) * w};
	std::sort(E, ce);
	f(i, 0, k) fa[i] = i;
	int ans = 0;
	for(edge *e = E; e != ce; ++e){
		int fs = gf(e->s), ft = gf(e->t);
		if(fs != ft){
			fa[fs] = ft;
			adj[e->s].push_back(e->t);
			adj[e->t].push_back(e->s);
			ans += e->w;
		}
	}
	printf("%d\n", ans);
	dfs(0, 0);
	return 0;
}































