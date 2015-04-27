#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <functional>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <climits>
#include <cassert>
#include <memory>
#include <time.h>
using namespace std;
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
const double EPS = 1e-9;
const double PI  = acos(-1.0);

typedef vector<vs> vvs;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

#define EACH(t,i,c) for(t::const_iterator i=(c).begin();i!=(c).end();i++)
pair<Weight, Edges> minimumSpanningTree(const Graph &g, int r = 0) {
  int n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  Q.push( Edge(-1, r, 0) );
  while (!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (visited[e.dst]) continue;
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    EACH(Edges,f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
  }
  return pair<Weight, Edges>(total, T);
}

//void output(int cur,Edges &edges,vvi &raw,vi &used){
//	used[cur]=true;
//	REP(i,edges.size()){
//		if(edges[i].src==cur){
//			if(raw[edges[i].src][edges[i].dst]){
//				cout<<edges[i].dst+1<<" "<<0<<endl;
//			}else{
//				cout<<edges[i].dst+1<<" "<<edges[i].src+1<<endl;
//			}
//		}
//	}
//	REP(i,edges.size()){
//		output(i,edges,raw,used);
//	}
//}

int main(){
	int n,m,k,w;
	cin>>n>>m>>k>>w;
	vvs levels(k,vs(n));
	REP(level,k){
		REP(i,n){
			cin>>levels[level][i];
		}
	}

	Graph g(k);
	vvi raw(k,vi(k));
	REP(i,k){
		REP(j,k){
			int diff=0;
			REP(y,n){
				REP(x,m){
					if(levels[i][y][x]!=levels[j][y][x]){
						diff+=w;
					}
				}
			}
			if(diff>n*m){
				diff=n*m;
				raw[i][j]=true;
			}
			g[i].push_back(Edge(i,j,diff));
		}
	}


	pair<Weight,Edges> tree= minimumSpanningTree(g);
	cout<<tree.first+n*m<<endl;

	Edges &edges=tree.second;
	cout<<edges[0].dst+1<<" "<<0<<endl;
	vi used(k);

	FOR(i,1,edges.size()){
		if(raw[edges[i].src][edges[i].dst]){
			cout<<edges[i].dst+1<<" "<<0<<endl;
		}else{
			cout<<edges[i].dst+1<<" "<<edges[i].src+1<<endl;
		}
	}
	//output(0,edges,raw,used);
}