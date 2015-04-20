
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	__int64 a = 1000000000;
	int b;
	cin >> a;
	cout << (int)round(a / 2.0) << endl;
	cout.flush();
	cin >> b;
	while (b != 0)
	{
		if (b == 1)
		{
			a = a + (int)round(a / 2.0);
		}
		if (b == -1)
		{
			a = a - (int)round(a / 2.0);
		}
		cout << a << endl;
		fflush(stdout);
		cin >> b;
	}
	return 0;
}