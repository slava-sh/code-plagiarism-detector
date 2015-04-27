/*
 * temp.cpp
 *
 *  Created on: 2012-7-18
 *      Author: BSBandme
 */
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cassert>
#include <list>
#include <iomanip>
#include <math.h>
#include <deque>
#include <utility>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <climits>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <sstream>
#include <tr1/unordered_map>
#include <tr1/unordered_set>

using namespace std;
using namespace tr1;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return a > b ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

inline int jud(double a, double b){
	if(abs(a) < eps && abs(b) < eps) return 0;
	else if(abs1(a - b) / abs1(a) < eps) return 0;
	if(a < b) return -1;
	return 1;
}
template <typename t> inline int jud(t a, t b){
	if(a < b) return -1;
	if(a == b) return 0;
	return 1;
}

// f_lb == 1代表返回相同的一串的左边界，f_small == 1代表返回如果没有寻找的值返回小的数
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1){
	int be = 0, en = na - 1;
	if(*a <= *(a + na - 1)){
		if(f_lb == 0) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != 1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != -1) en = mid;
			else be = mid + 1;
		}
		if(f_small && jud(*(a + be), val) == 1) be--;
		if(!f_small && jud(*(a + be), val) == -1) be++;
	} else {
		if(f_lb) while(be < en){
			int mid = (be + en + 1) / 2;
			if(jud(*(a + mid), val) != -1) be = mid;
			else en = mid - 1;
		}else while(be < en){
			int mid = (be + en) / 2;
			if(jud(*(a + mid), val) != 1) en = mid;
			else be = mid + 1;
		}
		if(!f_small && jud(*(a + be), val) == -1) be--;
		if(f_small && jud(*(a + be), val) == 1) be++;
	}
	return be;
}

template <class T> inline T lowb(T num) {return num & (-num); }
inline int bitnum(ui nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(ull nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitnum(ll nValue) { return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32); }
inline int bitmaxl(ui a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(int a) { if(a == 0) return 0; return 32 - __builtin_clz(a); }
inline int bitmaxl(ull a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }
inline int bitmaxl(ll a) { int temp = a >> 32; if(temp) return 32 - __builtin_clz(temp) + 32; return bitmaxl(int(a)); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1;
	long long k = n;
	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}
	return ans;
}

#define  MOD 1000000007
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
	if(mod == -1) mod = MOD;
	a += b;
	while(a >= mod) a -= mod;
	while(a < 0) a += mod;
}
template <class t>
void output1(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		cerr << arr[i] << ' ';
	cerr << endl;
}
template <class t>
void output2(t arr) {
	for(int i = 0; i < (int)arr.size(); i++)
		output1(arr[i]);
}


//#define debug
//.........................mi.......feng......xian.......xia.......jin.......zhi.......hack...............................................

/*==================================================*\
| Tarjan强连通分量
| INIT: vec[]为邻接表; stop, cnt, scnt置0; pre[]置-1;
| CALL: for(i=0; i<n; ++i) if(-1==pre[i]) tarjan(i, n);
\*==================================================*/
const int V = 2010;
vector<int> vec[V];
int id[V], pre[V], low[V], s[V], stop, cnt, scnt;
void tarjan(int v, int n, int fa) { // vertex: 0 ~ n-1
	int t, minc = low[v] = pre[v] = cnt++;
	vector<int>::iterator pv;
	s[stop++] = v;
	for (pv = vec[v].begin(); pv != vec[v].end(); ++pv) if(*pv != fa){
		if (-1 == pre[*pv]) tarjan(*pv, n, v);
		if (low[*pv] < minc) minc = low[*pv];
	}
	if (minc < low[v]) {
		low[v] = minc;
		return;
	}
	do {
		id[t = s[--stop]] = scnt;
		low[t] = n;
	} while (t != v);
	++scnt; // 强连通分量的个数
}

const int maxn = V;
int val[maxn];
struct edge {
	int to, nxt;
} e[maxn * 2];
int head[maxn], le;
int n, m;
int rans;

inline void addedge(int a, int b) {
	e[le].to = b;
	e[le].nxt = head[a];
	head[a] = le++;
}

inline int dfs(int no, int fa) {
	int sum = val[no];
	for(int i = head[no]; i != -1; i = e[i].nxt) if(e[i].to != fa){
		int rsum = dfs(e[i].to, no);
		rans += rsum * val[no];
		sum += rsum;
	}
	return sum;
}

int main(){
	ios_base::sync_with_stdio(0);
	#ifdef debug //......................................................................................................
	freopen("input.txt", "r", stdin);
	int __size__ = 256 << 20; // 256MB
	char *__p__ = (char*)malloc(__size__) + __size__;
	__asm__("movl %0, %%esp\n" :: "r"(__p__));
	#endif //...........................................................................................................

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	memset(pre, -1, sizeof(pre));
	for(int i = 0; i < n; i++) if(pre[i] == -1)
		tarjan(i, n, -1);

	memset(head, -1, sizeof(head));
	for(int i = 0; i < n; i++) {
		val[id[i]]++;
		for(int j = 0; j < (int)vec[i].size(); j++) if(id[vec[i][j]] != id[i]) {
//			cerr << id[i] << ' ' << id[vec[i][j]] << endl;
			addedge(id[i], id[vec[i][j]]);
		}
	}
	int ans = 0;
	int pp = 0;
	for(int i = 0; i < scnt; i++) pp += val[i] * val[i];
	for(int i = 0; i < scnt; i++) {
		rans = 0;
		bitset <maxn> dp;
		dp.set(0, 1);
		for(int j = head[i]; j != -1; j = e[j].nxt) {
			int k = dfs(e[j].to, i);
			dp |= dp << k;
		}
		rans += (n - val[i]) * val[i];
		int maxv = 0;
		for(int j = 0; j <= n; j++) if(dp.test(j)){
			maxv = max(maxv, (n - val[i] - j) * j);
		}
		rans += maxv;
		if(rans > ans) ans = rans;
	}
	cout << ans + pp << endl;

    return 0;
}
