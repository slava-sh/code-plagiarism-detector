#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
#define valid(y,x,h,w) (0<=y&&y<h&&0<=x&&x<w)
#define tpl(...) make_tuple(__VA_ARGS__)
const int INF = 1<<29;
const double EPS = 1e-8;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int,int> pii;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class T>ostream&operator<<(ostream &o,const vector<T>&t){o<<'[';FOR(i,t){if(i!=t.begin())o<<',';o<<*i;}return o<<']';}
template<class S,class T>ostream&operator<<(ostream &o,const pair<S,T>&t){return o<<'('<<t.first<<','<<t.second<<')';}
template<int N,class Tp>void out(ostream&,const Tp&){}
template<int N,class Tp,class,class ...Ts>void out(ostream &o,const Tp&t){if(N)o<<',';o<<get<N>(t);out<N+1,Tp,Ts...>(o,t);}
template<class ...Ts>ostream&operator<<(ostream&o,const tuple<Ts...>&t){o<<'(';out<0,tuple<Ts...>,Ts...>(o,t);return o<<')';}
template<class T>void output(T *a,int n){REP(i,n){if(i)cout<<',';cout<<a[i];}cout<<endl;}
template<class T>void output(T *a,int n,int m){REP(i,n)output(a[i],m);}
template<class T>void output(T t){if(t<0)t=-t,putchar('-');static int c[20];int k=0;
while(t)c[k++]=t%10,t/=10;if(!k)c[k++]=0;while(k)putchar(c[--k]^48);}
template<class S,class ...T>void output(S a,T...t){output(a);putchar(' ');output(t...);}
template<class T>bool input(T &t){t=0;int n=0,c;while(~(c=getchar())&&!isdigit(c)&&c!='-');if(!~c)return 0;
if(c=='-')n=1;else t=c^48;while(isdigit(c=getchar()))t=10*t+c-'0';t=n?-t:t;return 1;}
template<class S,class ...T>bool input(S&a,T&...t){input(a);return input(t...);}

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight :
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


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
    FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
  }
  return pair<Weight, Edges>(total, T);
}
char ba[1000][10][10];

int main() {
  int n,m,k,w;
  while(input(n,m,k,w)) {
    REP(i,k)REP(j,n)REP(l,m)scanf(" %c ", &ba[i][j][l]);
    Graph g(k+1);
    REP(i,k)REP(j,i){
      int c = 0;
      REP(y,n)REP(x,m) c+=ba[i][y][x]!=ba[j][y][x];
      g[i].push_back(Edge(i,j,c*w));
      g[j].push_back(Edge(j,i,c*w));
    }
    REP(i,k) g[k].push_back(Edge(k,i,n*m));
    pair<Weight,Edges> res = minimumSpanningTree(g,k);
    cout << res.first << endl;
    FOR(it,res.second) {
      if (it->dst == k) continue;
      if (it->src == k) {
        printf("%d 0\n", it->dst+1);
      } else {
        printf("%d %d\n", it->dst+1, it->src+1);
      }
    }
  }
}
