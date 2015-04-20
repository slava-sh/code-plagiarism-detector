#include <fstream> 

using namespace std;

int Compare(const void * a, const void *b)
{
	long long x = *(long long *)a, y = *(long long *)b;
	return x - y;
}

long long arr[100001];
long long arr2[100001];

int main()
{
	ifstream fin("merlin.in");
	ofstream fout("merlin.out");
	long long n, i;
	long long v;
	fin >> n;
	for (i = 0; i < n; i++)
		fin >> arr[i];
	qsort(arr, n, sizeof(long long), Compare);
	arr2[n - 1] = arr[n - 1];
	for (i = n - 2; i >= 0; i--)
		arr2[i] = arr2[i + 1] + arr[i];
	v = 0;
	for (i = 1; i < n; i++)
	{
		v = v + i * (arr[i] - arr[i - 1]);
		if (v > arr2[i + 1])
			break;
	}
	fout << n - i;
	return 0;
}