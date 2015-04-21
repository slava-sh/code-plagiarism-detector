#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define ll long long
#define ss second
#define ff first

const ll maxn = 6001;
const ll maxseg = 131072;
const ll inf = 4611686018427387904;
const double pi = 3.141592653589793238462643383279502884;
const double eps = 1e-9;
const double inff = 1e100;
char x;

void up()
{
	cout << 'U' << '/n';
	cout.flush();
	cin >> x;
	if ((x == 'Y') || (x == 'E'))
		exit(0);
}

void right()
{
	cout << 'R' << '/n';
	cout.flush();
	cin >> x;
	if ((x == 'Y') || (x == 'E'))
		exit(0);
}

void left()
{
	cout << 'L' << '/n';
	cout.flush();
	cin >> x;
	if ((x == 'Y') || (x == 'E'))
		exit(0);
}

void down()
{
	cout << 'D' << '/n';
	cout.flush();
	cin >> x;
	if ((x == 'Y') || (x == 'E'))
		exit(0);
}

int main()
{
	cin.sync_with_stdio(0);
	ll cur = 0;
	ll j;
	for (int i = 1; i <= maxn; ++i)
	{
		j = maxn / i + (bool)(maxn % i) + 1;
		for (; j >= 0; --j)
			up();
		right();
	}
	for (int i = 1; i <= maxn; ++i)
		left();
	for (int i = 1; i <= maxn; ++i)
	{
		j = maxn / i + (bool)(maxn % i) + 1;
		for (; j >= 0; --j)
			up();
		left();
	}
	return 0;
}