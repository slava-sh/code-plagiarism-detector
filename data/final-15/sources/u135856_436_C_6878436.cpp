///////////////////////////////
// Template By: Agus Sentosa //
//       16 - 5 - 2014       //
///////////////////////////////
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <utility>

//I/O
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <istream>
#include <ostream>

//Data Type
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <bitset>

//Data Type
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define LL long long
#define ULL unsigned long long

//Data Type Properties
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define popb pop_back

//Macro
#define all(v) (v).begin(),(v).end()
#define sortv(v) sort(all(v))
#define num(x) ((x)-'0')
#define ch(x) ((x)+'0')
#define bit_count __builtin_popcount
#define bit_countll __builtin_popcountll

//Output
#define endl '\n'
#define debug puts("OK");

//Input
#define in scanf
#define out printf

#define gw using
#define memang_ganteng namespace std;

gw memang_ganteng

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define g getchar_unlocked
template<class T>
void io(T &res){
    register char c;
    while(c=g()){ if(c!=' ' && c!='\n')break; }
    res=num(c);
    while(c=g()){ if(c==' ' || c=='\n')return; res=(res<<3)+(res<<1)+(num(c)); }
}

template<class T>
string inttostr(T x){
    string res="";
    while(x){
        char t=ch(x%10); x/=10; res=t+res;
    }
    return res;
}

template<class T>
T strtoint(string x){
    T res=0;
    for(int i=0;i<x.size();i++){
        res=(res<<3)+(res<<1)+num(x[i]);
    }
    return res;
}
void open(string a){
    freopen((a+".in").c_str(),"r",stdin);
    freopen((a+".out").c_str(),"w",stdout);
}
void close(){
    fclose(stdin);
    fclose(stdout);
}

//Constant
#define INF (INT_MAX-2)
#define LINF (LONG_LONG_MAX-2)
#define INV INT_MIN
#define LINV LONG_LONG_MIN
#define EPS 1e-9

///////////////////////////////
//      End of Template      //
///////////////////////////////
int y,x,k,w;
char lvl[1005][11][11];

int par[1005];

int dist(int a,int b){
    int res=0;

    for(int i=0;i<y;i++)
        for(int j=0;j<x;j++)
            res+=(lvl[a][i][j]!=lvl[b][i][j]);

    return res*w;
}

int getpar(int i){
    if(par[i]==i)return i;
    return par[i]=getpar(par[i]);
}

vector<int> V[1005];

void DFS(int cur,int bef){
    if(bef!=-1)cout << cur << ' ' << bef << endl;
    for(int i=0;i<V[cur].size();i++){
        if(V[cur][i]!=bef)
            DFS(V[cur][i],cur);
    }
}

int main(){
    ios::sync_with_stdio(0);
    
    cin >> y >> x >> k >> w;
    
    for(int i=1;i<=k;i++){

        for(int j=0;j<y;j++)
            for(int k=0;k<x;k++)
                cin >> lvl[i][j][k];

    }

    vector< pair<int,pii> > E;
    int kons=y*x;
    for(int i=1;i<=k;i++)
        E.pb(mp(kons,mp(0,i)));

    for(int i=1;i<=k;i++)
        for(int j=i+1;j<=k;j++)
            E.pb(mp(dist(i,j),mp(i,j)));

    sortv(E);
    int res=0;
    for(int i=0;i<=k;i++)par[i]=i;

    for(int i=0;i<E.size();i++){
        int D=E[i].f;
        int a=E[i].s.f;
        int b=E[i].s.s;

        if(getpar(a)!=getpar(b)){
            res+=D;
            par[getpar(a)]=getpar(b);
            V[a].pb(b);
            V[b].pb(a);
        }
    }

    cout << res << endl;
    DFS(0,-1);

    return 0;
}