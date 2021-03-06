#include <stdio.h>
#include <cmath>
#include <conio.h>

using namespace std;

long long gcd(long long a, long long b)
{
	long long t;
	while (b > 0)
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main(){
	long long a, b, gd, gm, k, x = 1, y;
	freopen("gcm.in", "r", stdin);
	freopen("gcm.out", "w", stdout);
	scanf("%I64d%I64d", &a, &b);
	if (a > b)
	{
		int l = a;
		a = b;
		b = l;
	}
	gd = gcd(a, b);
	gm = (b / gd)*a;
	k = gm / gd;
	x = long long(sqrt(k));
	while (x > a/gd && (k % x != 0 || gcd(x, k / x) != 1))
		x--;
	printf("%I64d %I64d", x*gd, (k / x)*gd);
	
//	_getch();
	return 0;
}