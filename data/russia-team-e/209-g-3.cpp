#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;

int main()
{
	ifstream cin("prizes.in");
	ofstream cout("prizes.out");

	int n, m;
	cin >> n >> m;
	if ( min(m,n) == 1 )
		cout << (max(n, m) + 1) / 4;
	else
	if ( min(n, m) == 2 )
		cout << 0;
	else
		cout << 1;
	return 0;
}