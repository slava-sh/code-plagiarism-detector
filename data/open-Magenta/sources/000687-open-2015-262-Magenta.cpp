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

	for (int i = 0; i < 100000; i++)
	{
		if (i & 1)
			printf("D);
		else
			printf("R");
		fflush(stdout);
		cin >> c;
		if (c == "Y" || c == "E") return 0;
	}

	for (int i = 0; i < 100000; i++)
	{
		if (i % 3 == 0)
			printf("D");
		else
			printf("R");
		fflush(stdout);
		cin >> c;
		if (c == "Y" || c == "E") return 0;
	}

	return 0;
}