//#include <iostream>
#include <fstream>
using namespace std;

long long a[10000000];
long long b[10000000];
long long x, n,d;
int main()


{

	ifstream cin ("sochi.in");
	ofstream cout("sochi.out");
	cin >> n >> d;

	long long sum  = 0;
	for (int i = 0; i <n; ++i)
	{
		cin >> x;
		a[i] = x - 2*d;
		b[i] = x - d;
		if ( a[i] >= d) sum = sum + a[i];
	}
	if ( n == 1) cout << x; else

	{
		long long m = 0;
		long long s = 0;
		for (int i = 0; i < n; ++i)
		{
			s = 0;
			if ( b[i] >= d) 
			{

				for (int j = i+1 ; j < n; ++j)
				{
					if (b[j] >= d)
					{
						s = sum;
						if (a[i] >= d) s = s - a[i];
						if (a[j] >= d) s = s - a[j];
						s = s + b[i] + b[j];
					}

				}
			}
			if ( s > m) m = s;

		}


		cout << m;
	}
	return 0;
}