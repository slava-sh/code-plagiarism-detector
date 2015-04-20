#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

long long nod(long long a, long long b) 
{
	if(a == 0 || b == 0) {
		return a + b;
	} else if (a <= b) {
		return nod(b % a, a);
	} else {
		return nod(a % b, b);
	}
}	



int main()
{
	freopen("gcm.in", "r", stdin);
	freopen("gcm.out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	int r;
	r = rand();
	
	if(r % 2 == 0){
	long long w = nod(a, b);
	
	for (long long i = 0; i <= 10000000; i++) {
		if (i * i >= 4  * a * b) {
			double x = sqrt(i * i - 4 * a * b);
			if (x == int(x) && int(i - x) % 2 == 0 && (nod((i - x) / 2, (i - x) / 2 + x) == w)) {
				cout << int(i - x) / 2 << " " << int(i - x) / 2 + int(x) << endl;
				return 0;
			}
		}
	}
	cout << min(a, b) << " " << max(a, b) << endl;	
	}

	else
	{
		long long y = nod(a, b), x = (a / y) * b, resx = x, resy = y;
	if ((fabs(a - b) == 1 && y == 1) || y == 0) {
		cout << min(a, b) << " " << max(b, a) << endl;
		return 0;
	}
	for(long long j = min(a, b) / y; j <= sqrt(x); j++) {
			if (x % j == 0 && (x / j) % j != 0) {
				if (x / j < y * j) {
					printf("%I64d %I64d\n", resy, resx);
					return 0;
				}
				if (x / j - y * j < resx - resy && nod(x / j , y * j) == y) {
					resx = x / j;
					resy = y * j;
				}
			}
	}	                     
	printf("%I64d %I64d\n", resy, resx);


}
return 0;
}
 