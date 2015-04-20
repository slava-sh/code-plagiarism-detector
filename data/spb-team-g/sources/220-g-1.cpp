/* team 220.  */

#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define SHOWAR(Ar, N) \
  for (int i = 0; i < N; i++) \
    std::cout << Ar[i] << " ";

struct vec
{
  double x, y, z;
};

typedef long long LL;


int main()
{
	freopen("merlin.in", "r", stdin);
	freopen("merlin.out", "w", stdout);

	int n;
	cin >> n;

	LL sum = 0;
	vector<long> Ar(n);

	for (int i = 0; i < n; i++)
	{
		cin >> Ar[i];
		sum += Ar[i];
	}

	sort(Ar.begin(), Ar.end());

	for (int i = 0; i < n; i++)
	{
		if (sum / (n - i) >= Ar[n - i - 1])
		{
			std::cout << i << endl;
			exit(0);
		}
	}
}

int _main()
{
  freopen("merlin.in", "r", stdin);
  freopen("merlin.out", "w", stdout);

  int n;
  cin >> n;

  vector<long> Ar(n);

  LL sum = 0, sumn = 0;

  for (int i = 0; i < n; i++)
  {
	  cin >> Ar[i];
	  sum += Ar[i];
  }

  double sumt = 0;

  sort(Ar.begin(), Ar.end());

  for (int i = 0; i < n; i++)
  {
	if (Ar[n - 1] < sum / (n - i) &&
	   sumn >= sumt)
	{
		std::cout << i; 
		exit(0);
	}

	if (i != n - 1)
		sumt = sumt * (n - i) / (n - i - 1) + (2 * sum - sumn) / (n - i - 1) - Ar[n - i - 2];
	else
	{
		std::cout << i;
		exit(0);
	}

	sumn += Ar[n - i - 2];
  }
	// SHOWAR(Ar, 10);
  return 0;
}