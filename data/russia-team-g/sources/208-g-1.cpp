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
		cout << n / 4;
	}

	else
	{
		if ( n == 1) cout << m / 3; else
			cout << n / 4 +1;
	}

	return 0;
}