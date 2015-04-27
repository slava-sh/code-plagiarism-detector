#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
 
 
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x)  cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;
 
 
 
#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back
 
using namespace std;
static const double EPS = 1e-5;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<string> vs;

template<typename T> std::ostream& operator<<(std::ostream& os, const vector<T>& z){
    os << "[ ";
    REP(i,z.size())os << z[i] << ", " ;
    return ( os << "]" << endl);
}
 
template<typename T> std::ostream& operator<<(std::ostream& os, const set<T>& z){
    os << "set( "; 
    EACH(p,z)os << (*p) << ", " ;
    return ( os << ")" << endl);
}
 
template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const map<T,U>& z){
    os << "{ "; 
    EACH(p,z)os << (p->first) << ": " << (p->second) << ", " ;
    return ( os << "}" << endl);
}
 
template<typename T,typename U> std::ostream& operator<<(std::ostream& os, const pair<T,U>& z){
    return ( os << "(" << z.first << ", " << z.second << ",)" );
}

int n;
map<int,int> r;
vector<pii> z;

void prin(vvi &ret,int r1, int r2, int r3){
    vi rr;
    rr.pb(r1);
    rr.pb(r2);
    rr.pb(r3);
    sort(rr.begin(), rr.end());
    ret.pb(rr);
}

int main(){
    cin >> n;
    REP(i,n){
        int m;
        cin >> m;
        r[m]+=1;
    }
    
    priority_queue<pii, vector<pii> > que;
    
    EACH(pp,r){
      z.pb(pii(pp->second, pp->first));
        que.push(pii(pp->second, pp->first));
    }
    /*
    sort(z.begin(), z.end(), greater<pii>());
    vi zn, zr;
    REP(i,z.size()){
        zn.pb(z[i].first);
        zr.pb(z[i].second);
    }
    debug(z);*/
    vvi ret;
    int pn[3];
    int pr[3];
    while(que.size()>=3){
        //debug(que.size());
        REP(i,3){
            pn[i]=que.top().first;
            pr[i]=que.top().second;
            que.pop();
        }
        REP(i,3){
            pn[i]--;
            if(pn[i]>0){
                que.push(pii(pn[i], pr[i]));
            }
        }
        prin(ret, pr[0], pr[1], pr[2]);
    }
    cout << ret.size()<< endl;
    REP(i,ret.size()){
        cout << ret[i][2] << " " << ret[i][1] << " " << ret[i][0] << endl;
    }
  return 0;
}
