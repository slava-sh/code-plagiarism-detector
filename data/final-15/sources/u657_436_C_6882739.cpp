/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/

#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;
typedef pair<int,pii>  piii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
    return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
    o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
    ostream &out; bool first;
    void start() { first = true; }
    debugger(ostream& out):out(out) {start();}
    void nl() { out << endl; start(); }
    // Taken from rudradevbasak
    template<class T> debugger& operator,(T& v) {
        if(first) first = false; else out << ", ";
        out << v; return *this;
    }
    template<class T> debugger& operator,(pair<T*,int> arr) { //array print
        out << "{";
            FOR(i, arr.second) { out << arr.first[i] << ", "; }
        out << "}";
        return *this;
    }
} dbg(cerr);
string str[1111][11];
int sps[2222];
int cost[1111][1111];
int vis[2222];
int K;
int n,m,x,a,b,k,w;
int spSet2(){
    int x,i,j,c;;
    for(i=1;i<=K;i++){
        sps[i]= 1000000000;
        vis[i]=0;
    }

    sps[1]=0;
    int ret=n*m;
    vector<pii>ans;
    priority_queue<piii>pq;
    pq.push(piii(-sps[1],pii(1,0)));    //pair(distance,node)

    while(!pq.empty()){
        piii now = pq.top();
        pq.pop();


        int x = now.second.px;

        if(vis[x])continue;
        vis[x]=1;

        if(-now.px>n*m){
                ret+=n*m;ans.pb(pii(x,0));
        }
        else {
            ret+=-now.px;ans.pb(pii(x,now.second.py));
        }

       // cout<<x<<" "<<now.second.py<<endl;
    for(j=1;j<=K;j++){
            i = j;
            c = cost[x][i];
            if(vis[i])continue;
            if(c < sps[i]){
                sps[i] = c;
                pq.push(piii(-sps[i],pii(i,x)));
            }

        }
    }
    cout<<ret<<endl;
    FOR(i,sz(ans)){
        cout<<ans[i].px<<" "<<ans[i].py<<endl;
    }
}

int main()
{

    cin>>n>>m>>K>>w;
    FOR1(_,K){
        FOR(i,n){
            cin>>str[_][i];
        }
    }
    priority_queue<piii>pq;
    FOR1(i,K){
        FOR1(j,i-1){
            FOR(k,n){
                FOR(l,m){
                            cost[i][j]=cost[j][i]=cost[j][i]+(str[i][k][l]!=str[j][k][l])*w;

                }
            }

        }
    }
    FOR1(i,K){
       // FOR1(j,K)cout<<cost[i][j]<<" ";
  //  cout<<endl;
    }
    spSet2();



    return 0;
}
