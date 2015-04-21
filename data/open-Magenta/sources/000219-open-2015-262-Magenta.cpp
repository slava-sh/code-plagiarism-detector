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

	char c;

	for (int i = 0; i <= 200000; i++)
	{
		if (i & 1)
			cout << "D\n";
		else
			cout << "R\n";
		fflush(stdout);
		cin >> c;
		if (c == 'Y' || c == 'E') return 0;
	}

	return 0;
}