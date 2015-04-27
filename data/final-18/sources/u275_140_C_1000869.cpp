#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stack>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;

template<typename T> int size(T & a) { return (int) a.size(); }
template<typename T> T sqr(T a) {return a * a; }

#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pii pair<int, int>
#define _(a, b) memset((a), (b), sizeof(a))
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define all(a) a.begin(),a.end()


int e[3];
struct pos {
    int a, b, c;
    pos() {}
    pos(int aa, int bb, int cc) {
        e[0] = aa;
        e[1] = bb;
        e[2] = cc;
        sort(e, e + 3);
        reverse(e, e + 3);
        a = e[0];
        b = e[1];
        c = e[2];
    }
};

struct item {
    int cnt, val;
    item(int cnt, int val) {
        this->cnt = cnt;
        this->val = val;
    }
    bool operator <( const item &o) const {
        if (cnt != o.cnt)
            return cnt > o.cnt;
        return val < o.val;
    }
};
int main() {
#ifdef air
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    set<item> q;
    map<int, int> g; 
    REP(i,0,n) {
        int x;
        scanf("%d", &x);
        g[x] ++;    
    }
    for(map<int, int>::iterator it = g.begin();it != g.end(); ++it) {
        q.insert(item(it->second, it->first));
    }
    vector<pos> res;
    while (size(q)) {
        
        item  a = *q.begin();
        q.erase(q.begin());
        if (!size(q))
            break;
        item b = *q.begin();
        q.erase(q.begin());
        if (!size(q))
            break;
        item c = *q.begin();
        q.erase(q.begin());
        a.cnt--;
        b.cnt--;
        c.cnt--;
        res.pb(pos(a.val, b.val, c.val));
        if( a.cnt) q.insert(a);
        if( b.cnt) q.insert(b);
        if( c.cnt) q.insert(c);
    }
    cout << size(res)<<endl;
    REP(i,0,size(res)) {
        cout << res[i].a << " " << res[i].b << " " << res[i].c << endl;
    }
    


#ifdef air
    printf("\n%.3lf\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif

}