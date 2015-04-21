#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int x = 1, y = 1;
void pt(char c)
{
	cout << c << endl;
	if (c == 'U') y++;
	else if (c == 'D') y--;
	else if (c == 'R') x++;
	else x--;
	cout.flush();
	char x;
	cin >> x;
	//x = 'N';
	if (x == 'Y') exit(0);
}


const int MAXN = 18000;
int a[MAXN];
int b[MAXN];

int main()
{
	pt('U');
	int sz = 1;
	for (int i = 0; i < MAXN; i++) a[i] = 0;
	a[1] = 1;
	while (true)
	{
		sz *= 2;
		for (int i = 1; i <= sz; i++)
		{
			if (i == 1) b[i] = sz;
			else
			{
				pt('U');
				b[i] = b[i - 1];
				if (i * (b[i] / 2) >= sz) b[i] /= 2;
			}
			if (x < b[i])
			{
				while (x != b[i]) pt('R');
			}
			else
			{
				while (x - 1 > a[i]) pt('L');
			}
		}
		for (int i = 1; i <= sz; i++)
		{
			if (i != 1)
			{
				pt('R');
				pt('D');
			}
			a[i] = b[i];
		}
	}
	return 0;
}