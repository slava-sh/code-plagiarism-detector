#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 5150;
typedef long long ll;
const ll INF = 1e18;

int mas[MAXN];
int tree[MAXN];
int precalc[MAXN][MAXN];
int n;
int l, r, res, inv;

int inversions()
{
	int amount = 0;
	for (int i = 0; i < n; i++)
		tree[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < mas[i]; j++)
			amount += tree[j];
		tree[mas[i]] = 1;
	}
	return amount;
}

void Precalc()
{
	inv = inversions();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			precalc[i][j] = (j == 0 ? 0 : precalc[i][j - 1]) + (int)(mas[j] < i);
		}
	}
}

int ls(int l, int r, int x)
{
	return precalc[x][r] - (l == 0 ? 0 : precalc[x][l - 1]);
}

int gr(int l, int r, int x)
{
	return r - l - ls(l, r, x);
}

void check(int i, int j)
{
	int curr = inv + ls(i, j, mas[i]) - gr(i, j, mas[i]) + gr(i, j, mas[j]) - ls(i, j, mas[j]);
	if (curr > res)
	{
		res = curr;
		l = i + 1;
		r = j + 1;
	}
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
		mas[i]--;
	}
	Precalc();
	l = r = -1;
	res = inv;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			check(i, j);
		}
	}

	printf("%d %d", l, r);
	return 0;
}