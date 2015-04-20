//#include <iostream>
#include <fstream>
using namespace std;
ifstream cin("prizes.in");
ofstream cout("prizes.out");

int main()
{
	long long n,m;
	cin >> n >> m;
	if (n>m) swap(n,m);
	if (n==1)  cout << m/4 << endl;
	else if (n==2)
	{
		if (m>=3) cout << 1 ;
		else cout << 0;
		cout << endl;
	}
	else if (n>=3) cout << 1 << endl;

}