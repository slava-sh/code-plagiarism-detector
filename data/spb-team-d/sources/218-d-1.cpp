#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#pragma comment (linker, "/STACK:136667216")


using namespace std;

struct node
{
	long long value, keep;
	node* l;
	node* r;
	node()
	{
		value = 0;
		keep = 0;
	}
};
int A, B, X;

void push(node* i, int l, int r)
{
	if (l < r)
	{
		i->l->keep += i->keep;
		i->r->keep += i->keep;
		i->l->value += i->keep * (r - l + 1) / 2;
		i->r->value += i->keep * (r - l + 1) / 2;
	}
}

long long get(node* i, int l, int r)
{
	if (B < l || A > r) return 0;
	if (l >= A && r <= B)
	{
		return i->value;
	}
	push(i, l, (l + r) / 2);
	get(i->l, l, (l + r) / 2 - 1);
	get(i->r, (l + r) / 2, r);
}

void inc(node* i, int l, int r)
{
	if (B < l || A > r) return;
	i->value += X * (min(r, B) - max(l, A) + 1);
	if (l >= A && r <= B)
	{
		i->keep += X;
		return;
	}
	push(i, l, r);
	inc(i->l, l, (l + r) / 2 - 1);
	inc(i->r, (l + r) / 2, r);
}

void create(node *i, int l, int r)
{
	if (l < r)
	{
		if (l == 1 && r == 2) cout << 1;
		i->l = new node;
		i->r = new node;
		create(i->l, l, (l + r) / 2 - 1);
		create(i->r, (l + r) / 2 , r);
	}
}

int main()
{
	freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);
	vector <pair <pair <int, int>, int> > v;
	int n, m;
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i].first.first >> v[i].first.second >> v[i].second;
	
	for (int i = 0; i < m; i++)
	{
		int x;
		long long cur = 0;
		cin >> x;
		for (int j = 0; j < n; j++)
		{
			if (v[j].first.first <= x && v[j].first.second >= x)
			{
				int p = (x - v[j].first.first) % 2;
				cur += v[j].second * (p * 2 - 1);
			}
		}
		cout << -cur << endl;
	}
	return 0;
}