#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main()
{
	ifstream cin("fence.in");
	ofstream cout("fence.out");
	int n, k;
	cin >> n >> k;
	vec.resize(n);
	for ( int i = 0; i < n; ++i )
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	int L = 0, R = vec[0] + 1;
	while ( R - L > 1 )
	{
		int m = (L + R) / 2;
		
		int temp = 0;
		for ( int i = 0; i < n; ++i )
		{
			temp += max(vec[i] - temp, m);
		}
		
		if ( temp <= k )
		{
			L = m;
		}
		else
		{
			R = m;
		}
	}
	cout << L;
	return 0;
}