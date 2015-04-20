//#include <iostream>
#include <fstream>

using namespace std;

long long n,m;
int main()
{
	ifstream cin ("prizes.in");
	ofstream cout ("prizes.out");
	
	cin >> n >> m;
long long n1 = 0, m1 = 0;
if ( n == 1) n1 = 1000000000; else
{
	if ( (n+1) % 4 == 0) n1 = n / 4 +1; else n1 = n / 4;
}

if ( m == 1) m1 = 1000000000; else
{
	if ( (m+1) % 4 == 0) m1 = m1 / 4 + 1; else m1 = m1 / 4;
}
if ( n1 > m1 ) cout << m1; else cout << n1;
	

	return 0;
}