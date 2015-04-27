#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cctype>
#include <complex>
#include <string>
#include <sstream>
#include <fstream>
#include <cassert>
using namespace std;

//common

typedef int  i32;
typedef long long i64,ll;
typedef long double ld;

#define BR "\n"
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,l,r) for(int i=(int)l;i<(int)(r);++i)
#define EACH(i,c) for(auto i=(c).begin(); i!=(c).end(); ++i)
#define IN(l,v,r) ((l)<=(v) && (v)<(r))

//config
//#define NDEBUG
//#define INF 1<<30
//#define EPS 1e-8
//const ll MOD =100000007;

//debug
#ifdef NDEBUG
#define DUMP(x)
#define DUMPLN(x)
#define DEBUG(x)
#define DEBUGLN(x)
#define LINE()
#define LINELN()
#define CHECK(exp,act)
#define STOP(e)
#else
#define DUMP(x)  cerr << #x << " = " << (x)
#define DUMPLN(x)  DUMP(x) <<endl
#define DEBUG(x) DUMP(x) << LINE() << " " << __FILE__
#define DEBUGLN(x) DEBUG(x)<<endl
#define LINE()    cerr<< " (L" << __LINE__ << ")"
#define LINELN()    LINE()<<endl
#define CHECK(exp,act)  if(exp!=act){DUMPLN(exp);DEBUGLN(act);}
#define STOP(e)  CHECK(e,true);if(!(e)) exit(1);
#endif

template<class T> inline string toString(const vector<T>& x) {
	stringstream ss;
	REP(i,x.size()){
		if(i!=0)ss<<" ";
		ss<< x[i];
	}
	return ss.str();
}

template<class T> inline string toString(const vector<vector<T> >& map) {
	stringstream ss;
	REP(i,map.size()){
		if(i!=0)ss<<BR;
		ss<< toString(map[i]);
	}
	return ss.str();
}
template<class K,class V>  string toString(map<K,V>& x) {
	string res;stringstream ss;
	for(auto& p:x)ss<< p.first<<":" << p.second<<" ";
	return ss.str();
}

string BITtoString(int bit){
    stringstream ss;
    while(bit!=0){ss<<(bit%2);bit/=2;}
    string res=ss.str();reverse(ALL(res));
    return res;
}

template<typename T,typename V> inline T pmod(T v,V MOD){
	return (v%MOD+MOD)%MOD;
}
char tmp[1000];
#define nextInt(n) scanf("%d",&n)
#define nextLong(n) scanf("%I64d",&n)
#define nextDouble(n) scanf("%lf",&n)
#define nextChar(n) scanf("%c",&n)
#define nextString(n) scanf("%s",tmp);n=tmp

ll MOD=1000000007LL;

namespace EGraph{
	typedef int Cost;Cost CINF=1<<28;
	struct Edge{
		int from,to;Cost cost;
		Edge(int from,int to,Cost cost)
		: from(from),to(to),cost(cost) {};
		bool operator<(Edge r) const{
			return cost<r.cost;
		}
		bool operator>(Edge r) const{
			return cost>r.cost;
		}
	};
	typedef vector<vector<Edge> >  Graph;
}
using namespace EGraph;

struct UnionFind{
    vector<int> par; // 親
    vector<int> rank; // 木の深さ
    vector<int> ss;//xの属する集合のサイズ
    int size;//集合の個数
    UnionFind(int n){
        REP(i,n) par.push_back(i);
        rank = vector<int>(n);
        ss=vector<int>(n,1);
        size=n;
    }
    int root(int x){
        if(par[x] == x)return x;
        return par[x] = root(par[x]);
    }
    bool same(int x,int y){
        return root(x) == root(y);
    }
    void unite(int x,int y){
        x = root(x);y = root(y);
        if(x==y)return;
        if(rank[x] < rank[y]){
            par[x] = y;
            ss[y]+=ss[x];
        }else{
            par[y] = x;
            ss[x]+=ss[y];
        }
        if(rank[x] == rank[y]) rank[x]++;
        size--;
    }
    int getS(int x){
        return ss[root(x)];
    }
};

namespace SpanningTree{
	using namespace EGraph;

	//O(E*log(V))
	// verified by ACAC002 B
	// http://judge.u-aizu.ac.jp/onlinejudge/creview.jsp?rid=899132&cid=ACAC002
	vector<Edge> kruskal(Graph g){
		const int V=g.size();
		UnionFind uf=UnionFind(V);
		priority_queue<Edge,vector<Edge>,greater<Edge>> que;
		REP(u,V)for(Edge e:g[u])
			que.push(e);
		vector<Edge> res;
		while(!que.empty()){
			Edge e=que.top();que.pop();
			if(!uf.same(e.from,e.to)){
				uf.unite(e.from,e.to);
				res.push_back(e);
			}
		}
		return res;
	}
}

using namespace SpanningTree;

class Main{
public:
	vector<int> vs;
	vector<bool> exs;

	void run(){
	//	ifstream cin("in");
	//	ofstream cout( "out" );
		int n,m,k,w;cin >> n >> m >> k >> w;
		vector<vector<string>> board(k+1,vector<string>(n));
		REP(y,n)REP(x,m)board[0][y]+='.';
		REP(_k,k){
			REP(y,n)cin >> board[_k+1][y];
		}

		vector<vector<int>> ds(k+1,vector<int>(k+1));
		REP(k1,k+1)REP(k2,k+1){
			REP(y,n)REP(x,m)if(board[k1][y][x]!=board[k2][y][x])ds[k1][k2]++;
		}

		Graph g(k+1);
		for(int k1=1;k1<=k;k1++)for(int k2=1;k2<=k;k2++)
				g[k1].push_back(Edge(k1,k2,ds[k1][k2]*w));
		for(int k1=1;k1<=k;k1++){
				g[0].push_back(Edge(0,k1,n*m));			
				g[k1].push_back(Edge(k1,0,n*m));			
		}

		vector<Edge> res=kruskal(g);
		ll sum=0;
		REP(i,res.size())sum+=res[i].cost;

		Graph g2(k+1);
		REP(i,res.size()){
			g2[res[i].from].push_back(res[i]);
			g2[res[i].to].push_back(Edge(res[i].to,res[i].from,res[i].cost));
		}
		ans=vector<pair<int,int>>();
		dfs(g2,-1,0);
		cout << sum<<endl;
		REP(i,ans.size()){
			cout << ans[i].first <<" "<<ans[i].second<<endl;
		}
	}
	vector<pair<int,int>> ans;

	void dfs(Graph& g,int p,int v){
		EACH(e,g[v])if(e->to!=p){
			ans.push_back(make_pair(e->to,e->from));
			dfs(g,v,e->to);
		}
	}
};
 int main(){
	cout <<fixed<<setprecision(15);	
	ios::sync_with_stdio(false);
 	Main().run();
 	return 0;
 }