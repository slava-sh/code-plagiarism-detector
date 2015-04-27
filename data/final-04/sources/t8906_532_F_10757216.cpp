#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long LL;

const int MOD = (int)1e9 + 7;

LL H1[26][1 << 18], H2[26][1 << 18];
LL X1[1 << 18], X2[1 << 18];

int n, m;

char S[1 << 18];
char T[1 << 18];

map<LL, int> M;
int mask[26];

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%s", S);
	scanf("%s", T);

	X1[0] = X2[0] = 1;
	for(int i = 1; i < 1 << 18; ++i)
	{
		X1[i] = X1[i - 1] * 2999 % MOD;
		X2[i] = X2[i - 1] * 3137 % MOD;
	}

	for(int i = 0; i < 26; ++i)
	{
		H1[i][0] = H2[i][0] = 0;
		for(int j = 0; j < n; ++j)
		{
			H1[i][j + 1] = (H1[i][j] * 2999 + (S[j] == 'a' + i)) % MOD;
			H2[i][j + 1] = (H2[i][j] * 3137 + (S[j] == 'a' + i)) % MOD;
		}
	}

	for(int i = 0; i < 26; ++i)
	{
		LL h1 = 0;
		LL h2 = 0;
		for(int j = 0; j < m; ++j)
		{
			h1 = (h1 * 2999 + (T[j] == 'a' + i)) % MOD;
			h2 = (h2 * 3137 + (T[j] == 'a' + i)) % MOD;
		}
		LL hash = h1 * MOD + h2;
		if (hash != 0)
			M[hash] = i;
	}

	vector<int> res;
	for(int i = 0; i <= n - m; ++i)
	{
		for(int j = 0; j < 26; ++j)
			mask[j] = (1 << 26) - 1;
		bool bad = 0;
		for(int j = 0; j < 26; ++j)
		{
			LL h1 = (H1[j][i + m] - H1[j][i] * X1[m]) % MOD;
			if (h1 < 0)
				h1 += MOD;
			LL h2 = (H2[j][i + m] - H2[j][i] * X2[m]) % MOD;
			if (h2 < 0)
				h2 += MOD;
			LL hash = h1 * MOD + h2;
			if (hash == 0)
				continue;
			if (!M.count(hash))
			{
				bad = 1;
				break;
			}
			int k = M[hash];
			mask[k] &= 1 << j;
			mask[j] &= 1 << k;
		}
		for(int j = 0; j < 26; ++j)
			if (mask[j] == 0)
				bad = 1;
		if (!bad)
			res.push_back(i);
	}

	printf("%d\n", res.size());
	for(int i = 0; i < res.size(); ++i)
		printf("%d ", res[i] + 1);
	if (!res.empty())
		printf("\n");
	return 0;
}