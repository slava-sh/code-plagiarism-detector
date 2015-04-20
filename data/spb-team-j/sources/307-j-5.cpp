#include <fstream>

using namespace std;

long long arr[2000001];
long long arr2[2000001];

long long Min(long long a, long long b)
{
	return a < b ? a : b;
}

long long Max(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	ifstream fin("seq.in");
	ofstream fout("seq.out");
	long long MaxS = -1;
	long long n, h, i, x;
	long long BAD = 0;
	bool fl = 0;
	fin >> n >> h;
	for (i = 1; i <= n; i++)
	{
		fin >> x;
		arr[i] = i - x;
	}
	arr2[1] = arr[1];
	for (i = 2; i <= n; i++)
		arr2[i] = arr[i] + arr2[i - 1];
	for (i = 1; i < h; i++)
		if (arr[i] < 0)
			BAD = i + 1;
	for (i = 0; i + h <= n; i++)
	{
		if (arr[i + h] - i < 0)
			BAD = h;
		else if (BAD > 0)
			BAD--;
		if (BAD == 0 || fl == 0)
		{
			MaxS = Min(arr2[i + h] - arr2[i] - h * i, MaxS);
			fl = 1;
		}
	}
		fout << MaxS;
	return 0;
}