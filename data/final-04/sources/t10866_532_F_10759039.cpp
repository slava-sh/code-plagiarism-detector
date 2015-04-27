#include <bits/stdc++.h>
using namespace std;

#ifdef SG
    #include <debug.h>
#else
    #define show(...)
    #define debug(...)
    #define deepen(...)
    #define timer(...)
#endif

#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; --i)
#define forv(i,v) for (auto i = v.begin(); i != v.end(); ++i)
#define forr(i,v) for (auto i = v.end(); i != v.begin() && (--i, 1); )
#define ve vector
#define pa pair
#define tu tuple
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fs first
#define sc second
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef pa<int, int> pii;
typedef pa<int, ll> pil;
typedef pa<ll, int> pli;
typedef pa<ll, ll> pll;
typedef ve<int> vi;

const ld pi = 3.1415926535897932384626433832795l;

template<typename T> inline auto sqr (T x) -> decltype(x * x) {return x * x;}
template<typename T> inline T abs (T x) {return x > T() ? x : -x;}
template<typename T1, typename T2> inline bool umx (T1& a, T2 b) {if (a < b) {a = b; return 1;} return 0;}
template<typename T1, typename T2> inline bool umn (T1& a, T2 b) {if (b < a) {a = b; return 1;} return 0;}

const int N = 200100;

struct Input {
    string s, t;
    int n, m;

    bool read () {
        if (scanf ("%d %d", &n, &m) != 2)
            return 0;
        getline(cin, s);
        getline(cin, s);
        getline(cin, t);
        
        return 1;
    }

    void init (const Input &input) {
        *this = input;
    }
};

struct Data: Input {
    vector <int> ans;
        
    void write () {
        cout << ans.size() << endl;
        forn(i, ans.size()) {
            printf ("%d ", ans[i] + 1); 
        }
        cout <<  endl;

    }
    
    virtual void solve () {}
    
    virtual void clear () {
        *this = Data();
    }
};

const int A = 26;

struct Solution: Data {
    ll p[2][N];
    int prev[N];
    ll obrp[2][N];
    int next[N];

    int fst[A];
    int prev_pos[A];
    ll hash[2][A];
    ll mod[2];
    int lst[A];
    ll tekhash[2][A];
    int kol[A];
    
    ll get_st (ll a, int b, ll mod) {
        ll res = 1;
        forn(i, 30) {
            if (b & (1 << i)) {
                (res *= a) %= mod;
            }   
            (a *= a) %= mod;
        }
        return res;
    }

    vector <int> help[A];

    void solve () {
        p[0][0] = p[1][0] = 1;
        p[1][1] = 1000003;
        p[0][1] = 1000033;
        mod[0] = 1000000007;
        mod[1] = 1000000009;
        for (int i = 2; i < N; ++i) {
            forn(j, 2) {
                p[j][i] = (p[j][i - 1] * p[j][1]) % mod[j];
            }
        }
        obrp[1][0] = obrp[0][0] = 1;
        forn(i, 2)
            for (int j = 1; j < 2; ++j)
                obrp[i][j] = get_st(p[i][j], mod[i] - 2, mod[i]);
        forn(i, 2)
            for (int j = 2; j < N; ++j) {
                obrp[i][j] = (obrp[i][j - 1] * obrp[i][1]) % mod[i];
            }
        debug(obrp[0], obrp[0] + 12);
        debug(obrp[1], obrp[1] + 12);

        /*hash_s[0][0] = hash_s[1][0] = 0;
        forn(i, 2) {
            forn(j, n) {
                hash_s[i][j + 1] = (hash_s[i][j] * p[i][1] + int(s[j]) - 'a') % mod[i];
            }   
        }
        hash_t[0][0] = hash_t[1][0] = 0;
        forn(i, 2) {
            forn(j, m) {
                hash_t[i][j + 1] = (hash[i][j] * p[i][1] + int(s[j]) - 'a') % mod[i];
            }   
        }*/
        
        memset(fst, -1, sizeof(fst));
        memset(prev_pos, -1, sizeof(prev_pos));
        forn(i, 2)
            forn(j, A)
                hash[i][j] = 0;
        forn(i, m) {
            if (fst[t[i] - 'a'] < 0) {
                fst[t[i] - 'a'] = i;
            }
            int idx = t[i] - 'a';
            if (prev_pos[idx] >= 0) {
                forn(j, 2) {
                    (hash[j][idx] *= p[j][1]) %= mod[j];
                    hash[j][idx] += (i - prev_pos[idx]);
                    hash[j][idx] %= mod[j];
                }
            }
            prev_pos[t[i] - 'a'] = i;
        }

        memset(lst, -1, sizeof(lst));
        forn(i, n) {
            prev[i] = lst[int(s[i]) - 'a'];
            lst[int(s[i]) - 'a'] = i;   
        }
        memset(lst, -1, sizeof(lst));
        ford(i, n) {
            next[i] = lst[int(s[i]) - 'a'];
            lst[int(s[i]) - 'a'] = i;   
        } 
        forn(i, 2)
            forn(j, A) {
                tekhash[i][j] = 0;
            }
        memset(lst, -1, sizeof(lst));
        memset(kol, 0, sizeof(kol));
        forn(i, m) {
            int idx = int(s[i]) - 'a';
            if (lst[idx] != -1) {
                forn(j, 2) {
                    (tekhash[j][idx] *= p[j][1]) %= mod[j];
                    (tekhash[j][idx] += i - lst[idx]) %= mod[j];
                }
            }
            lst[idx] = i;
            kol[idx]++;     
        }
        debug(tekhash[0][0]);
        debug(tekhash[1][0]);
    //  memset(kol1, -1, sizeof(kol1));

        for (int i = 0; i + m <= n; ++i) {
            bool ok = 1;
    //      memset(kol1, 0, sizeof(kol1));
            forn(j, A) {
                help[j] = vector<int>();
            }
            forn(j, A) {
                if (fst[j] < 0) {
                    continue;
                }
                int posx = fst[j] + i;
                if (j != int(s[posx]) - 'a') {
                    help[j].pb(int(s[posx]) - 'a');
                    help[int(s[posx]) - 'a'].pb(j);
                }
                
                if (prev[posx] >= i) {
                    ok = 0;
                    break;
                }
                if (mp(tekhash[0][int(s[posx]) - 'a'], tekhash[1][int(s[posx]) - 'a']) != mp(hash[0][j], hash[1][j])) {
                //  debug(mp(tekhash[0][int(s[posx]) - 'a'], tekhash[1][int(s[posx]) - 'a']));
            //      debug(mp(hash[0][j], hash[1][j])); 
                    ok = 0;
                    break;      
                }
            }
            forn(j, A) {
                if ((int)help[j].size() > 2 || ((int)help[j].size() == 2 && help[j][0] != help[j][1])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ans.pb(i);
            }
            
            int idx = int(s[i]) - 'a';
            if (kol[idx] > 1) {
                forn(j, 2) 
                    (tekhash[j][idx] += (mod[j] - p[j][kol[idx] - 2]) * (next[i] - i)) %= mod[j];
                /*debug(i);
                debug(idx);
                debug(kol[idx]);
                debug(next[i]);
                debug();    */        
            }
            debug(tekhash[0][0]);
            debug(tekhash[1][0]);
            kol[idx]--;

            if (i + m < n) {
                idx = int(s[i + m]) - 'a';
                if (lst[idx] > i) {
                    forn(j, 2) {
                        (tekhash[j][idx] *= p[j][1]) %= mod[j];
                        (tekhash[j][idx] += i + m - lst[idx]) %= mod[j];
                    }
                }
                /*debug(i + m);
                debug(idx);
                debug(kol[idx]);
                debug(lst[idx]);
                debug();        */
                lst[idx] = i + m;
                kol[idx]++;     

            }
            debug(tekhash[0][0]);
            debug(tekhash[1][0]);
            
        }
    }
    
    void clear () {
        *this = Solution();
    }
};

Solution sol;

int main () {
    deepen(0);
    cout.setf(ios::showpoint | ios::fixed);
    cout.precision(20);
#ifdef SG
    freopen("f.in", "r", stdin);
//  freopen(".out", "w", stdout);
    while (sol.read()) {
        sol.solve();
        sol.write();
        sol.clear();
    }
#else
    sol.read();
    sol.solve();
    sol.write();
#endif

    return 0;
}
