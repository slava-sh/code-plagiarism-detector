#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <vector>
using namespace std;

vector <long long> dn;
vector <long long> dm;

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
	long long a, b, gd, gm, k, x = 1, n, m;
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
	n = a / gd;
	m = b / gd;
	k = n*m;
	for (int i = 1; i*i <= n; i++)
		if (n % i == 0 && gcd(i, n / i) == 1)
		{
			dn.push_back(i);
			dn.push_back(n / i);
		}

	for (int i = 1; i*i <= m; i++)
		if (m % i == 0 && gcd(i, m / i) == 1)
		{
			dm.push_back(i);
			dm.push_back(m / i);
		}

	int mini = 0; 
	int minj = 0;
	for (int i = 0; i < int(dn.size()); i++)
		for (int j = 0; j < int(dm.size()); j++)
			if (abs(dn[i] * dm[j] - (n / dn[i])*(m / dm[j])) < abs(dn[mini] * dm[minj] - (n / dn[mini])*(m / dm[minj])))
			{
				mini = i;
				minj = j;
			}
	x = dn[mini] * dm[minj];
	if (x*x > k)
		x = k / x;
	printf("%I64d %I64d", x*gd, (k / x)*gd);
	
//	_getch();
	return 0;
}