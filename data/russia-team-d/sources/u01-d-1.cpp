#include <iostream>

using namespace std;

int main() 
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);

	int n;
	cin>>n;

	int k;
	cin>>k;

	__int64 sum = 0;

	int m;

	int min = 1000000000;

	for (int i = 0; i < n; i++) 
	{
		cin>>m;
		if (sum <= k) sum += m;
		if (min > m) min = m; 
	}

	if (sum <= k) cout<<min;
	else 
	{
		if (min >= k/n) cout<<k/n;
		else cout<<min;
	}


	return 0;

}