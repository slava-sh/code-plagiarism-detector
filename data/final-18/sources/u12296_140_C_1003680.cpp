#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <complex>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <stack>
#include <queue>
#include <utility>
#include <typeinfo>
#include <ctime>
using namespace std;

template <typename T> inline void checkmax(T &a, const T& b) { if (a < b) a = b; }
template <typename T> inline void checkmin(T &a, const T& b) { if (a > b) a = b; }
inline int lowbit(int x) { return x & -x; }

unsigned rand32(){
    return (rand() << 16) + rand();
}

int rand(int a, int b){
    return rand32() % (b - a + 1) + a;
}

double drand01(){
    return fabs( rand32() ) / INT_MAX;
}

typedef long long LL;

const double eps = 1e-8;

int dcmp(double x){
    return x < -eps ? -1 : x > eps;
}

bool deq(double x, double y){
    return dcmp(x - y) == 0;
}

bool dleq(double x, double y){
    return dcmp(x - y) <= 0;
}

#define maker_header {\
    freopen("0.in", "w", stdout);\
}

#define std_header {\
    freopen("0.in", "r", stdin);\
    freopen("0.out", "w", stdout);\
}


/** ----------headers above --------------*/

const int maxn = 100000 + 10;

struct node {
    int x;
    int c;
    friend bool operator < (node a, node b){
        return a.c < b.c;
    }
} item[maxn];

int r1[maxn], r2[maxn], r3[maxn];

int main(){
    int n;
    while ( cin >> n ){
        static int a[maxn];
        static int x[maxn];
        static int c[maxn];

        int xcnt = 0;
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            x[ xcnt++ ] = a[i];
            c[i] = 0;
        }
        sort(x, x + xcnt);
        xcnt = unique(x, x + xcnt) - x;

        for (int i = 0; i < n; i++){
            int j = lower_bound(x, x + xcnt, a[i]) - x;
            c[j]++;
        }

        for (int i = 0; i < xcnt; i++){
            item[i].x = x[i];
            item[i].c = c[i];
        }

        int itemcnt = xcnt;

        make_heap(item, item + itemcnt);
        int rcnt = 0;
        while (itemcnt >= 3){
            node n1 = item[0]; pop_heap(item, item + itemcnt--);
            node n2 = item[0]; pop_heap(item, item + itemcnt--);
            node n3 = item[0]; pop_heap(item, item + itemcnt--);
            r1[rcnt] = n1.x;
            r2[rcnt] = n2.x;
            r3[rcnt] = n3.x;
            rcnt++;
            if (--n1.c > 0){
                item[ itemcnt++ ] = n1; push_heap(item, item + itemcnt);
            }
            if (--n2.c > 0){
                item[ itemcnt++ ] = n2; push_heap(item, item + itemcnt);
            }
            if (--n3.c > 0){
                item[ itemcnt++ ] = n3; push_heap(item, item + itemcnt);
            }
        }
        printf("%d\n", rcnt);
        for (int i = 0; i < rcnt; i++){
            int r[3];
            r[0] = r1[i];
            r[1] = r2[i];
            r[2] = r3[i];
            sort(r, r + 3, greater<int>());
            printf("%d %d %d\n", r[0], r[1], r[2]);
        }


    }
}
