#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

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
	long long y = nod(a, b), x = (a / y) * b, resx = x, resy = y;
	for(long long j = 2; j <= x / y + 5; j++) {
			if (x % j == 0 && (x / j) % j != 0) {
				if (x / j < y * j) {
					cout << resy << " " << resx  << endl;
					return 0;
				}
				if (x / j - y * j < resx - resy && nod(x / j , y * j) == y) {
					resx = x / j;
					resy = y * j;
				}
			}
	}	                     
	cout << resx << " " << resy << endl; 
return 0;
}
