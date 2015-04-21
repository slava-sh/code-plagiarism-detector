#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define lint long long int

struct point
{
	int x, y;
};

bool operator<(point a, point b)
{
	return a.x < b.x || a.x == b.x && a.y < b.y;
}

int A, B;
int N;

vector<vector<point>> v;

vector<double> vl;

double y(double x, int n)
{
	if(x > v[n].back().x)
		return 0;
	int lx = 0;
	int l, r;
	l = 0;
	r = v[n].size();
	for(int i = 0; i < 100; i++)
	{
		int mid = (l + r) / 2;
		if(v[n][mid].x < x)
			l = mid;
		else
			r = mid;
		if(v[n][mid].x == x)
			return v[n][mid].y;
	}
	return v[n][l].y + (x - v[n][l].x) * (v[n][r].y - v[n][l].y) / (v[n][r].x - v[n][l].x);
}

bool cmp(int a, int b)
{
	return vl[a] < vl[b];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> A >> B;
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		vector<point> nv;
		int l;
		cin >> l;
		for(int j = 0; j <= l; j++)
		{
			point p0;
			cin >> p0.x >> p0.y;
			nv.push_back(p0);
		}
		v.push_back(nv);
	}
	/*
	for(int i = 0; i < 500; i++)
	{
		double x0 = 0.01 * i;
		cout << x0 << " " << y(x0, 0) << endl;
	}*/
	bool good = 1;
	int a, b;
	vector<int> templ;
	for(int i = 0; i < N; i++)
	{
		templ.push_back(i);
		vl.push_back(0);
	}
	for(int k = 0; k < 100; k++)
	{
		srand(1543);
	
		double curX = (double)(k) * 0.1 * (B - A) + A + 0.00000001;//(double)(rand()%10000) * 0.0001 * (B - A) + A;
		for(int i = 0; i < N; i++)
		{
			vl[i] = y(curX, i);
		}
		sort(templ.begin(), templ.end(), cmp);

		vector<double> vlOld = vl;

		vector<int> curS, prevS;
		prevS = curS = templ;
	
		for(int j = 1; j < 100; j++)
		{
			curX = (double)(j) * 0.01 * (B - A) + A + 0.00000001;
			if(curX >= B)
				break;
			for(int i = 0; i < N; i++)
			{
				vl[i] = y(curX, i);
			}
			for(int i = 0; i < N; i++)
				for(int j = i + 1; j < N; j++)
				{
					if((vl[i] > vl[j] && vlOld[i] < vlOld[j]) ||
						(vl[i] < vl[j] && vlOld[i] > vlOld[j]))
					{
						a = i;
						b = j;
						good = 0;
						break;
					}
				}
			if(good == 0)
				break;
		}
		if(good == 0)
			break;
	}


	if(good)
		cout << "Yes" << endl;
	else
	{
		a++;
		b++;
		cout << "No" << endl;
		cout << a << " " << b << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}