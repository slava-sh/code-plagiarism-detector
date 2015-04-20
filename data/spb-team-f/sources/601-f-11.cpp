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


	/*
	for (long long i = 0; i < fabs(a - b); i++) {
		double x = sqrt(i * i + 4.0 * a * b);
		if(x == int(x)) {
			if(int(x - i) % 2 == 0 && nod((x - i) / 2, (x - i) / 2 + i) == w) {
				cout << int((x - i) / 2) << " " << int(2 * a * b / (x - i)) << endl;
				return 0;
			}
		}
	} */
	cout << min(a, b) << " " << max(a, b) << endl;	
return 0;
}
 