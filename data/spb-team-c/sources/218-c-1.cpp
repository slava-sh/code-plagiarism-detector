#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
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

struct human
{
	string n1, n2, n3;
};

bool operator <(human a, human b)
{
	return a.n1 < b.n1 || a.n1 == b.n1 && a.n2 < b.n2 || a.n1 == b.n1 && a.n2 == b.n2 && a.n3 < b.n3;
}

int a[1010], c[1010];

int main()
{
	freopen("conquest.in", "r", stdin);
	freopen("conquest.out", "w", stdout);
	bool b;
	int res = 0, s = 0, p = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	while (1){
		for (int i = 1; i <= n; i++)
			s += a[i];
		b = 0;
		for (int i = n; i > 0; i--){
			s -= a[i];
			if (p + s <= a[i]){
				a[i]--, p++, res += c[i];
				b = 1;
				break;
			}
		}
		s = 0;
		if (!b)
			break;
	}
	cout << res;
	return 0;
}