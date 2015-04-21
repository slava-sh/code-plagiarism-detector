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

	char t, c;

	for (int i = 0; i < 100000; i++)
	{
		if (i & 1)
			printf("D\n");
		else
			printf("R\n");
		fflush(stdout);
		scanf("%c%c", &c, &t);
		if (c == 'Y' || c == 'E') return 0;
	}

	for (int i = 0; i < 100000; i++)
	{
		if (i % 3 == 0)
			printf("D\n");
		else
			printf("R\n");
		fflush(stdout);
		scanf("%c%c", &c, &t);
		if (c == 'Y' || c == 'E') return 0;
	}

	return 0;
}