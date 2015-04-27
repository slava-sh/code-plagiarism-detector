#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef ll li;
typedef pair<ll,ll> PI;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define REP(i, n) rep (i, n)
#define F first
#define S second
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(),(a).end()
#define FLL(a,b) memset((a),b,sizeof(a))
#define CLR(a) memset((a),0,sizeof(a))
#define FOR(it,a) for(__typeof(a.begin())it=a.begin();it!=a.end();++it)
#define FORR(it,a) for(__typeof(a.rbegin())it=a.rbegin();it!=a.rend();++it)
template<typename T,typename U> ostream& operator<< (ostream& out, const pair<T,U>& val){return out << "(" << val.F << ", " << val.S << ")";}
template<class T> ostream& operator<< (ostream& out, const vector<T>& val){out << "{";rep(i,SZ(val)) out << (i?", ":"") << val[i];return out << "}";}
#define declare(a,it) __typeof(a) it=a
const double EPS = 1e-8;

const int dx[]={1,0,-1,0,1,1,-1,-1,0};
const int dy[]={0,1,0,-1,-1,1,-1,1,0};

#define endl '\n'



string in[500];
int col[500];
ll mod;

ll dp[600][600];
ll rec(int nu2,int nu1){
  if(nu2 == 0 && nu1 == 0) return 1;
  ll& ret = dp[nu2][nu1];
  if(ret != -1) return ret;
  ret = 0;
  if(nu2 > 1) ret += nu2*(nu2-1)/2 % mod * rec(nu2-2,nu1+2) % mod;
  if(nu1 > 1) ret += nu1*(nu1-1)/2 % mod * rec(nu2,nu1-2) % mod;
  if(nu1 && nu2) ret += nu2 * nu1 % mod * rec(nu2-1,nu1) % mod;
  ret %= mod;
  return ret;
}

int main(int argc, char *argv[])
{
  int n,m;
  cin >> n >> m >> mod;
  rep(i,m){
    cin >> in[i];    
    rep(j,n)
      if(in[i][j]-'0')
        ++col[j];
  }

  ll nu2 = count(col,col+n,0);
  ll nu1 = count(col,col+n,1);
  //cout << nu2 << " " << nu1 << endl;
  memset(dp,-1,sizeof(dp));
  cout << rec(nu2,nu1) << endl;
}
