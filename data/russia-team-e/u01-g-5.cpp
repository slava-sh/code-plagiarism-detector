#include <iostream>

using namespace std;


int max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

int min(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int main() 
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);

	int n, m;
	cin>>n>>m;

	int count = 0;

	int mmin = min(n,m), mmax = max(n,m);

	if (mmin == 1)
	{
		if (mmax >= 3) count += (mmax-3)/4 + 1; 
	}
	else if (mmin > 2)
	{
		count += (mmin-3)/4 + 1;
	}

	cout<<count;

	return 0;

}