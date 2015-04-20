#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> d2, d3;

int main()
{
	ifstream cin("sochi.in");
	ofstream cout("sochi.out");
	int n, d;
	cin >> n >> d;
	int x;
	long long temp = -1;
	for ( int i = 0; i < n; ++i )
	{
		cin >> x;
		if ( x > temp )
			temp = x;
		if ( x >= 2 * d && x < 3 * d )
			d2.push_back(x);
		if ( x >= 3 * d )
			d3.push_back(x);
	}
	if ( d2.size() + d3.size() < 2 )
	{
		cout << temp;
		return 0;
	}
	sort(d2.begin(), d2.end());
	sort(d3.begin(), d3.end());
	long long sum = 0;
	for ( int i = 0; i < d3.size(); ++i )
	{
		sum += d3[i] - 2 * d;
	}
	int f = min(2, (int)d2.size());
	for ( int i = 0; i < f; ++i )
		sum += d2[d2.size() - i - 1] - d;
	sum += d * (2 - f);
	cout << max(temp, sum);
	return 0;
}