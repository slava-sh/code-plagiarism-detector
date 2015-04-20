#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LL long long
#define LD long double
#define SIZE 500000
#define FILENAME "sochi"

using namespace std;

LL n, i, r, a[SIZE], ans, l, d, length, j;

int main() {
	freopen(FILENAME".in", "r", stdin);
	freopen(FILENAME".out", "w", stdout);
	cin >> n >> d;
	for (i = 0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	length = 0; l = n-1; r = n-1;
	for (i=n-1; i>=0; i--)
	{
		if (i == n-1){
			length += a[i];
			if (a[i] <= 2*d)
				break;
			continue;
		}
		if ((a[l] >=2*d)&&(a[i] > 2*d))
		{
			
			a[l] -=d;
			l = i;
			length += a[i] - 2*d;
			a[l] -=d;
			
//			cerr << i <<" l  + " << a[l] + d << " = " << length << endl;
			continue;	
		}
		if ((a[r] >= 2*d)&&(a[i] > 2*d))
		{
			a[r] -=d;
			r = i;
			length += a[i] - 2*d;
			a[r] -=d;
//			cerr << i <<" r +  " << a[r] + d << " = " << length << endl;
			continue;
		}
//		for (j = 0; j<n; j++)
 //			cerr << a[j] << " ";
//		cerr << endl;
	}
	cout << length;
	return 0;
}
