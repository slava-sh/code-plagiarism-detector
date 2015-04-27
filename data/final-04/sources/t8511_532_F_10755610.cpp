#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#pragma comment(linker, "/STACK:66777216")
#else
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#endif
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long

/* ===================== */
static unsigned rnd() {
	static unsigned y = 124612741 + time(0);
	y ^= y << 13;
	y ^= y >> 17;
	return y ^= y << 5;
}
inline int fpow(int a, int st, int mod) {
	int ans = 1;
	while (st) {
		if (st % 2) ans = (long long)ans * a % mod;
		a = (long long)a * a % mod;
		st /= 2;
	}
	return ans;
}

// Computes x^-1 modulo y
int invmod(int x, int y) {
	int a = 1, b = 0, k;
	for (; y; swap(x, y), swap(a, b)) {
		k = x / y;
		x -= y * k;
		a -= b * k;
	}
	return a + max(b, 0);
}

inline int calcBits(int a) {
#ifdef _MSC_VER
	return _mm_popcnt_u32(a);
#else
	return __builtin_popcount(a);
#endif
}
struct Hash {
	Hash() : x1(0), x2(0) {}
	Hash(const int& x1, const int& x2) : x1(x1), x2(x2) {}
	int x1, x2;

	static int mod1, mod2;
	static int p1, p2;
	static int invp1, invp2;
	static bool initCalled;
	static const Hash ONE, ZERO, INVALID;
	static Hash UNIT, INV_UNIT;
	static bool prime(int a) {
		if (a == 1) return 0;
		for (int i = 2; i * i <= a; ++i) {
			if (a % i == 0) return false;
		}
		return true;
	}
	static int pickModHelper(int start, int bad) {
		int mn = INF, best = -1;
		FOR(i, start, start + 5000) {
			if (i == bad || !prime(i)) continue;
			int cur = calcBits(i);
			if (cur < mn) {
				mn = cur;
				best = i;
			}
		}
		return best;
	}
	static void init() {
		if (initCalled) return;
		initCalled = true;
		mod1 = pickModHelper(INF + rnd() % 10000000, -1);
		mod2 = pickModHelper(INF + rnd() % 10000000, mod1);

		invp1 = invmod(p1, mod1);
		invp2 = invmod(p2, mod2);
		INV_UNIT = Hash(invp1, invp2);
	}

	inline Hash& operator +=(const Hash& other) {
		x1 += other.x1;
		if (x1 >= Hash::mod1) x1 -= Hash::mod1;
		x2 += other.x2;
		if (x2 >= Hash::mod2) x2 -= Hash::mod2;
		return *this;
	}
	inline Hash& operator -=(const Hash& other) {
		x1 -= other.x1;
		if (x1 < 0) x1 += Hash::mod1;
		x2 -= other.x2;
		if (x2 < 0) x2 += Hash::mod2;
		return *this;
	}
	inline Hash& operator *=(const Hash& other) {
		x1 = (ll)x1 * other.x1 % Hash::mod1;
		x2 = (ll)x2 * other.x2 % Hash::mod2;
		return *this;
	}
	inline Hash& operator *=(const int& other) {
		x1 = (ll)x1 * other % Hash::mod1;
		x2 = (ll)x2 * other % Hash::mod2;
		return *this;
	}
	inline Hash& operator^=(const int& power) {
		int st = power;
		Hash ans(1, 1);
		while (st) {
			if (st % 2) ans *= *this;
			x1 = (long long)x1 * x1 % Hash::mod1;
			x2 = (long long)x2 * x2 % Hash::mod2;
			st /= 2;
		}
		return *this;
	}
	inline bool operator ==(const Hash& other) const {
		return x1 == other.x1 && x2 == other.x2;
	}
};
bool Hash::initCalled = false;
int Hash::mod1 = 0;
int Hash::mod2 = 0;
int Hash::p1 = 23561;
int Hash::p2 = 10000019;
int Hash::invp1 = -1;
int Hash::invp2 = -1;
const Hash Hash::ONE(1, 1);
const Hash Hash::ZERO(0, 0);
const Hash Hash::INVALID(-1, -1);
Hash Hash::UNIT(Hash::p1, Hash::p2);
Hash Hash::INV_UNIT(-1, -1);

inline Hash operator +(const Hash& a, const Hash& b) {
	Hash ans(a.x1 + b.x1, a.x2 + b.x2);
	if (ans.x1 >= Hash::mod1) ans.x1 -= Hash::mod1;
	if (ans.x2 >= Hash::mod2) ans.x2 -= Hash::mod2;
	return ans;
}
inline Hash operator -(const Hash& a, const Hash& b) {
	Hash ans(a.x1 - b.x1, a.x2 - b.x2);
	if (ans.x1 < 0) ans.x1 += Hash::mod1;
	if (ans.x2 < 0) ans.x2 += Hash::mod2;
	return ans;
}
inline Hash operator *(const Hash& a, const Hash& b) {
	return Hash((long long)a.x1 * b.x1 % Hash::mod1, (long long)a.x2 * b.x2 % Hash::mod2);
}
inline Hash operator *(const Hash& a, const int &b) {
	return Hash((long long)a.x1 * b % Hash::mod1, (long long)a.x2 * b % Hash::mod2);
}
inline Hash operator^(const Hash& a, const int& power) {
	int st = power;
	Hash ans(1, 1), cur(a);
	while (st) {
		if (st % 2) ans *= cur;
		cur *= cur;
		st /= 2;
	}
	return ans;
}
inline Hash fpow(const Hash& a, const int& power) {
	return a ^ power;
}
inline Hash invmod(const Hash& a) {
	return Hash(invmod(a.x1, Hash::mod1), invmod(a.x2, Hash::mod2));
}
/* ==================== */

/* ==================== */
template<class H>
struct HashString : public string {
	HashString() : string() {
		precalc(0);
	}
	HashString(const HashString& other) : string(other) {
		precalc(size());
	}
	HashString(HashString&& other)
		: hh(std::move(other.hh)),
		string(std::move(other)) {
		precalc(size());
	}

	HashString(const string& other) : string(other)  {
		precalc(size());
		build();
	}
	HashString(string&& other) : string(std::move(other)) {
		precalc(size());
		build();
	}

	HashString(const char* other) : string(other) {
		precalc(size());
		build();
	}
	inline void clear() {
		hh.clear();
		string::clear();
	}

	inline static H getPow(int p) {
		if (p < haveN) {
			return pp[p];
		}
		else {
			return fpow(H::UNIT, p);
		}
	}
	inline static H getInvPow(size_t p) {
		if (p < invpp.size()) {
			return invpp[p];
		}
		else {
			return fpow(H::INV_UNIT, p);
		}
	}
	inline H getInvRegister(const H& p) const {
		if (p == register_) {
			return registerValue_;
		}
		else {
			register_ = p;
			return registerValue_ = invmod(p);
		}
	}
	static void precalc(int N = 0) {
		Hash::init();
		if (haveN >= N) return;
		pp.resize(N);
		invpp.resize(N);
		if (!haveN) {
			pp[0] = H::ONE;
			invpp[0] = H::ONE;
			haveN = 1;
		}
		for (int i = haveN; i < N; ++i) {
			pp[i] = pp[i - 1] * H::UNIT;
			invpp[i] = invpp[i - 1] * H::INV_UNIT;
		}
		haveN = N;
	}
	inline void build() {
		int curSize = size();
		if (haveN <= curSize) {
			precalc(curSize);
		}
		for (int i = hh.size(); i < curSize; ++i) {
			H pr = i ? hh.back() : H::ZERO;
			hh.push_back(pr + getPow(i) * (*this)[i]);
		}
	}

	// Computes and returns hash of a cyclic string starting from position pos and of length len.
	// len can be larger than string length.
	inline H getHash(int pos, int len) const {
		if (len <= 0) return H::ZERO;
		const int S = size();
		if (pos + len - 1 < S) {
			H ans = hh[pos + len - 1];
			if (pos) {
				ans -= hh[pos - 1];
				ans *= getInvPow(pos);
			}
			return ans;
		}
		else {
			H head = hh.back();
			if (pos) {
				head -= hh[pos - 1];
				head *= getInvPow(pos);
			}

			int full = -1, en = -1;
			H mid = H::ZERO;
			int midlen = 0;
			if (len <= S) {
				en = pos + len - 1 - S;
				H tail = hh[en];
				full = 0;
				return head + tail * getPow(S - pos);
			}
			else {
				en = (pos + len - 1) % S;
				H tail = hh[en];
				full = (len - (S - pos) - (en + 1)) / S;
				mid = hh.back() * (H::ONE - getInvPow(full * S)) * getInvRegister(H::ONE - getInvPow(S));
				return head + mid * getPow(S - pos) + tail * getPow(len - (en + 1));
			}
		}
	}

	inline HashString& operator +=(const char& ch) {
		string::operator+=(ch);
		build();
		return *this;
	}
	inline HashString& operator +=(const HashString& other) {
		string::operator+=(other);
		build();
		return *this;
	}
	inline bool operator ==(const HashString& other) const {
		return hh.back() == other.hh.back();
	}
	inline bool operator <(const HashString& other) const {
		int s1 = size();
		int s2 = other.size();
		const int S = min(s1, s2);
		int l = 0, r = S + 1;
		while (r - l > 1) {
			int xx = (r + l) / 2;
			if (getHash(0, xx) == other.getHash(0, xx)) l = xx; else
				r = xx;
		}
		char c1 = 0, c2 = 0;
		if (l < s1) c1 = (*this)[l];
		if (l < s2) c2 = other[l];
		return c1 < c2;
	}
	inline bool operator <=(const HashString& other) const {
		return (*this == other) || (*this < other);
	}
	inline bool operator >(const HashString& other) const {
		return !(*this == other) && !(*this < other);
	}
	inline bool operator >=(const HashString& other) const {
		return !(*this < other);
	}
	inline bool operator !=(const HashString& other) const {
		return !(*this == other);
	}
	inline void reserve(int N) {
		hh.reserve(N);
		string::reserve(N);
	}

	vector<H> hh;
	static vector<H> pp, invpp;

private:
	mutable H register_, registerValue_;
	static int haveN;
};
template<>
int HashString<Hash>::haveN = 0;
template<>
vector<Hash> HashString<Hash>::pp = vector<Hash>();
template<>
vector<Hash> HashString<Hash>::invpp = vector<Hash>();
/* ========================= */


int a, b, c, d, n, m, k;
Hash pc[27][27];
char str[200002];
int nx1[200002][27];
int sp[27];
int cp[27];
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	scanf("%s", str);
	HashString<Hash> s1(str);
	scanf("%s", str);
	HashString<Hash> s2(str);

	rept(i, 26) {
		rept(j, i + 1) {
			Hash cur = Hash::ZERO;
			rept(z, m) {
				if (str[z] != i + 'a' && str[z] != j + 'a') continue;
				if (str[z] == i + 'a') {
					cur = cur + s2.getPow(z) * (j + 'a');
				}
				else {
					cur = cur + s2.getPow(z) * (i + 'a');
				}
			}
			pc[i][j] = pc[j][i] = cur;
		}
	}

	memset(nx1, 63, sizeof(nx1));
	FORD(i, n - 1, 0) {
		if (i != n - 1) memmove(nx1[i], nx1[i + 1], 26 * sizeof(int));
		nx1[i][s1[i] - 'a'] = i;
	}
	memset(sp, 63, sizeof(sp));
	rept(i, m) {
		sp[s2[i] - 'a'] = i;
	}

	VI res;
	rept(i, n) {
		if (i + m - 1 >= n) break;
		memset(cp, -1, sizeof(cp));
		bool ok = 1;
		rept(z, 26) {
			int pos = nx1[i][z];
			if (pos >= i && pos <= i + m - 1) {
				int v = s2[pos - i] - 'a';
				if (cp[z] != -1 && cp[z] != v) {
					ok = 0;
					break;
				}
				if (cp[v] != -1 && cp[v] != z) {
					ok = 0;
					break;
				}
				cp[v] = z;
				cp[z] = v;
			}
			pos = sp[z];
			if (pos >= 0 && pos < m) {
				int v = s1[i + pos] - 'a';
				if (cp[z] != -1 && cp[z] != v) {
					ok = 0;
					break;
				}
				if (cp[v] != -1 && cp[v] != z) {
					ok = 0;
					break;
				}
				cp[v] = z;
				cp[z] = v;
			}
		}
		if (!ok) continue;

		rept(j, 26) {
			if (cp[j] == -1) cp[j] = j;
		}
		Hash sum = Hash::ZERO;
		rept(j, 26) {
			if (cp[j] <= j) {
				sum = sum + pc[j][cp[j]];
			}
		}
		Hash et = s1.getHash(i, m);
		if (sum == et) {
			res.pb(i);
		}
	}
	printf("%d\n", L(res));
	rept(i, L(res)) {
		if (i) printf(" ");
		printf("%d", res[i] + 1);
	}
	printf("\n");
}