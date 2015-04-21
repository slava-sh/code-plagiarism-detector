#include<iostream>
using namespace std;
int x[1007][1007], y[1007][1007],sz[1007];
bool used[1007][1007];
long long vect(long long x1, long long y1, long long x2, long long y2,long long x3,long long y3,long long x4,long long y4)
{
	long long dx1 = x2 - x1, dy1 = y2 - y1, dx2 = x4 - x3, dy2 = y4 - y3;
	return dx1*dy2 - dx2*dy1;
}
bool diff(long long x, long long y)
{
	return (x > 0 && y < 0) || (x < 0 && y > 0);
}
bool diffSide(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	return diff(vect(x1, y1, x2, y2, x1, y1, x3, y3), vect(x1, y1, x2, y2, x1, y1, x4, y4));
}
bool intersect(int x1, int y1, int x2, int y2,int x3,int y3,int x4,int y4)
{
	if (x1 == x3 && y1 == y3) return false;
	if (x1 == x4 && y1 == y4) return false;
	if (x2 == x3 && y2 == y3) return false;
	if (x2 == x4 && y2 == y4) return false;
	return diffSide(x1, y1, x2, y2, x3, y3, x4, y4) && diffSide(x3, y3, x4, y4, x1, y1, x2, y2);
}
int main()
{
	int a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> sz[i];
		for (int j = 1; j <= sz[i] + 1; j++)
		{
			cin >> x[i][j] >> y[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sz[i]; j++)
		{
			if (x[i][j] < a && x[i][j + 1] < a)
			{
				used[i][j] = true;
			}
			if (x[i][j]>b && x[i][j + 1] > b)
			{
				used[i][j] = true;
			}
			if (x[i][j] < a) x[i][j] = a;
			if (x[i][j + 1] > b) x[i][j] = b;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = 1; k <= sz[i]; k++)
			{
				for (int p = 1; p <= sz[j]; p++)
				{
					if ( !used[i][k] && !used[j][p] && intersect(x[i][k], y[i][k], x[i][k + 1], y[i][k + 1], x[j][p], y[j][p], x[j][p + 1], y[j][p + 1]))
					{
						cout << "No" << endl;
						cout << i << ' ' << j << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
}