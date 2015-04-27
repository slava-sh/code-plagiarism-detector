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

const int DX[] = {-1, 1, 0, 0};
const int DY[] = {0, 0, -1, 1};

char A[1 << 10][1 << 10];
int C[1 << 10][1 << 10];
int R[1 << 20];
VInt E[1 << 20];
int B[16];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);

	int i, j, k;
	FOR(i, 0, N)
		scanf("%s", A[i]);

	CLEAR(C, -1);
	int cnt = 0;
	FOR(i, 0, N)
		FOR(j, 0, M)
			if(A[i][j] == '.' && C[i][j] == -1)
			{
				if(j != M - 1 && A[i][j + 1] != '#')
				{
					if(C[i][j + 1] == -1)
					{
						C[i][j + 1] = cnt;
						++cnt;
					}

					C[i][j] = C[i][j + 1];
					continue;
				}

				if(i != N - 1 && A[i + 1][j] != '#')
				{
					if(C[i + 1][j] == -1)
					{
						C[i + 1][j] = cnt;
						++cnt;
					}

					C[i][j] = C[i + 1][j];
					continue;
				}

				if(j != 0 && A[i][j - 1] != '#')
				{
					C[i][j] = C[i][j - 1];
					continue;
				}

				if(i != 0 && A[i - 1][j] != '#')
				{
					C[i][j] = C[i - 1][j];
					continue;
				}

				printf("-1\n");
				return 0;
			}

	FOR(i, 0, N)
		FOR(j, 0, M)
			if(C[i][j] != -1)
				FOR(k, 0, 4)
				{
					int x = i + DX[k];
					int y = j + DY[k];
					if(x < 0 || x >= N || y < 0 || y >= M || C[x][y] == -1 || C[x][y] >= C[i][j])
						continue;

					E[ C[i][j] ].PB(C[x][y]);
				}

	FOR(i, 0, cnt)
	{
		CLEAR(B, 0);
		FOR(j, 0, SIZE(E[i]))
			B[ R[ E[i][j] ] ] = 1;

		R[i] = 0;
		while(B[ R[i] ])
			++R[i];
	}

	FOR(i, 0, N)
		FOR(j, 0, M)
			if(C[i][j] != -1)
				A[i][j] = '0' + R[ C[i][j] ];

	FOR(i, 0, N)
		printf("%s\n", A[i]);

	return 0;
};
