#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>
//#include <ext/hash_map>


using namespace std;
using namespace __gnu_cxx;



#define REP(i,n) for(int i = 0; i < int(n); ++i)
#define REPV(i, n) for (int i = (n) - 1; (int)i >= 0; --i)
#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)

#define FE(i,t) for (__typeof((t).begin())i=(t).begin();i!=(t).end();++i)
#define FEV(i,t) for (__typeof((t).rbegin())i=(t).rbegin();i!=(t).rend();++i)

#define two(x) (1LL << (x))
#define ALL(a) (a).begin(), (a).end()


#define pb push_back
#define ST first
#define ND second
#define MP(x,y) make_pair(x, y)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

template<class T> void checkmin(T &a, T b){if (b<a)a=b;}
template<class T> void checkmax(T &a, T b){if (b>a)a=b;}
template<class T> void out(T t[], int n){REP(i, n)cout<<t[i]<<" "; cout<<endl;}
template<class T> void out(vector<T> t, int n=-1){for (int i=0; i<(n==-1?t.size():n); ++i) cout<<t[i]<<" "; cout<<endl;}
inline int count_bit(int n){return (n==0)?0:1+count_bit(n&(n-1));}
inline int low_bit(int n){return (n^n-1)&n;}
inline int ctz(int n){return (n==0?-1:ctz(n>>1)+1);}
int toInt(string s){int a; istringstream(s)>>a; return a;}
string toStr(int a){ostringstream os; os<<a; return os.str();}

priority_queue<pii> q;
vector<int> a;
map<int,int> mp;


int main(){
//    printf("100000\n");
//    REP(i, 50000) printf("%d %d ", i+1, i+1);
//    printf("\n");

    int n; cin>>n;
    vector<int> tb;
    REP(i, n){ int b; cin>>b; tb.pb(b); }
    sort(ALL(tb));
    int z=1;
    FOR(i, 1, n){
        if (tb[i]==tb[i-1]) ++z;
        else{
            if (z==1) a.pb(tb[i-1]);
            else q.push(MP(z,tb[i-1]));
            z=1;
        }
    }
    if (z==1) a.pb(tb[n-1]);
    else q.push(MP(z,tb[n-1]));

    int cnt=0;
    string ans;
    while(1){
        int x[3];
        vector<pii> tmp;

        REP(i, 3){
            if (q.empty()){
                if (a.size()==0) x[i]=-1;
                else{
                    x[i]=a.back();
                    a.pop_back();
                }
            }else{
                pii y=q.top(); q.pop();
                tmp.pb(MP(y.ST-1, y.ND));
                x[i]=y.ND;
            }
        }

        if (x[2]==-1) break;
        sort(x, x+3, greater<int>());
        ans+=toStr(x[0])+" "+toStr(x[1])+" "+toStr(x[2])+"\n";
        ++cnt;
        FE(it, tmp) if (it->ST==1) a.pb(it->ND); else q.push(*it);
    }

    cout<<cnt<<endl;
    cout<<ans<<endl;

    return 0;
}

