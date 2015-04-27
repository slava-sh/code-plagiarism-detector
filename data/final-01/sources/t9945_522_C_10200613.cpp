#pragma comment(linker, "/STACK:66777216")
#define _CRT_SECURE_NO_WARNINGS
//#include <bits/stdc++.h>
//#include <unordered_set>
//#include <unordered_map>
#include <functional>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <ctime>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
//#include <decimal>
//#include <boost/multiprecision/mpfr.hpp>

#define forn(i,n) for(int i = 0; i < (int)(n); ++ i)
#define for1(i,n) for(int i = 1; i <= (int)(n); ++ i)
#define fore(i,a,b) for(int i = (int)(a); i <= (int)(b); ++ i)
#define ford(i,n) for(int i = (int)(n)-1; i >= 0; -- i)
#define ford1(i,n) for(int i = (int)(n); i >= 1; -- i)
#define fored(i,a,b) for(int i = (int)(b); i >= (int)(a);--i)
#define mp make_pair 
#define pb push_back
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORE(it,c) for(__typeof(c).begin() it = (c).begin(); it!=(c).end(); ++it)
//#define fi first
//#define se second

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
//typedef unsigned int UI;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<pii> vpi;
typedef vector<ld> vd;
typedef pair<ld,ld> pdd;
typedef vector<pdd> vpd;

int m, k;
const int N = 100000+5;
int a[ N ], b[ N ], r[ N ];
int last[ N ];
int first;
int qa;
int res[ N ];
void solve() {
    int T = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &m, &k);
        a[0] = 0;
        for1(i,k)
            scanf("%d", &a[i]);
        forn(i,m-1)
            scanf("%d%d", &b[i],&r[i]);
        int q = 0;
        int first = -1;
        for1(i,k)
            last[i] = -1;
        forn(i,m-1){
            last[ b[i] ] = i;
            if(r[i]){
                if(!q){
                    if(first==-1){
                        first = i;
                        qa = -a[0];
                    }
                }
            }
            --a[ b[i] ];
            if(b[i] && a[ b[i] ]==0)
                    ++ q;
        }
        //first, qa
        for1(i,k)res[i] = 0;

        int v = -1;
        for1(i,k){
            if(last[i] < first && qa >= a[ i ]){
                res[i] = 1;
                if(v==-1 || v > a[i])
                    v = a[i];
            }
        }
        if(v==-1)v = 0;
        qa = -a[0];
        qa-=v;
        for1(i,k)
            if(a[i] <= qa)
                res[i] = 1;
        for1(i,k){
            if(res[i]==0)
                printf("N");
            else
                printf("Y");
            
        }
        printf("\n");
    }
}

void testgen(){
    FILE * file_ = fopen("input.txt", "w");
    srand(time(NULL));
    int Q = 10000;
    fprintf(file_, "%d\n", Q);
    forn(i,Q){
        fprintf(file_, "%d %d 1\n", rand()%(N-1)+1, rand()%(N-1)+1/*, rand()%(N-1)+1*/);    
    }
    fclose(file_);
}

int main() {
#ifdef LOCAL
//  testgen();
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#else
#define task "heap"
    //  freopen(task".in", "r", stdin);
    //  freopen(task".out", "w", stdout);
#endif

    cout<<fixed;
    cout.precision(15);
    cerr<<fixed;
    cerr.precision(12);
    solve();

#ifdef LOCAL
    cerr<<"Execution time = "<<clock()/1000.0<<"ms\n";
#endif
    return 0;
}