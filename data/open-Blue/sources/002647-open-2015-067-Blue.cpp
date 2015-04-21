#include <bits/stdc++.h>
#include <unordered_set>
#define ff first
#define ss second
#define szof(_x) (int) (_x).size()
#define bend(_x) (_x).begin(), (_x).end()
#define mapa make_pair
#define puba push_back
#define hash my_hash

using namespace std;
typedef pair <int, int> pii;
typedef long long LL;
const LL MOD1 = 1e9 + 7, P1 = 37, MAXN = 2e4 + 5;

struct hash {
    LL a;
    hash() {
        a = 0;
    }
    hash(LL _a) {
        a = _a;
    }
    bool operator==(hash h) {
        return a == h.a;
    }
    bool operator!=(hash h) {
        return a != h.a;
    }
    hash operator+(hash h) {
        return hash(a + h.a);
    }
    hash operator-(hash h) {
        return hash(a - h.a);
    }
    hash operator*(hash h) {
        return hash(a * h.a);
    }
    hash operator%(hash h) {
        hash ret = hash(a);
        ret.a %= h.a;
        if (ret.a < 0) {
            ret.a += h.a;
        }
        return ret;
    }
};


hash mod = hash(MOD1);
hash prod = hash(P1);
int l;
string s;
hash sprod[MAXN];
hash prec[MAXN];

unordered_set <LL> was;

hash get_hash(int l, int r) {
    return (prec[r + 1] - prec[l] * sprod[r - l + 1]) % mod;
}

int check1(int ls) {
    if (ls > l) {
        return 0;
    }
    for (int i = 0; i < szof(s); ++i) {
        if (s[i] != s[i % ls]) {
            return 0;
        }
    }
    cout << 1 << endl;
    for (int i = 0; i < ls; ++i) {
        cout << s[i];
    }
    cout << endl;
    if (clock() > CLOCKS_PER_SEC * 2) {
        exit(1);
    }
    exit(0);
}

bool d[MAXN];

int check2(int l1, int r1, int l2, int r2) {
    hash h1 = get_hash(l1, r1);
    hash h2 = get_hash(l2, r2);
    if (!was.insert(h1.a << 32 | h2.a).ss) {
        return 0;
    }

    l1 = r1 - l1 + 1;
    l2 = r2 - l2 + 1;
    
    memset(d, 0, sizeof d);
    d[0] = 1;
    for (int i = 0; i <= szof(s); ++i) {
        if (i >= l1 && get_hash(i - l1, i - 1) == h1) {
            d[i] |= d[i - l1];
        }
        if (i >= l2 && get_hash(i - l2, i - 1) == h2) {
            d[i] |= d[i - l2];
        }
    }
    if (!d[szof(s)]) {
        return 0;
    }
    cout << 2 << "\n";
    for (int i = r1 - l1 + 1; i <= r1; ++i) {
        cout << s[i];
    }
    cout << "\n";
    for (int i = r2 - l2 + 1; i <= r2; ++i) {
        cout << s[i];
    }
    cout << "\n";
    if (clock() > CLOCKS_PER_SEC * 2) {
        exit(1);
    }
    exit(0);
}

int main() {
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    sprod[0] = hash(1);
    for (int i = 1; i < MAXN; ++i) {
        sprod[i] = sprod[i - 1] * prod % mod;
    }

    cin >> l; 
    cin >> s;
    int n = szof(s);

    for (int i = 0; i < n; ++i) {
        prec[i + 1] = (prec[i] * prod + hash(s[i] - 'a' + 1)) % mod;
    }

    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            check1(i);
            check1(n / i);
        }
    }

    for (int i = 1; i <= l; ++i) {
        //cerr << i << endl;
        hash h1 = get_hash(0, i - 1);
        for (int k = 1; k < i && k < n; ++k) {
            check2(0, i - 1, 0, k - 1);
        }
        for (int j = i; j < n; j += i) {
            if (j + i - 1 < n && get_hash(j, j + i - 1) != h1) {
                for (int k = 1; k <= l && k + j - 1 < n; ++k) {
                    check2(0, i - 1, j, j + k - 1);
                }
                break;
            }            
        }
    }

    cout << "3\na\nb\nc\n" << endl;

    if (clock() > CLOCKS_PER_SEC * 2) {
        exit(1);
    }

    return 0;
}