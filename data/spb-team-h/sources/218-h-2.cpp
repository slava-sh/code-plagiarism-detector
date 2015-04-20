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

int main()
{
	freopen("names.in", "r", stdin);
	freopen("names.out", "w", stdout);
	int n;
	map <string, vector <int> > m;
	vector <human> a;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		human x;
		cin >> x.n1 >> x.n2 >> x.n3;
		m[x.n1].push_back(i);
		m[x.n2].push_back(i);
		m[x.n3].push_back(i);
		a[i] = x;
	}/*
	4
	Ivanov Ivan Ivanovich
	Ivan Borisovich Petrov
	Sergey Ivanovich Sidorov
	Pavlov Sergey Borisovich*/
	for (auto it = m.begin(); it != m.end(); it++)
	{
		if (it->second.size() == 1)
		{
			if (a[it->second[0]].n3 == it->first)
			{
				if (m[a[it->second[0]].n1].size() > 1)
				{
					swap(a[it->second[0]].n1, a[it->second[0]].n3);
					swap(a[it->second[0]].n2, a[it->second[0]].n3);
				}
			}
		}

		}
			
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
		cout << a[i].n1 << " " << a[i].n2 << " " << a[i].n3 << endl;
	return 0;
}