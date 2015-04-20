#include <iostream>

using namespace std;

int main() 
{
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);

	int n,m;
	cin>>n>>m;

	int mmin = min(n,m), mmax = max(n,m);

	int count = 0;

	if (mmin == 1) 
	{
		count += (mmax-3) / 4+1;
	}
	else if (mmin > 2)
	{
		count++;
		count += (mmin-3) / 4;
	}

	

	cout<<count;

	return 0;

}