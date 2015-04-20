#include <cstdio>
#include <iostream>
using namespace std;


int g[1111][1111], used[1111], a[1111];
int fl = 0, n;

void dfs(int v, int col)
{
	used[v] = col;
	for ( int i = 0; i < n; i++)
	{
		if ( used[i] == 0 && g[i][v] != 0)
			dfs(i, col * g[i][v]);
		if ( g[i][v] != 0)
			if (used[v] != used[i] * g[i][v])
				fl = 1;
	}
}
   

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	scanf("%d", &n);
	for ( int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	//cerr << "!!!" << endl;
	for ( int i = 1; i < n; i++)
	{
		if ( a[i] > n - i)
		{
			printf("0");
			return 0;
		}

		//cerr << "!!!" << endl;
		if ( a[i] != 0)
		{
			for ( int j = 0; j < a[i]; j++)
			{
				g[j][j + i] = 1;
				g[j + i][j] = 1;
			}
		}	
		if ( a[i] != -1)
		{
			g[a[i]][i + a[i]] = -1;	
			g[i + a[i]][a[i]] = -1;	
		}
	}
	/*
	cerr << "!!!" << endl;
	for ( int i = 0; i < n; i++)
	{
		for ( int j = 0; j < n; j++)
			printf("%d", g[i][j]);
		printf("\n");
	}

	cerr << "!!!" << endl;
	*/
	int col = 1;
	for ( int i = 0; i < n; i++)
	{
		if ( used[i] == 0)
			dfs(i, col++);
		if ( fl == 1)
		{
			printf("0");
			return 0;
		}
	}
	//cerr << "!!!" << endl;
	int res = 1;
	for ( int i = 1; i < col; i++)
	{
		res *= 2;
		res = res % ( int(1e9) + 7);
	}

	printf("%d", res);


	return 0;
}

