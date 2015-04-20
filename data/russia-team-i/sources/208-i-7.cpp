//#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");
bool f(int a, int b) {return a>b;}
int a[100000],n,d;
int main()
{
	vector<int> b;
	vector<int> c;
	b.reserve(100000);
	c.reserve(100000);
	cin >> n >> d;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n,f);
	for (int i=0; i<n; ++i)
	{
		if (a[i]>=3*d) b.push_back(a[i]);
		else if(a[i]>=2*d) c.push_back(a[i]);
		else break;
	}
	if (c.size()>=1)
	{
		sort(c.begin(), c.end());
		if (c.size()>=1) b.push_back(c[0]);
		if (c.size()>=2) b.push_back(c[1]);
	}

	int k=b.size()-1;
	long long sm=0;
	for (int i=0; i<b.size(); ++i)
		sm+=b[i];
	if (b.size()==0) cout << a[0] << endl;
	else	cout << sm-2*k*d << endl;
	
		return 0;
	}