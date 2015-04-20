#include <fstream>

//#include <iostream>
#include <algorithm>
using namespace std;
ifstream cin("sochi.in");
ofstream cout("sochi.out");


int a[100000],k, d;
long long sm,n;
int main()
{
	cin >> n >> d;
	for (long long i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n);
	for (long long i=n-1; i>=0; --i)
	{
		if (a[i]>=3*d) sm+=a[i]-2*d;
		else if (a[i]>=2*d) {k++; sm+=a[i]-d;}
	}
	if (k==0) sm+=2*d;
	if (k==1) sm+=d;
	cout << sm << endl;
}