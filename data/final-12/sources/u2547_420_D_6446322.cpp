#undef NDEBUG
#ifdef SU2_PROJ
//#define _GLIBCXX_DEBUG
#endif

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }
inline ostream& operator<< (ostream& out, const pt& p) { return out << '(' << p.x << ", " << p.y << ')'; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 1000 * 1000 + 13;

struct node
{
    node *l, *r;
    int value, cnt, prior;
    
    node(int val)
    {
        l = r = NULL;
        value = val;
        cnt = 1;
        prior = (rand() << 15) ^ rand();
    }
};

typedef node* tree;

tree root = NULL;

inline int cnt(tree t)
{
    if (!t) return 0;
    return t->cnt;
}

inline void push(tree t)
{
    if (!t) return; 
    t->cnt = cnt(t->l) + 1 + cnt(t->r);
}

tree merge(tree t1, tree t2)
{
    push(t1);
    push(t2);
    
    if (!t1) return t2;
    if (!t2) return t1;
    
    tree res;
    
    if (t1->prior > t2->prior)
    {
        t1->r = merge(t1->r, t2);
        res = t1;
    }
    else
    {
        t2->l = merge(t1, t2->l);
        res = t2;
    }
    
    push(res);  
    return res;
}

void split(tree t, tree& t1, tree& t2, int k)
{
    push(t);
    if (!t)
    {
        t1 = t2 = NULL;
        return;
    }
    
    int lfsize = cnt(t->l);
    
    if (k >= lfsize)
    {
        split(t->r, t->r, t2, k - lfsize - 1);
        t1 = t;
    }
    else
    {
        split(t->l, t1, t->l, k);
        t2 = t;
    }
    
    push(t1);
    push(t2);
}

inline void insert(int pos, int val)
{
    tree next = new node(val);
    
    if (!root)
    {
        root = next;
        return;
    }
    
    tree t1, t2;
    split(root, t1, t2, pos);
    
    root = merge(t1, next);
    root = merge(root, t2);
}

inline int modify(int pos)
{
    tree t1, t2, t3, t4;
    
    split(root, t1, t2, pos);
    split(t1, t3, t4, pos - 1);
    
    int ans = t4->value;
    
    root = merge(t4, t3);
    root = merge(root, t2);
    
    return ans;
}

int n, m;

inline bool read()
{   
    if (scanf("%d%d", &n, &m) != 2) return false;   
    return true;
}

int ans[N];
int used[N];

inline void solve()
{   
    forn(i, n) insert(i, i);
    
    memset(ans, -1, sizeof ans);
    
    //forn(i, n) cerr << find(i) << endl;
    
    forn(i, m)
    {
        int x, y;
        assert(scanf("%d%d", &x, &y) == 2); x--, y--;
        //x = 0, y = 0;
        
        int pos = modify(y);
        
        if (ans[pos] == x || ans[pos] == -1)
            ans[pos] = x;
        else
        {
            puts("-1");
            return;         
        }
    }
    
    forn(i, n)
    {
        if (ans[i] == -1) continue;
        
        if (used[ans[i]])
        {
            puts("-1");
            return;
        }
        
        used[ans[i]] = true;
    }
    
    int p = 0;
    
    forn(i, n)
    {
        if (ans[i] != -1) continue;
        
        while (p < n && used[p]) p++;   
        
        ans[i] = p++;
    }
    
    forn(i, n) printf("%d ", ans[i] + 1);
    puts("");
}

int main()
{
#ifdef SU2_PROJ
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;
    
    assert(read());
    solve();
    
#ifdef SU2_PROJ
    cerr << "== TIME: " << clock() << " ==" << endl;
#endif

    return 0;
}
