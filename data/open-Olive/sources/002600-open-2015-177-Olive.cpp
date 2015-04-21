#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 200500;
typedef long long ll;
const ll INF = 1e18;

int mas[MAXN];
int tree[MAXN];
int n;
int l, r, res;

int sum(int x)
{
	int res = 0;
	for (int i = 0; i < x; i++)
		res += tree[i];
	return res;
}

void update(int x)
{
	tree[x] = 1;
}

int inversions()
{
	int amount = 0;
	for (int i = 0; i < n; i++)
		tree[i] = 0;

	for (int i = 0; i < n; i++)
	{
		amount += sum(mas[i]);
		update(mas[i]);
	}

	return -amount;
}
void check(int i, int j)
{
	swap(mas[i], mas[j]);
	int curr = inversions();
	if (curr < res)
	{
		res = curr;
		l = i + 1;
		r = j + 1;
	}
	swap(mas[i], mas[j]);
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
	
	l = r = -1;
	res = inversions();

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