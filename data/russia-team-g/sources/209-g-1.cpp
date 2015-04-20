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
	cout << (min(n, m) + 1) / 4;
	return 0;
}