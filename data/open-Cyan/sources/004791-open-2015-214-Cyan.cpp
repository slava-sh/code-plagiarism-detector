#include<iostream>
#include<vector>
using namespace std;
int x[1007][1007], y[1007][1007],sz[1007];
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
			vector<long double>dy;
			for (int k = 1; k <= sz[i] + 1;k++)
			{
				int cx = x[i][k];
				if (cx<a || cx>b) continue;
				double alt1 = 1234228, alt2 = 1234228;
				for (int k = 1; k <= sz[i]; k++)
				{
					if (x[i][k] <= cx && x[i][k + 1] >= cx)
					{
						double step = 1.0*(y[i][k + 1] - y[i][k]) / (x[i][k + 1] - x[i][k]);
						alt1 = 1.0*(y[i][k] + step*(cx - x[i][k]));
					}
				}
				for (int k = 1; k <= sz[j]; k++)
				{
					if (x[j][k] <= cx && x[j][k + 1] >= cx)
					{
						double step = 1.0*(y[j][k + 1] - y[j][k]) / (x[j][k + 1] - x[j][k]);
						alt2 = 1.0*(y[j][k] + 1.0*step*(cx - x[j][k]));
					}
				}
				if (alt1 == 1234228 || alt2 == 1234228) continue;
				dy.push_back(alt2 - alt1);
			}
			for (int k = 1; k <= sz[j] + 1; k++)
			{
				int cx = x[j][k];
				if (cx<a || cx>b) continue;
				double alt1 = 1234228, alt2 = 1234228;
				for (int k = 1; k <= sz[i]; k++)
				{
					if (x[i][k] <= cx && x[i][k + 1] >= cx)
					{
						double step = 1.0*(y[i][k + 1] - y[i][k]) / (x[i][k + 1] - x[i][k]);
						alt1 = 1.0*(y[i][k] + step*(cx - x[i][k]));
					}
				}
				for (int k = 1; k <= sz[j]; k++)
				{
					if (x[j][k] <= cx && x[j][k + 1] >= cx)
					{
						double step = 1.0*(y[j][k + 1] - y[j][k]) / (x[j][k + 1] - x[j][k]);
						alt2 = 1.0*(y[j][k] + 1.0*step*(cx - x[j][k]));
					}
				}
				if (alt1 == 1234228 || alt2 == 1234228) continue;
				dy.push_back(alt2 - alt1);
			}
			bool haveless = false, havemore = false;
			for (int k = 0; k < dy.size(); k++)
			{
				if (dy[k] < -eps) haveless = true;
				if (dy[k] > eps) havemore = true;
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