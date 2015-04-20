#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
using namespace std;
typedef __int64 llint;
typedef string str;
vector <int> G[5010];
vector <int> L[5010];
int A[5010];
int C[5010];
int S[5010];
bool M[5010];
struct int2
{
	int a, b;
	int2(int _a, int _b){
		a = _a; b = _b;
	}
};
bool operator < (int2 a, int2 b)
{
	if(a.b == b.b)
	{
		return a.a > b.a;
	}
	return a.b > b.b;
}
priority_queue < int2 > Q;
int main()
{
	freopen("secure.in", "r", stdin); freopen("secure.out", "w", stdout);
	int n, m, i, a, b, c, d;
	scanf("%d%d", &n, &m);
	fill(C, C + n, -1);
	fill(A, A + n, 2e9);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &S[i]);
		if(S[i] == 1)
		{
			A[i] = 0;
			C[i] = i;
			Q.push( int2(i, 0) );
		}
	}
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		a--; b--;
		G[a].push_back(b);
		L[a].push_back(c);
		G[b].push_back(a);
		L[b].push_back(c);
	}
	for(; Q.size() > 0; )
	{
		a = Q.top().a; b = Q.top().b; Q.pop();
		if(M[a] == 1)
		{
			continue;
		}
		M[a] = 1;
		for(i = 0; i < G[a].size(); i++)
		{
			c = G[a][i]; d = A[a] + L[a][i];
			if(A[c] > d)
			{
				A[c] = d; C[c] = C[a];
				Q.push( int2(c, d) );
			}
		}
	}
	a = 2e9; b = -1;
	for(i = 0; i < n; i++)
	{
		if(S[i] != 2)
		{
			continue;
		}
		if(a > A[i])
		{
			a = A[i];
			b = i;
		}
	}
	if(a == 2e9)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d %d %d\n", C[b] + 1, b + 1, a);
	}
	return 0;
}