#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

void pt(char c)
{
	cout << c << endl;
	cout.flush();
	char x;
	cin >> x;
	if (x == 'Y') exit(0);
}

void go(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		if (i != 0) pt('U');
		for (int j = 0; j + 1 < m; j++) pt('R');
	}
}

const int MAXN = 18000;
int main()
{
	for (int sp = 1; sp < MAXN; sp *= 3)
	{
		for (int i = 1; i <= sp; i *= 3)
		{
			go(i, sp / i);
		}
	}
	return 0;
}