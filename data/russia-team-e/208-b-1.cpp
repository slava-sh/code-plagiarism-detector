//#include <iostream>
#include <fstream>
using namespace std;

int a[300000];
int main()
{
	ifstream cin("che.in");
	ofstream cout("che.out");
	int n,r;

	int sm=0;

	cin >> n >> r;

	for (int i=0; i<n; ++i) cin >> a[i];

	for (int j=0; a[j]+r<a[n-1] && j<n; ++j)
	{
		int i=j+1;
		for (; a[j]+r>=a[i]; ++i);
		++i;
		sm+=n-i+1;
	}
	cout << sm << endl;
	return 0;
}