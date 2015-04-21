#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 5150;
typedef long long ll;
const ll INF = 1e18;
const double EPS = 1e-9;

double a, b;
int n;
vector <vector <pair<int, int> > > mountain;

void getY (vector <int> &x, vector <pair <int, int> > &mount, vector <double> &res)
{
	res.resize(x.size());
	int ptr = 0;
	for (int i = 0; i < x.size(); i++)
	{
		if (mount[ptr + 1].first == x[i])
		{
			ptr++;
			res[i] = mount[ptr].second;
		}
		else
		{
			res[i] = mount[ptr].second + 
				(double)(mount[ptr + 1].second - mount[ptr].second) / 
				(double)(mount[ptr + 1].first - mount[ptr].first) * 
				(double)(x[i] - mount[ptr].first);
		}
	}
}

bool check(vector <pair <int, int> > &a, vector <pair <int, int> > &b)
{
	vector <int> x;
	int ptr1 = 0;
	int ptr2 = 0;

	while (ptr1 != a.size())
	{
		if (ptr2 == b.size())
			break;
		if (a[ptr1].first == b[ptr2].first)
		{
			ptr1++;
			continue;
		}
		if (a[ptr1].first > b[ptr2].first)
		{
			x.push_back(b[ptr2].first);
			ptr2++;
		}
		else
		{
			x.push_back(a[ptr1].first);
			ptr1++;
		}
	}
	while (ptr2 != b.size())
	{
		if (b[ptr2].first != x.back())
			x.push_back(b[ptr2].first);
		ptr2++;
	}
	
	vector <double> y1, y2;
	getY(x, a, y1);
	getY(x, b, y2);

	bool ls = false;
	bool gr = false;
	for (int i = 0; i < y1.size(); i++)
	{
		if (y1[i] + EPS < y2[i])
			ls = true;
		if (y1[i] > y2[i] + EPS)
			gr = true;
	}
	return ls && gr;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	cin >> a >> b;	
	cin >> n;
	mountain.resize(n);

	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		for (int j = 0; j < l + 1; j++)
		{
			int x, y;
			cin >> x >> y;
			mountain[i].push_back(make_pair(x, y));
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (check(mountain[i], mountain[j]))
			{
				cout << "No\n" << i + 1 << ' ' << j + 1;
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}