#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int V[128];
int T[128];
int L[128];
int R[128];
int C[128];

int main()
{
	int hl, hr, n;
	scanf("%d%d%d", &hl, &hr, &n);

	int i, j, k;
	FOR(i, 0, n)
	{
		char buf[4];
		scanf("%d%s%d%d", &V[i], buf, &L[i], &R[i]);
		T[i] = buf[0] == 'T' ? 1 : 0;
	}

	int res = 0;
	FOR(i, -n, n + 1)
	{
		if(i == 0)
			continue;

		int a = 0;
		int b = i;
		if(a > b)
			swap(a, b);

		CLEAR(C, 0);
		int fail = 0;
		FOR(j, a, b)
		{
			int type = (j % 2 == 0 ? 1 : 0);

			Int pos = 100000*(100*(j + 1) - hl);
			Int z = ((i % 2 == 0 ? hr : 100 - hr) + i*100 - hl);
			if(z < 0)
			{
				z = -z;
				pos = -pos;
			}


			FOR(k, 0, n)
				if(T[k] == type && L[k]*z <= pos && pos <= R[k]*z)
					break;

			if(k == n)
				fail = 1;
			else
				++C[k];
		}

		int r = 0;
		FOR(j, 0, n)
		{
			if(C[j] == 1)
				r += V[j];

			if(C[j] > 1)
				fail = 1;
		}

		if(fail == 0)
			res = max(res, r);
	}

	printf("%d\n", res);
	return 0;
};
