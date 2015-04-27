#include<bits/stdc++.h>
using namespace std;

#define fo3(i,a,b) for(int i=(int)(a); i<(int)(b); ++i)
#define of3(i,a,b) for(int i=(int)(b)-1; i>=(int)(a); --i)

#define fo2(i,b) fo3(i,0,b)
#define of2(i,b) of3(i,0,b)

#define _CAT(a,b) a##b
#define CAT(a,b) _CAT(a,b)
#define _5TH(a,b,c,d,e,...) e
#define VA_SEL(f, ...) CAT(f,_5TH(__VA_ARGS__,4,3,2,1))(__VA_ARGS__)

#define fo(...) VA_SEL(fo,__VA_ARGS__)
#define of(...) VA_SEL(of,__VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define pub push_back
#define pob pop_back
#define mp make_pair
#define fi first
#define se second

#define be begin()
#define en end()

#define fore(it,c) for(__typeof((c).be) it=(c).be; it!=(c).en; ++it)
#define var(a,v) __typeof(v)a=v

#define ii (int)
#define sz size()

struct OO{
	OO&operator<(int a){printf("%d",a);return *this;}
	OO&operator<(ll a){printf("%lld",a);return *this;}
	OO&operator<(double a){printf("%.15f",a);return *this;}
	OO&operator<(char a){putchar(a);return *this;}
	OO&operator<(const char* a){fputs(a,stdout);return *this;}
}O;

struct II{
	II&operator>(int& a){scanf("%d",&a);return *this;}
	II&operator>(ll& a){scanf("%lld",&a);return *this;}
	II&operator>(double& a){scanf("%lf",&a);return *this;}
	II&operator>(char& a){a=getchar();return *this;}
} I;

#ifdef DEBUG
OO E;
#else
struct EE{
	EE&operator<(int a){return *this;}
	EE&operator<(ll a){return *this;}
	EE&operator<(double a){return *this;}
	EE&operator<(char a){return *this;}
	EE&operator<(const char* a){return *this;}
}E;
#endif

#define N '\n'

////////////////////////////////// UNION FIND //////////////////////////////////
class UnionFind
{
public:
	UnionFind(size_t univSize) : parents(univSize), ranks(univSize,0)
	{
		for(size_t i=0; i<univSize; ++i) parents[i] = i;
	}
	size_t find(size_t x)
	{
		size_t root = x;
		while(parents[root] != root) root = parents[root];
		while(x != root)
		{
			size_t& curr = parents[x];
			x = parents[x];
			curr = root;
		}
		return root;
	}
	bool makeUnion(size_t a, size_t b) // false if union already made
	{
		a = find(a);
		b = find(b);
		if(a==b)return false;
		if(ranks[a] < ranks[b]) parents[a] = b, ++ranks[b];
		else parents[b] = a, ++ranks[a];
		return true;
	}
private:
	std::vector<size_t> parents;
	std::vector<size_t> ranks;
};
////////////////////////////////////////////////////////////////////////////////


inline char gc(){
	char c = getchar();
	while(!isgraph(c))c=getchar();
	return c;
}

int n,m,K,W;

struct plansza{
	ull data[53][2];
} plansze[1009];

//char temp[11][11];

inline void setbit(ull data[2], int i, int j){
	int pos = i*10+j;
	if(pos<64)data[0] |= (1LL << pos);
	else data[1] |= (1LL << (pos-64));
}

inline int getdiff(int a, int b){
	int total = 0;
	fo(i,26*2+1){
		ll v = (plansze[a].data[i][0] ^ plansze[b].data[i][0]);
		total += __builtin_popcountll(v);
		v = (plansze[a].data[i][1] ^ plansze[b].data[i][1]);
		total += __builtin_popcountll(v);
	}
	return total>>1;
}

//int dist[1009][1009];

struct Ed{
	Ed(int a, int b, int c) : fr(a), to(b), w(c) {}
	int fr;
	int to;
	int w;
	
	bool operator<(const Ed& o)const{
		return w<o.w;
	}
};

vector<Ed> edges;

vector<pii> dests[1009];

UnionFind uf(1009);

//vector<Ed> wv;

bool vis[1009];

void dfs(int v){
	if(vis[v])return;
	vis[v] = true;
	
	fo(i,dests[v].sz){
		int vdest = dests[v][i].fi;
		if(!vis[vdest]){
			if(dests[v][i].se == -1) O<vdest+1<" "<0<N;
			else O<vdest+1<" "<v+1<N;
			dfs(vdest);
		}
	}
}

int main(){
	I>n>m>K>W;
	
	int simplecost = n*m;
	
	fo(k,K){
		fo(i,n)fo(j,m){
			char c = gc();
			//if(c!='.'){
			int ic = (c>='a' && c<='z') ? c-'a' : 26+c-'A';
			if(c=='.') ic = 26*2;
				setbit(plansze[k].data[ic],i,j);
			//}
		}
	}
	
	fo(i,K)fo(j,i+1,K){
		int diff = getdiff(i,j);
		//dist[i][j] = diff;
		edges.pub(Ed(i,j,diff));
		E<"dist["<i<"]["<j<"] == "<diff<N;
	}
	
	sort(edges.be, edges.en);
	
	ll wynik = n*m;
	
	fo(i,(int)edges.sz){
		int cost = edges[i].w;
		cost *= W;
		if(cost > simplecost){
			cost = -1;
			//wynik += simplecost;
		}
		//else wynik += cost;
		
		int a = edges[i].fr;
		int b = edges[i].to;
		int aa = uf.find(a);
		int bb = uf.find(b);
		if(aa==bb)continue;
		
		if(cost==-1) wynik += simplecost;
		else wynik += cost;
		
		uf.makeUnion(aa,bb);
		
		//wv.pub(edges[i]);
		//wv.back().w = cost;
		
		dests[a].pub(mp(b,cost));
		dests[b].pub(mp(a,cost));
	}
	
	O<wynik<N;
	O<1<" "<0<N;
	dfs(0);
	
	return 0;
}




