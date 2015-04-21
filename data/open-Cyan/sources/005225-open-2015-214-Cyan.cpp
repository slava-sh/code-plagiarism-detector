#include<iostream>
#include<vector>
using namespace std;
int x[1007][1007], y[1007][1007], sz[1007];
const double eps = 10e-6;
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
		for (int j = i + 1; j <= n; j++)
		{
			bool haveless = false, havemore = false;
			for (int k = 1; k <= sz[i] + 1; k++)
			{
				int cx = x[i][k];
				if (cx<a || cx>b) continue;
				double alt1 = y[i][k], alt2 = 1234228;
				int l = 1, r = sz[j] + 2;
				while (r - l > 1)
				{
					int m = (l + r) / 2;
					if (x[j][m] <= cx)
					{
						l = m;
					}
					else
					{
						r = m;
					}
				}
				int p = l;
				if (x[j][p] <= cx && x[j][p + 1] >= cx)
				{
					double step = 1.0*(y[j][p + 1] - y[j][p]) / (x[j][p + 1] - x[j][p]);
					alt2 = 1.0*(y[j][p] + 1.0*step*(cx - x[j][p]));
				}
				if (alt2 == 1234228) continue;
				double dy = alt2 - alt1;
				if (dy < -eps) haveless = true;
				if (dy > eps) havemore = true;
			}
			for (int k = 1; k <= sz[j] + 1; k++)
			{
				int cx = x[j][k];
				if (cx<a || cx>b) continue;
				double alt1 = 1234228, alt2 = y[j][k];
				int l = 1, r = sz[i] + 2;
				while (r - l > 1)
				{
					int m = (l + r) / 2;
					if (x[i][m] <= cx)
					{
						l = m;
					}
					else
					{
						r = m;
					}
				}
				int p = l;
				if (x[i][p] <= cx && x[i][p + 1] >= cx)
				{
					double step = 1.0*(y[i][p + 1] - y[i][p]) / (x[i][p + 1] - x[i][p]);
					alt1 = 1.0*(y[i][p] + step*(cx - x[i][p]));
				}
				if (alt1 == 1234228) continue;
				double dy = alt2 - alt1;
				if (dy < -eps) haveless = true;
				if (dy > eps) havemore = true;
			}
			if (haveless && havemore)
			{
				cout << "No" << endl;
				cout << i << ' ' << j << endl;
				return 0;
			}
		}

	}
	cout << "Yes" << endl;
}