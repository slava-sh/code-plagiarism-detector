#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#define problem "abcd"
#define ll long long
using namespace std;
ll n, y, z, c;
char a[11];
int main()
{
	ifstream cin (problem".in");
	ofstream cout (problem".out");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			cin >> a[j];
		y = (a[0] - '0') * 10;
		y += (a[1] - '0');
		
		z = (a[2] - '0') * 10;
		z += (a[3] - '0');
	//	cout << y << " " << z << "\n";
		c = y * y + z * z;
		if ((c % 7) == 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
