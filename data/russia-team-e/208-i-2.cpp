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
		a[i] = x - d;
		b[i] = x - 2*d;
		if ( b[i] > 0) sum = sum + b[i];
	}

	long long m = 0;
	long long s = 0;
	for (int i = 0; i < n; ++i)
	{
		s = 0;
		if ( a[i] > 0 )
		{
			for (int j = i+1; j < n; ++j)
			{
				if (a[j] > 0 ) 
				{
					s = sum;
					if ( b[i] > 0) s = s - b[i];
					if ( b[j] > 0) s = s - b[j];
					s = s + a[i] + a[j];
				}
			}		
		}
		if ( s > m) m = s;
	}


	cout << m;
	return 0;
}