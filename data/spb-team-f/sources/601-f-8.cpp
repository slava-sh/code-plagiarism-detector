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
	if (fabs(b - a) > int(1e6)) {
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
	} else {
	long long w = nod(a, b);
	for (long long i = 0; i <= fabs(a - b); i++) {
		double x = sqrt(i * i + 4.0 * a * b);
		if(x == int(x)) {
			if(int(x - i) % 2 == 0 && nod((x - i) / 2, (x - i) / 2 + i) == w) {
				cout << int((x - i) / 2) << " " << int(2 * a * b / (x - i)) << endl;
				return 0;
			}
		}
	} 
	cout << min(a, b) << " " << max(a, b) << endl;
}	
return 0;
}
 