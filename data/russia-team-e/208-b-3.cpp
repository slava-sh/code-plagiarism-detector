//#include <iostream>
#include <fstream>
using namespace std;

long long a[300000];
int main()
{
	ifstream cin("che.in");
	ofstream cout("che.out");
	long long n,r;
	long long pr=1;
	long long sm=0;

	cin >> n >> r;

	for (int i=0; i<n; ++i) cin >> a[i];

	for (int j=0; a[j]+r<a[n-1] && j<n; ++j)
	{
		long long i=pr;
		for (; a[j]+r>=a[i] && i<n; ++i);
		pr=i;
		sm+=n-pr;
	}
	cout << sm << endl;
	return 0;
}