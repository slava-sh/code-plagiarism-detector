#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <sys/time.h>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstring>
#include <fstream>
#include <set>

#define FOR(i,a,b)  for(__typeof(b) i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define FOREACH(x,c)   for(__typeof(c.begin()) x=c.begin();x != c.end(); x++)
#define ALL(c)      c.begin(),c.end()
#define CLEAR(c)    memset(c,0,sizeof(c))
#define SIZE(c) (int) ((c).size())

#define PB          push_back
#define MP          make_pair
#define X           first
#define Y           second

#define ULL         unsigned long long
#define LL          long long
#define LD          long double
#define II         pair<int, int>
#define DD         pair<double, double>

#define VC	    vector
#define VI          VC<int>
#define VVI         VC<VI>
#define VD          VC<double>
#define VS          VC<string>
#define VII         VC<II>
#define VDD         VC<DD>

#define DB(a)       cerr << #a << ": " << a << endl;

using namespace std;

template<class T> void print(VC < T > v) {cerr << "[";if (SIZE(v) != 0) cerr << v[0]; FOR(i, 1, SIZE(v)) cerr << "," << v[i]; cerr << "]\n";}
template<class T> string i2s(T &x) { ostringstream o; o << x; return o.str(); }
VS split(string &s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < SIZE(s)) all.PB(s.substr(p)); return all;}

int n,m,k,w;

char L[1000][10][11];

#define III tuple<int,int,int>

VC<III> D;
int full;

void readData(){
    scanf("%d %d %d %d", &n, &m, &k, &w);
    REP(l,k)
        REP(x,n)
            scanf("%s",L[l][x]);
}

int dist(int l1, int l2){
    int res = 0;
    REP(x,n) REP(y,m)
        res += (L[l1][x][y] != L[l2][x][y]);
    return w*res;
}

void comp(){
    full = n*m;
    D.reserve(k*(k-1)/2);
    REP(l1,k) REP(l2,k) if (l1 < l2){
        int d = dist(l1,l2);
        if (d < full)
            D.PB(make_tuple(d,l1,l2));
    }
}

VII fu;

void fuInit(int n){
    fu = VII(n,MP(-1,0));
}

int fuFind(int v){
    return ((fu[v].X == -1)?v:(fu[v].X=fuFind(fu[v].X))); 
}

void fuUnion(int r1, int r2){
    if (fu[r1].Y > fu[r2].Y)
        fu[r2].X = r1;
    else if (fu[r1].Y < fu[r2].Y)
        fu[r1].X = r2;
    else{
        fu[r1].X = r2;
        fu[r2].Y++;
    }   
}

VVI sol;

VI visited;
VI stack;

void DFS(){
    visited.resize(k,0);
    REP(v,k) if (!visited[v]){
        visited[v] = 1;
        printf("%d 0\n",v+1);
        stack.PB(v);
        while (!(stack.empty())){
            int u = stack.back();
            stack.pop_back();
            for(auto ngb : sol[u])
                if (!visited[ngb]){
                    visited[ngb] = 1;
                    printf("%d %d\n",ngb+1,u+1);
                    stack.PB(ngb);
                }
        }    
    }
}

void solve(){
    sort(ALL(D));
    fuInit(k);
    sol.resize(k);
    int u,v;
    int cost = 0;
    int cnt = 0;
    for(auto e : D){
        u = get<1>(e); v = get<2>(e);
        //cout << get<0>(e) << " " << u << " " << v << endl;
        int ru=fuFind(u), rv=fuFind(v);
        if (ru != rv){
            fuUnion(ru,rv);
            cost += get<0>(e);
            cnt++;
            sol[u].PB(v);
            sol[v].PB(u);
        }
    }
    cost += full*(k-cnt);
    printf("%d\n",cost);
    DFS();
}

int main(int argc, char *argv[]){
    readData();
    comp();
    solve();
    return 0;
}
