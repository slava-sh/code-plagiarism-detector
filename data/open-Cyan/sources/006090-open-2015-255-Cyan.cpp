#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

#define lint long long int
#define C 50.0
#define D (1.0 / C)

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

	set<double> coord0;
	vector<double> goodpos0, goodpos;

	for(int i = 0; i < N; i++)
	{
		vector<point> nv;
		int l;
		cin >> l;
		for(int j = 0; j <= l; j++)
		{
			point p0;
			cin >> p0.x >> p0.y;
			coord0.insert(p0.x);
			nv.push_back(p0);
		}
		v.push_back(nv);
	}
	vector<double> coord;
	for(set<double>::iterator it = coord0.begin(); it != coord0.end(); it++)
	{
		coord.push_back(*it);
	}
	//sort(coord.begin(), coord.end());
	for(int i = 0; i < coord.size() - 1; i++)
	{
		goodpos.push_back(coord[i] + 0.000000001);
		goodpos.push_back((coord[i + 1] + coord[i]) * 0.5 + 0.000000000001);
	}
	goodpos0.push_back(coord.back() + 0.000000001);
	sort(goodpos.begin(), goodpos.end());
	/*for(int i = 0; i < goodpos0.size() - 1; i++)
	{
		
		goodpos.push_back(goodpos0[i]);
		goodpos.push_back((goodpos0[i + 1] + goodpos0[i]) * 0.5 + 0.000000000001);
	}*/
	/*
	for(int i = 0; i < 100; i++)
	{
		double x0 = (double)i * 0.01 * (B - A) + A;
		goodpos.push_back(x0);
	}*/


	sort(goodpos.begin(), goodpos.end());
	
	bool good = 1;
	int a, b;
	vector<int> templ;
	for(int i = 0; i < N; i++)
	{
		templ.push_back(i);
		vl.push_back(0);
	}
	int c = goodpos.size();
	for(int k = 0; k < c; k++)
	{
		srand(1543);
	
		double curX = goodpos[k];//(double)(k) * D * (B - A) + A + 0.00000001;//(double)(rand()%10000) * 0.0001 * (B - A) + A;
		for(int i = 0; i < N; i++)
		{
			vl[i] = y(curX, i);
		}
		sort(templ.begin(), templ.end(), cmp);

		vector<double> vlOld = vl;

		vector<int> curS, prevS;
		prevS = curS = templ;
	
		for(int j = 0; j < c; j++)
		{
			double curX0 = goodpos[j];//(double)(j) * D * (B - A) + A + 0.00000001;
			if(curX0 >= B)
				break;
			for(int i = 0; i < N; i++)
			{
				vl[i] = y(curX0, i);
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



	/*
	for(int k = 0; k < C; k++)
	{
		//srand(1543);
	
		double curX = (double)(k) * D * (B - A) + A + 0.00000001;//(double)(rand()%10000) * 0.0001 * (B - A) + A;
		for(int i = 0; i < N; i++)
		{
			vl[i] = y(curX, i);
		}
		sort(templ.begin(), templ.end(), cmp);

		vector<double> vlOld = vl;

		vector<int> curS, prevS;
		prevS = curS = templ;
	
		for(int j = k + 1; j < C; j++)
		{
			curX = (double)(j) * D * (B - A) + A + 0.00000001;
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
		*/

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