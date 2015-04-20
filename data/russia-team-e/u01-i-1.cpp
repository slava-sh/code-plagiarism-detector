#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);

	int n;
	cin>>n;

	int d;
	cin>>d;

	int arr[100001];

	for (int i = 0; i < n; i++)
	{
		cin>>arr[i];
	}

	sort(arr, arr + n);

	int arr_sum[100001], arr_index = 0, max = 0;

	memset(arr_sum, 0, sizeof(arr_sum)/sizeof(arr_sum[0]));

	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			arr_sum[arr_index] += arr[j];
			
			
		}

		arr_sum[arr_index] = arr_sum[arr_index] - (n-i-1)*2*d;
		if (max < arr_sum[arr_index]) max = arr_sum[arr_index];

		arr_index++;

	}

	cout<<max;

	return 0;

}