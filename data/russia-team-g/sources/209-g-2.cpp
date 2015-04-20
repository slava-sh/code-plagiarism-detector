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
	if ( min(n, m) <= 2 )
		cout << 0;
	else
		cout << 1;
	return 0;
}