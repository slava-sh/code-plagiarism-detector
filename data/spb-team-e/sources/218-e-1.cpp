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
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	int n, m, l[2], r[2], can[2] = {0}, score[2] = {0}, gen = {0}, a;
	cin >> n >> m;
	cin >> l[0] >> r[0];
	cin >> l[1] >> r[1];
	for (int i = 0; i < n; i++){
		cin >> a;
		if (l[0] <= a && a <= r[0] && l[1] <= a && a <= r[1])
			gen++;
		else if (l[0] <= a && a <= r[0])
			can[0]++;
		else if (l[1] <= a && a <= r[1])
			can[1]++;
	}
	//cout << can[0] << ' ' << gen << ' ' << can[1] << endl;
	for (int i = 0; i < m; i++)
		if (gen > 0){
			gen--;
			score[i % 2]++;
		}
		else if (can[i % 2] > 0){
			can[i % 2]--;
			score[i % 2]++;
		}
	//cout << score[0] << ' ' << score[1] << endl;
	if (score[0] > score[1])
		cout << "Petya\n";
	else if (score[1] > score[0])
		cout << "Vasya\n";
	else
		cout << "Draw\n";
	return 0;
}