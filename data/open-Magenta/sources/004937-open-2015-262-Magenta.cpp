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
			cout << "D";
		else
			cout << "R";
		cout << endl;
		cout.flush();
		getline(cin, c);
		if (c == "Y" || c == "E") return 0;
	}

	for (int i = 0; i < 133335; i++)
	{
		if (i % 3 == 2)
			cout << "D";
		else
			cout << "R";
		cout << endl;
		cout.flush();
		getline(cin, c);
		if (c == "Y" || c == "E") return 0;
	}

	return 0;
}