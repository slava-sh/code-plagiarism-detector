#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
	ifstream fin("game.in");
	ofstream fout("game.out");
	int n, m, l1, r1, l2, r2, t = 0, w1 = 0, w2 = 0;
	bool d;
	fin >> n >> m >> l1 >> r1 >> l2 >> r2;
	vector<int> s(n);
	for (int i = 0; i < n; i++)
	{
		fin >> s[i];
	}
	int c = 0, v1 = 0, v2 = 0;/*
	sort(s.begin(), s.end());*/
	if (r1 >= l2){
		int ml = max(l1, l2);
		int mr = min(r1, r2);
		for (int i = 0; i < n; i++)
		{
			if (s[i] >= ml && s[i] <= mr)
				c++;

		}
		c = min(c, m);
		m -= c;
	}
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= l1 && s[i] <= r1)
			v1++;

	}
	v1 -= c;
	v1 = min(v1, m / 2 + m % 2);
	m -= v1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] >= l2 && s[i] <= r2)
			v2++;

	}
	v2 -= c;
	v2 = min(v2, m);
	if (c % 2 == 0)
		if (v1 == v2)
			fout << "Draw";
		else
			if (v1 > v2)
				fout << "Petya";
			else
				fout << "Vasya";
	else
		if (v1+1 == v2 )
			fout << "Draw";
		else
			if (v1+1 > v2)
				fout << "Petya";
			else
				fout << "Vasya";


	fout.close();
	return 0;
}