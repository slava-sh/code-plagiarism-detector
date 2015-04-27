#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <map>
#include <cctype>
#include <unordered_set>
#include <unordered_map>

#define DEBUG 0

#if (DEBUG == 1)
    #define debug(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#else
    #define debug(fmt, ...)
#endif

#define INFTY 2000000000
#define INFTYLL 4000000000000000000LL
using namespace std;

typedef pair<int,int> pint;
typedef long long int lint;
typedef unsigned int unint;

/* FAST IO ********************** */
int onechar() {
    static const int BUFSIZE = 1<<20;
    static char buf[BUFSIZE], *ptr = buf+BUFSIZE;
    if (ptr == buf+BUFSIZE) {
        fread(buf, 1, BUFSIZE, stdin);
        ptr = buf;
    }
    return *ptr++;
}
int nextint() {
    char c;
    while (!isdigit(c = onechar()) && c != '-') ;
    int ans = c == '-' ? 0 : c-'0',
        sign = c == '-' ? -1 : 1;
    while (isdigit(c = onechar())) ans = ans * 10 + c-'0';
    return ans * sign;
}
char nextchar() { char c; while (isspace(c = onechar())); return c; }
string nextstring() {
    char c; string ret; while (!isspace(c = onechar())) ret += c;
    return ret;
}

/* ****************************** */

template <typename T> vector<T>& operator+=(vector<T> &v, const T &e) { v.push_back(e); return v; }
template <typename T> string tobin(T n) { string ret; do ret = char('0'+(n&1)) + ret; while (n /= 2); return ret; }
inline unint nextbitperm(unint mask) {
    unint ile = __builtin_ctz (mask), t = ~(mask>>ile), q = __builtin_ctz (t);
    return ~(((((((t>>q)-1)<<1)+1)<<ile)|((1<<(ile))-1))<<(q-1));
}

/* ****************************** */

/*
namespace std { namespace tr1 {
template <> struct hash< vector<int> > {
    size_t operator()(const std::vector<int>& v) const {
        size_t ret = 0, tmp = 1;
        for (int i=0; i<v.size(); i++, tmp *= 1000000009) {
            ret += tmp * v[i];
        }
        return ret;
    }
};
}}
*/

/* ****************************** */

template <typename T> struct RefType { typedef T& Ref; };
template <> struct RefType<bool> { typedef std::_Bit_reference Ref; };
template <typename T>
struct Vector
{
    vector<T> data;
    Vector(int s=0, const T& elem=T()) : data(s, elem) {}
    void push_back(const T& elem) { data.push_back(elem); }
    unsigned int size() const { return data.size(); }
    typename RefType<T>::Ref operator[](int k) {
        if (k<0 || k>=data.size()) {
            fprintf(stderr, "AAAAAAAAAAAAAAAA %d / %d\n", k, (int)data.size());
            abort();
        }
        return data[k];
    }
    T operator[](int k) const {
        if (k<0 || k>=data.size()) {
            fprintf(stderr, "const AAAAAAAAAAAAAAAA %d / %d\n", k, (int)data.size());
            while (true) ;
        }
        return data[k];
    }
    void clear() { data.clear(); }
    void resize(int n, const T& elem = T()) { data.resize(n, elem); }
};

/* ******************************* */

class Num
{
    static constexpr long long int MOD = 1000000007LL;
    long long val;
public:
    long long int get() const {
        return val;
    }
    Num(long long int x = 0LL) : val(x) {}
    Num operator+(const Num& other) const {
        return (val + other.val) % MOD;
    }
    Num operator*(const Num& other) const {
        return val * other.val % MOD;
    }
    Num operator-(const Num& other) const {
        return (val - other.val + MOD) % MOD;
    }
    static Num power(const Num& num, long long int k) {
        Num res = 1LL, curr = num;
        while (k) {
            if (k&1LL)
                res = res * curr;
            curr = curr * curr;
            k /= 2LL;
        }
        return res;
    }
    Num power(long long int k) const {
        return power(*this, k);
    }
    Num operator/(const Num& other) const {
        Num res = (*this) * power(other, MOD-2);
        assert((res * other).get() == this->get());
        return res;
    }
};

/* ****************************** */

char maps[1000][101];
int dif[1000][1000]; // i > j
struct E {
    int x, y, w;
    bool operator<(const E& e) const {
        return w > e.w;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    int R, C, L, K, W;
    scanf("%d %d %d %d", &R, &C, &K, &W);
    L = R*C;

    for (int k=0; k<K; k++) {
        for (int r=0; r<R; r++) {
            scanf("%s", maps[k] + r*C);
        }
    }

    for (int k1=0; k1<K; k1++) {
        for (int k2=0; k2<k1; k2++) {
            char *c1 = maps[k1], *c2 = maps[k2];
            int c = 0;
            for (int i=0; i<L; i++)
                c += c1[i] != c2[i];
            dif[k2][k1] = dif[k1][k2] = c * W;
        }
    }

    vector<bool> done(K, false);
    priority_queue<E> q;

    int mst = 0;
    done[0] = true;
    vector<pint> res;
    res.push_back(pint(1,0));
    for (int i=1; i<K; i++) {
        q.push({0,i,dif[0][i]});
        q.push({0,i,L});
    }

    int cnt = 1;
    while (cnt<K) {
        E e = q.top();
        q.pop();

        if (done[e.x] && done[e.y]) continue;
        int v = done[e.x] ? e.y : e.x;

        mst += e.w;
        done[v] = true;
        cnt ++;
        res.push_back(pint(v+1, e.w == L ? 0 : (e.x+e.y-v+1)));
        for (int i=0; i<K; i++) if (!done[i]) q.push({v,i,dif[v][i]});
    }

    printf("%d\n", mst + L);
    for (int i=0; i<K; i++) printf("%d %d\n", res[i].first, res[i].second);

    return 0;
}
