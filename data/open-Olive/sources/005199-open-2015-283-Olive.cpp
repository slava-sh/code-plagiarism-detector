#include <bits/stdc++.h>
#define TASK "a"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef std::pair < int , int > pair;
const int IINF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = std::numeric_limits < double > ::infinity();
const ld LDINF = std::numeric_limits < ld > ::infinity();
const double EPS = 1e-9;

const int N = 1000179;

struct Treap
{
	static Treap * null;

	int x, y;
	Treap * l, * r;
	int size;

	void recompute()
	{
		size = 1 + l->size + r->size;
	}

	Treap(const char * ss) : x(0), y(0), l(this), r(this), size(0) {}
	Treap(int nx) : x(nx), y(rand()), l(null), r(null), size(1) {}
};
Treap * Treap::null = new Treap("Lorem ipsum dolor sit amet");

Treap * merge(Treap * l, Treap * r)
{
	if (l == Treap::null)
		return r;
	if (r == Treap::null)
		return l;
	if (l->y < r->y)
	{
		l->r = merge(l->r, r);
		l->recompute();
		return l;
	} else {
		r->l = merge(l, r->l);
		r->recompute();
		return r;
	}
}

void split(Treap * t, int x, Treap *& l, Treap *& r)
{
	if (t == Treap::null)
	{
		l = r = t;
		return;
	}
	if (t->x < x)
	{
		l = t;
		split(t->r, x, t->r, r);
	} else {
		r = t;
		split(t->l, x, l, t->l);
	}
	t->recompute();
}

int n;
int a[N];

void myMain()
{
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	int ans = -1, ans1 = -2, ans2 = -2;
	static char at[N*sizeof(Treap)];
	for (int i = 1; i <= n; ++i)
		new ((Treap*)at + i) Treap(i);
	for (int i = 0; i < n; ++i)
	{
		Treap * b = Treap::null;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] > a[i])
				continue;
			Treap * b1, *b2;
			split(b, a[j], b1, b2);
			if (b2->size > ans)
			{
				ans = b2->size;
				ans1 = i;
				ans2 = j;
			}
			Treap * ct = (Treap*)at + a[j];
			ct->size = 1;
			ct->l = ct->r = Treap::null;
			b = merge(merge(b1, ct), b2);
		}
	}
	std::cout << ans1 + 1 << " " << ans2 + 1 << "\n";
}


void generateTest()
{
	std::cout << 5000 << "\n";
	std::vector < int > x;
	for (int i = 0; i < 5000; ++i)
		x.push_back(i+1);
	std::random_shuffle(x.begin(), x.end());
	for (int i = 0; i < 5000; ++i)
		std::cout << x[i] << " ";
}

int main()
{
#ifdef GEN
	freopen("input.txt", "w", stdout);
	generateTest();
	return 0;
#endif

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
#ifdef LOCAL
	std::cerr << "START\n";
#endif

	myMain();

#ifdef LOCAL
	std::cerr << "TIME = " << clock() * 1. / CLOCKS_PER_SEC << "\n";;
#endif
	return 0;
}
