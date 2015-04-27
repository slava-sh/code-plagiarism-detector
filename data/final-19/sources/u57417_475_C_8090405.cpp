#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1211;

int sum[N][N];
int num[N][N];

bool check(int a, int b, int n, int m, int pi, int pj)
{
	int painted = a * b;
	//cout << '!' << a << ' ' << b << '\n';
	while(true)
	{
		//cout << pi << ' ' << pj << '\n';
		//cout << painted << '\n';
		if(pi + a - 1 > n || pj + b - 1 > m)
			return false;
		/*
		cout << sum[pi + a - 1][pj + b - 1] - sum[pi + a - 1][pj - 1]
			- sum[pi - 1][pj + b - 1] + sum[pi - 1][pj - 1] << '\n';
		*/
		if(sum[pi + a - 1][pj + b - 1] - sum[pi + a - 1][pj - 1]
			- sum[pi - 1][pj + b - 1] + sum[pi - 1][pj - 1] != a * b)
			return false;
		if(pi + a <= n && pj + b <= m && num[pi + a][pj] && num[pi][pj + b])
			return false;
		else if(pi + a <= n && num[pi + a][pj])
		{
			pi ++;
			painted += b;
		}
		else if(pj + b <= m && num[pi][pj + b])
		{
			pj ++;
			painted += a;
		}
		else break;
	}
	//cout << painted << '\n';
	return painted == sum[n][m];
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int pi = -1, pj = -1;

	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < m; j++)
			if(s[j] == '.')
				num[i + 1][j + 1] = 0;
			else
			{
				num[i + 1][j + 1] = 1;
				if(pi == -1)
				{
					pi = i + 1;
					pj = j + 1;
				}
			}
	}
	if(pi == -1)
	{
		cout << -1 << '\n';
		return 0;
	}
	memset(sum, 0, sizeof(sum));

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			sum[i][j] = -sum[i-1][j-1] + sum[i][j-1] + sum[i-1][j] + num[i][j];

	int ans = -1;

	int downMost = 0;
	for(int i = pi; i <= n; i++)
		if(num[i][pj])
			downMost ++;
		else break;

	int rightMost = 0;
	for(int j = pj; j <= m; j++)
		if(num[pi][j])
			rightMost ++;
		else break;

	for(int i = 1; i <= downMost; i++)
		if(check(i, rightMost, n, m, pi, pj))
			if(ans == -1)
				ans = i * rightMost;
			else ans = min(ans, i * rightMost);
		else {}

	for(int j = 1; j <= rightMost; j++)
		if(check(downMost, j, n, m, pi, pj))
			if(ans == -1)
				ans = downMost * j;
			else ans = min(ans, downMost * j);
		else {}

	cout << ans << '\n';
	return 0;
}