#include <bits/stdc++.h>
using namespace std;

#ifdef ILIKEGENTOO
#   define Eo(x) { cerr << #x << " = " << (x) << endl; }
#   define E(x) { cerr << #x << " = " << (x) << "   "; }
#   define FREOPEN(x)
#else
#   define Eo(x) {}
#   define E(x) {}
#   define FREOPEN(x) (void)freopen(x ".in", "r", stdin);(void)freopen(x ".out", "w", stdout);
#endif
#define EO(x) Eo(x)
#define Sz(x) (int((x).size()))
#define All(x) (x).begin(),(x).end()

template<class A, class B> ostream &operator<<(ostream &os, const pair<A, B>& p) { return os << '(' << p.first << ", " << p.second << ')'; }

template<class C> void operator<<(vector<C> &v, const C &x){v.push_back(x);}
template<class D> void operator>>(vector<D> &v, D &x){assert(!v.empty()); x=v.back(); v.pop_back();}
template<class E> void operator<<(set<E> &v, const E &x){v.insert(x);}

typedef double flt;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int, int> pii;

const int inf = 0x3f3f3f3f;
const int64 inf64 = 0x3f3f3f3f3f3f3f3fLL;
const flt eps = 1e-8;
const flt pi = acos(-1.0);
const int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

random_device rdev; mt19937 rmt(rdev()); uniform_int_distribution<> rnd(0, 0x7fffffff);
inline int mrand(int mod = 0x7fffffff) { return rnd(rmt) % mod; }

const int maxn = 2000016;

char t[maxn], s[maxn];
int lt, ls;
bool havet[300], haves[300];

char pret[26][maxn];
char pres[26][maxn];

void checkHave(char *st, bool *have, int len) {
    for (int i = 0; i < len; ++i)
        have[st[i]] = true;
}

void genPre(char *str, char preto[26][maxn], int len) {
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < len; ++j)
            preto[i][j] = (str[j] == 'a' + i ? '1' : '0');
    }
}

char zs[maxn * 2];
int z[maxn * 2];
int zlen;
void z_function(int startpos) {
    int i, j = 0, r = 0;
    z[0] = zlen;
    for (i = startpos; i < zlen; ++i) {
    //for (i = 1; i < zlen; ++i) {
        z[i] = max(min(r - i, z[i - j]), 0);
        for ( ; i + z[i] < zlen && zs[z[i]] == zs[i + z[i]]; ++z[i]);
        if (i + z[i] > r) {
            r = i + z[i];
            j = i;
        }
    }
}

char mapto[26][maxn];

int main() {
    memset(mapto, 50, sizeof(mapto));
    scanf("%d %d", &ls, &lt);
    scanf("%s %s", s, t);

    int tlenaligned = lt / 16 * 16 + 16;
    for (int i = lt; i < tlenaligned; ++i) zs[i] = '$';
    zlen = tlenaligned + ls;

    checkHave(s, haves, ls);
    checkHave(t, havet, lt);
    genPre(s, pres, ls);
    genPre(t, pret, lt);

    for (int i = int('a'); i <= int('z'); ++i) if (havet[i]) {
        const int ii = i - 'a';
        memcpy(zs, pret[ii], lt);
        bool calced = false;
        for (int j = int('a'); j <= int('z'); ++j) if (haves[j]) {
            const int jj = j - 'a';
            memcpy(zs + tlenaligned, pres[jj], ls);
            if (calced)
                z_function(tlenaligned);
            else {
                z_function(1);
                calced = true;
            }

            for (int k = 0; k < ls; ++k) if (z[tlenaligned + k] == lt) {
                //E(i); E(j); Eo(k);
                mapto[ii][k] = jj;
            }
        }
    }

    vector<int> res;
    for (int k = 0; k < ls; ++k) {
        E(k); Eo("========");
        bool ok = true;
        for (int j = 0; j < 26; ++j) if (havet[j + 'a']) {
            int curto = mapto[j][k];
            E(j); Eo(int(curto));
            if (curto == 50) {
                ok = false;
                break;
            }
            if (mapto[curto][k] != 50 && mapto[curto][k] != j) {
                ok = false;
                break;
            }
        }
        if (ok) { res.push_back(k + 1); }
    }

    printf("%d\n", Sz(res));
    for (int i : res) printf("%d ", i);
    puts("");

    return 0;
}
