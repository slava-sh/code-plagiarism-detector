#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#pragma comment(linker, "/STACK:100000000")
using namespace std;

const int MAXINT = 1000000010;
const long long MAXLL = 2e18;
const long long MODUL = 1000000007;



template <typename T>
inline T MIN(T a, T b)
{
	return (a < b ? a : b);
}

int main()
{
	int n, m, cou(1), mas[100000], x, y;
	cin >> n;
	for(int i(0); i < n; ++i)
		cin >> mas[i];
	for(int i(1); i < n; ++i)
		cou += (mas[i] != mas[i - 1]);
	cin >> m;
	if(n == 1)
	{
		for(int i(0); i < m; ++i)
			cout << 1 << endl;
		return 0;
	}
	for(int i(0); i < m; ++i)
	{
		cin >> x >> y;
		--x;
		if(mas[x] != y)
		{
			if(x == 0)
			{
				if(mas[x + 1] == y)
					--cou;
				else if(mas[x + 1] == mas[x])
					++cou;
			}
			else if(x == n - 1)
			{
				if(mas[x - 1] == y)
					--cou;
				else if(mas[x] == mas[x - 1])
					++cou;
			}
			else
			{
				if(mas[x - 1] == mas[x + 1])
				{
					if(mas[x - 1] == y)
						cou -= 2;
					else if(mas[x - 1] == mas[x])
						cou += 2;
				}
				else
				{
					if(mas[x] == mas[x - 1] && y != mas[x + 1])
						++cou;
					if(mas[x] == mas[x + 1] && y != mas[x - 1])
						++cou;
					if(mas[x] != mas[x + 1] && mas[x] != mas[x - 1] && (y == mas[x + 1] || y == mas[x - 1]))
						--cou;
				}
			}
		}
		mas[x] = y;
		cout << cou << endl;
	}
	return 0;
}














