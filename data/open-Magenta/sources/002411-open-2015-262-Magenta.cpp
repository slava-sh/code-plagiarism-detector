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
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/

	string c;

	for (int i = 0; i < 66667; i++)
	{
		if (i % 2 == 1)
			cout << 'R';
		else
			cout << 'D';
		cout << endl;
		cout.flush();
		cin >> c;
		if (c[0] == 'Y' || c[0] == 'E') exit(0);
	}

	for (int i = 0; i < 200000; i++)
	{
		if (i % 3 == 2)
			cout << 'R';
		else
			cout << 'D';
		cout << endl;
		cout.flush();
		cin >> c;
		if (c[0] == 'Y' || c[0] == 'E') exit(0);
	}

	return 0;
}