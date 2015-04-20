#include <fstream>

using namespace std;

int Compare(const void * a, const void *b)
{
	int x = *(int *)a, y = *(int *)b;
	return x - y;
}

int arr[100000];
long long arr2[100000];

int main()
{
	ifstream fin("merlin.in");
	ofstream fout("merlin.out");
	int n, i;
	long long v;
	fin >> n;
	for (i = 0; i < n; i++)
		fin >> arr[i];
	qsort(arr, n, sizeof(int), Compare);
	arr2[n - 1] = arr[n - 1];
	for (i = n - 2; i >= 0; i--)
		arr2[i] = arr2[i + 1] + arr[i];
	v = 0;
	for (i = 1; i < n; i++)
	{
		v = v + i * (arr[i] - arr[i - 1]);
		if (v >= arr2[i + 1])
			break;
	}
	fout << n - i;
	return 0;
}