#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007
#define point pair<int, int> 
#define px first
#define py second
#define EPS 1e-9
#define rep(x) for(; (x) > 0; (x)--)
#define loop(i, x) for(int i = 0; i < (x); i++)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

struct node
{
	int bid, id, comp, size, fsize, bonus;
	node* parent;
	vector<node*> edges;
	int* dp;
	
	node()
	{
		bid = id = comp = -1;
		parent = NULL;
	}

	void init()
	{
		fsize = size;
		bonus = 0;
		for (node* o : edges) if (o != parent)
		{
			o->parent = this;
			o->init();
			fsize += o->fsize;
			bonus += o->bonus;
			bonus += o->fsize * size;
		}

	}
};

vector<vector<node*> > components;
int C = 0;

void dfs(node& n, stack<node*>& S, stack<node*>& P, node* from)
{
	if (n.id >= 0)
		return;
	
	n.id = C++;
	S.push(&n);
	P.push(&n);
	
	loop(i, n.edges.size())
	{
		node* o = n.edges[i];
		if (o == from)
			continue;
			
		if (o->id < 0)
			dfs(*o, S, P, &n);
		else if (o->comp < 0)
		{
			while (o->id < P.top()->id)
				P.pop();
		}
	}
	
	if (P.top() == &n)
	{
		int cid = components.size();
		vector<node*> comp;
		node* p;
		do {
			p = S.top();
			S.pop();
			p->comp = cid;
			comp.push_back(p);
		} while (p != &n);
		P.pop();
		components.push_back(comp);
	}
}

int main()
{
	int N, R;
	scanf("%d%d", &N, &R);
	
	node* nodes = new node[N];
	
	loop(i, N)
		nodes[i].bid = i;
	
	rep(R)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		nodes[a].edges.push_back(nodes + b);
		nodes[b].edges.push_back(nodes + a);
	}
	
	stack<node*> S, P;
	dfs(nodes[0], S, P, NULL);
	
	/*
	loop(i, components.size())
	{
		loop(j, components[i].size())
			printf("%d ", components[i][j]->bid);
		printf("\n");
	}*/

	int ans = 0;
	int s = components.size();
	node* reduc = new node[s];
	ji(s)
	{
		int v = reduc[i].size = components[i].size();
		ans += v * (v-1);
	}
	
	loop(i, s)
		reduc[i].bid = i;
	
	loop(i, N)
		loop(j, nodes[i].edges.size()) if (nodes[i].edges[j]->comp != nodes[i].comp)
		{
			//printf("%d %d %d %d\n", i, nodes[i].comp, nodes[i].edges[j]->comp, reduc[nodes[i].comp].edges.size());
			reduc[nodes[i].comp].edges.push_back(reduc + nodes[i].edges[j]->comp);
		}
	

	int tans = 0;
	ji(s)
	{
		reduc[i].parent = NULL;
		reduc[i].init();
		bool dp[2001];
		ji(2001)
			dp[i] = false;
		dp[0] = true;
		int b = 0;
		jj(reduc[i].edges.size())
		{
			node* o = reduc[i].edges[j];
			b += o->bonus;
			for (int i = 2000; i >= 0; i--) if (dp[i])
			{
				dp[i+o->fsize] = true;
			}
		}
		int cs = reduc[i].size;
		jj(2001) if (dp[j])
		{
			tans = max(tans, b + j * (N - j - cs) + (N - cs) * cs);
			//printf("%d %d %d %d\n", i, j, b, j * (N - j - cs) + (N - cs) * cs + b);
		}
	}

	printf("%d\n", ans + tans + N);
}