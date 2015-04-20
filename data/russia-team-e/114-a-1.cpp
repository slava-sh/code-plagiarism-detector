#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "binary"

const int MOD = 1000000007;
const int maxn = 1005;

vector<int> gr[maxn], antigr[maxn];
int z[maxn];
int was[maxn];
int n;

void go(int cur, int curc)
{
	if (was[cur] != 0 && was[cur] != curc)
	{
		printf("0\n");
		exit(0);
	}
	if (was[cur] != 0) return;
	was[cur] = curc;
	for (int i = 0; i < (int)gr[cur].size(); i++) go(gr[cur][i], curc);
	for (int i = 0; i < (int)antigr[cur].size(); i++) go(antigr[cur][i], 3 - curc);
}

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &z[i]);

	if (z[0] != 0)
	{
		printf("0\n");
		return 0;
	}
	for (int i = 1; i < n; i++) if (z[i] != -1)
	{
		if (i + z[i] > n)
		{
			printf("0\n");
			return 0;
		}
		for (int j = 0; j < z[i]; j++)
		{
			gr[j].push_back(j + i);
			gr[j + i].push_back(j);
		}
		if (i + z[i] != n)
		{
			antigr[z[i]].push_back(i + z[i]);
			antigr[i + z[i]].push_back(z[i]);
		}
	}
	for (int i = 0; i < n; i++) was[i] = 0;
	ll answer = 1;
	for (int i = 0; i < n; i++) if (was[i] == 0)
	{
		go(i, 1);
		answer = (answer * 2) % MOD;
	}

	cout << answer << endl;

	return 0;
}