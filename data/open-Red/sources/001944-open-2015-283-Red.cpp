#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef long double ld;
typedef std::pair < int , int > pair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits < double > ::infinity();
const ld LDINF = std::numeric_limits < ld > ::infinity();
const double EPS = 1e-9;

const int N = 100179;
const ll MOD = 1000000007;

int n, m, d;
struct Vertex
{
	std::vector < int > e, et, evc, ev;

	struct Node
	{
		int cl, cr, l, r;
		int num;
	};
	std::vector < Node > nv;

	int build(int cl, int cr);
} v[N];

int n1;
int v2v[N*10];
std::vector < int > e1[N*10], ec1[N*10];

int Vertex::build(int cl, int cr)
{
	if (e.size() == 0)
		return -1;
	nv.push_back(Node());
	if (cl == cr)
	{
		nv.back().cl = nv.back().cr = cl;
		nv.back().l = nv.back().r = -1;
		nv.back().num = ev[cl];
		return nv.size() - 1;
	}

	int ret = nv.size() - 1;
	nv[ret].cl = cl;
	nv[ret].cr = cr;
	nv[ret].num = n1++;
	int nl = build(cl, (cl + cr) >> 1);
	int nr = build(((cl + cr) >> 1) + 1, cr);
	Node & node1 = nv[ret];
	node1.l = nl;
	node1.r = nr;
	e1[node1.num].push_back(nv[node1.l].num);
	e1[node1.num].push_back(nv[node1.r].num);
	ec1[node1.num].push_back(nv[node1.l].l == -1 ? 1 : 0);
	ec1[node1.num].push_back(nv[node1.r].l == -1 ? 1 : 0);

	return ret;
}

void add(int v1, int vs, int l, int r, int c)
{
	int cl = v[vs].nv[c].cl;
	int cr = v[vs].nv[c].cr;
	if (cl > r || cr < l)
		return;
	if (l <= cl && cr <= r)
	{
		e1[v1].push_back(v[vs].nv[c].num);
		ec1[v1].push_back((v[vs].nv[c].l == -1 ? 1 : 0));
		return;
	}
	
	add(v1, vs, l, r, v[vs].nv[c].l);
	add(v1, vs, l, r, v[vs].nv[c].r);
}

int solve(int a, int b)
{
	static int d[N*10];
	std::set < pair > ds;
	memset(d, 0x3f, sizeof(int) * n1);
	if (v[a].nv.size() == 0)
		return -1;
	ds.insert({d[v[a].nv[0].num] = (v[a].nv[0].l == -1 ? 1 : 0), v[a].nv[0].num});
	while (!ds.empty())
	{
		auto it = ds.begin();
		int cv = it->second;
		int cd = it->first;
		if (v2v[cv] == b)
			return cd;
		ds.erase(it);
		for (int i = 0; i < e1[cv].size(); ++i)
		{
			int nv = e1[cv][i];
			int nd = cd + ec1[cv][i];
			if (nd < d[nv])
			{
				ds.erase({d[nv], nv});
				ds.insert({d[nv] = nd, nv});
			}
		}
	}
	return -1;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	
	memset(v2v, -1, sizeof(v2v));

	std::cin >> n >> m >> d;
	for (int i = 0; i < m; ++i)
	{
		int a, b, t;
		std::cin >> a >> b >> t;
		--a;
		--b;
		v[a].e.push_back(b);
		v[a].et.push_back(t);
		v[b].e.push_back(a);
		v[b].et.push_back(t);

		v2v[n1] = a;
		v[a].evc.push_back(n1);
		v[b].ev.push_back(n1++);
		v2v[n1] = b;
		v[b].evc.push_back(n1);
		v[a].ev.push_back(n1++);
	}	

	for (int i = 0; i < n; ++i)
		v[i].build(0, v[i].e.size() - 1);

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < v[i].e.size(); ++j)
		{
			int tl = std::lower_bound(v[i].et.begin(), v[i].et.end(), v[i].et[j] - d) - v[i].et.begin();
			int tr = std::upper_bound(v[i].et.begin(), v[i].et.end(), v[i].et[j] + d) - v[i].et.begin() - 1;
			add(v[i].evc[j], i, tl, tr, 0);
		}

	for (int i = 0; i < n1; ++i)
	{
		std::cerr << i << ":";
		for (int j = 0; j < e1[i].size(); ++j)
			std::cerr << " " << e1[i][j] << "(" << ec1[i][j] << ") ";
		std::cerr << "\n";
	}
	for (int i = 0; i < n1; ++i)
		std::cerr << v2v[i] << " ";
	std::cerr << "\n\n";


	int q;
	std::cin >> q;
	while (q--)
	{
		int a, b;
		std::cin >> a >> b;
		--a;
		--b;
		std::cout << solve(a, b) << "\n";
	}

	return 0;
}
