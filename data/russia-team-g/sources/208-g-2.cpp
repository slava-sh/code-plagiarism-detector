//#include <iostream>
#include <fstream>

using namespace std;

long long n,m;
int main()
{
	ifstream cin ("prizes.in");
	ofstream cout ("prizes.out");

	cin >> n >> m;
	if ( n % 2 == 0)
	{
	 if (m >=2) cout << 0; else
		 cout << n / 4;
	}

	else
	{

		if ( n == 1) cout << m / 3; else
	if ( m >=2)  cout << 1; else 
	{
		if ( n % 4 == 0 ) cout << n / 4  ; else cout << n / 4 + 1;
	}
	}
	

	return 0;
}