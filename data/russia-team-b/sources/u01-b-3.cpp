#include <iostream>

using namespace std;

int main() 
{
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);

	int n;
	cin>>n;

	int r;
	cin>>r;

	long int arr_state[30001];

	for (int i = 0; i < n; i++)
	{
		cin>>arr_state[i];
	}

	int count = 0;

	for (int i = 0; i < n-1; i++)
	{
		for (int j = i+1; j < n; j++) 
		{
			if (arr_state[i]+r < arr_state[j]) 
			{
				count += n-j;
				break;
			}
		}
	}
	

	cout<<count;

	return 0;

}