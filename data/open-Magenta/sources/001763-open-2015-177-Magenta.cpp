#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 200500;
typedef long long ll;
const ll INF = 1e18;

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);
	char h;
	while (true)
	{
		for (int i = 0; i < 25; i++)
		{
			cout << "U\n";
			fflush(stdout);
			cin >> h;
			if (h == 'Y' || h == 'E')
				return 0;
		}
		cout << "R\n";
		fflush(stdout);
		cin >> h;
		if (h == 'Y' || h == 'E')
			return 0;
	}
	return 0;
}