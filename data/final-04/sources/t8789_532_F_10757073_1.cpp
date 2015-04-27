#include <bits/stdc++.h>

using namespace std;

const int MAX_ALPH = 26;
const int MAX_N = 250000;
char line[MAX_N];
char tofind[MAX_N];
int lp[MAX_ALPH];
int funcz[2 * MAX_N];

char united[2 * MAX_N];
bool gp[MAX_ALPH][MAX_ALPH][MAX_N];

void dodo(int n, int m)
{
    for (char a = 'a'; a <= 'z'; a++)
		for (char b = a; b <= 'z'; b++)
		{
			int num_a = a - 'a', num_b = b - 'a', l = -1, r = 0;
			for (int i = 1; i < n + m; i++)
			{
				funcz[i] = 0;
				if (i < r) funcz[i] = min(funcz[i - l], r - i);
				while (i + funcz[i] < n + m) {
					char c1 = united[funcz[i]], c2 = united[i + funcz[i]];
					if (funcz[i] < m) c1 = (c1 == a ? a : (c1 == b ? b : '#'));
					else c1 = (c1 == a ? b : (c1 == b ? a : '#'));

					if (i + funcz[i] < m) c2 = (c2 == a ? a : (c2 == b ? b : '#'));
					else c2 = (c2 == a ? b : (c2 == b ? a : '#'));

					if (c1 == c2)funcz[i]++;else break;
				}
				if (i + funcz[i] > r)	l = i,	r = i + funcz[i];
				if (funcz[i] >= m
                &&
                i >= m)
					gp[num_a][num_b][i - m] = 1;
			}
		}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	scanf(" %s %s", line, tofind);

	memset(lp, -1, sizeof(lp));
	for (int i = m - 1; i >= 0; i--)lp[tofind[i] - 'a'] = i;

	for (int i = 0; i < m; i++)united[i] = tofind[i];

	for (int i = 0; i < n; i++)united[i + m] = line[i];
    
    dodo(n, m);

	vector <int> answer;
	for (int i = 0; i <= n - m; i++)
	{
		bool ok = true;
		for (int a = 0; a < MAX_ALPH; a++)
		{
			int pos = lp[a];
			if (pos == -1)continue;
			int b = line[i + pos] - 'a';
			if (!gp[min(a, b)][max(a, b)][i])
			{
				ok = false;
				break;
			}
		}
		if (ok)
			answer.push_back(i + 1);
	}

	printf("%d\n", (int)answer.size());
	for (int p : answer)
		printf("%d ", p);

	return 0;
}
