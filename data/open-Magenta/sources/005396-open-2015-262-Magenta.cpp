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

	string input;
	string d[] = { "D", "R" };

	int x = 2;
	for (int i = 0; i <= 200000; i++)
	{
		cout << d[(i % x) > 0] << endl;
		if (i % x == 0) x++;
		cout.flush();
		cin >> input;
		if (input == "Y" || input == "E") return 0;
	}

	return 0;
}