#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define INF 1000000007
#define Eps 1e-7
struct Point
{
	int x, y;
	int mount;
	Point() :x(-INF), y(-INF){}
};

int main()
{
	int A, B;
	int N;
	cin >> A >> B >> N;
	vector<vector<Point> > m(N);
	vector<int> l(N);
	for (int i = 0; i < N; i++)
	{
		cin >> l[i];
		l[i]++;
		m[i].resize(l[i]);
		for (int q = 0; q < l[i]; q++)
		{
			cin >> m[i][q].x >> m[i][q].y;
			m[i][q].mount = i;
		}
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int q = i + 1; q < N; q++)
		{
			char pos = 'n';
			int it1 = -1, it2 = -1;
			vector<Point> com(l[i] + l[q]);
			for (int j = 0, i1 = 0, i2 = 0; j < l[i] + l[q]; j++)
			{
				if (i1 == l[i])
				{
					com[j] = m[q][i2];
					i2++;
					continue;
				}
				if (i2 == l[q])
				{
					com[j] = m[i][i1];
					i1++;
					continue;
				}
				if (m[i][i1].x < m[q][i2].x)
				{
					com[j] = m[i][i1];
					i1++;
					continue;
				}
				else
				{
					com[j] = m[q][i2];
					i2++;
					continue;
				}
			}
			for (int j = 0; j < l[i] + l[q]; j++)
			{
				if (com[j].mount == i)
				{
					it1++;
					if (it2 == -1 || it2 == l[q] - 1)
						continue;
					else
					{
						long double y = m[q][it2].y + (m[q][it2 + 1].y - m[q][it2].y) * ((m[i][it1].x - m[q][it2].x) * 1.0 / (m[q][it2 + 1].x - m[q][it2].x));
						if (abs(y - com[j].y) < Eps)
							continue;
						if (y > com[j].y)
						{
							if (pos == 'n')
								pos = 's';
							else if (pos == 'f')
							{
								cout << "No" << endl;
								cout << i + 1 << ' ' << q + 1 << endl;
								return 0;
							}
						}
						else if (y < com[j].y)
						{
							if (pos == 'n')
								pos = 'f';
							else if (pos == 's')
							{
								cout << "No" << endl;
								cout << i + 1 << ' ' << q + 1 << endl;
								return 0;
							}
						}
					}
				}
				else if (com[j].mount == q)
				{
					it2++;
					if (it1 == -1 || it1 == l[i] - 1)
						continue;
					else
					{
						long double y = m[i][it1].y + (m[i][it1 + 1].y - m[i][it1].y) * ((m[q][it2].x - m[i][it1].x) * 1.0 / (m[i][it1 + 1].x - m[i][it1].x));
						if (abs(y - com[j].y) < Eps)
							continue;
						if (y > com[j].y)
						{
							if (pos == 'n')
								pos = 'f';
							else if (pos == 's')
							{
								cout << "No" << endl;
								cout << i + 1 << ' ' << q + 1 << endl;
								return 0;
							}
						}
						else if (y < com[j].y)
						{
							if (pos == 'n')
								pos = 's';
							else if (pos == 'f')
							{
								cout << "No" << endl;
								cout << i + 1 << ' ' << q + 1 << endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}