#include <fstream>

using namespace std;

long long arr[2000001];
long long arr2[2000001];

long long Min(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	ifstream fin("seq.in");
	ofstream fout("seq.out");
	long long MaxS = 1e18;
	long long n, h, i, x;
	fin >> n >> h;
	for (i = 1; i <= n; i++)
	{
		fin >> x;
		arr[i] = i - x;
	}
	arr2[1] = arr[1];
	for (i = 2; i <= n; i++)
		arr2[i] = arr2[i - 1] + arr[i];
	for (i = 0; i + h <= n; i++)
	{
		if (arr[i + h] - i < 0)
			i += h;
		else
			MaxS = Min(arr2[i + h] - arr2[i] - h * i, MaxS);
	}
	if (MaxS == 1e18)
		fout << -1;
	else
		fout << MaxS;
	return 0;
}