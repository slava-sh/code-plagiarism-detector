//#include "stdafx.h"
//#pragma comment(linker, "/STACK:67108864")
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <string>
#include <memory.h>

using namespace std;

int main()
{
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int l;
	string s;
	bool a = false, b = false, c = false;

	cin >> l >> s;
	int n = s.length();

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'a')
			a = true;
		else if (s[i] == 'b')
			b = true;
		else if (s[i] == 'c')
			c = true;
	}

	int count = 0;
	if (a) count++;
	if (b) count++;
	if (c) count++;

	if (n <= l)
	{
		cout << "1\n";
		cout << s;
		return 0;
	}

	if (count <= 1)
	{
		cout << "1\n";
		if (a) cout << 'a';
		if (b) cout << 'b';
		if (c) cout << 'c';
		return 0;
	}

	if (n <= l * 2)
	{
		cout << "2\n";
		cout << s.substr(0, l) << '\n';
		cout << s.substr(l, n - l);
		return 0;
	}

	if (count == 2)
	{
		cout << "2\n";
		if (a) cout << "a\n";
		if (b) cout << "b\n";
		if (c) cout << "c\n";
		return 0;
	}

	cout << "3\na\nb\nc";

	return 0;
}