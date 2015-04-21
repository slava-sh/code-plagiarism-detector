//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l;
	cin >> l;
	string s;
	cin >> s;
	if((int)s.size() <= l)
	{
		cout << 1 << endl;
		cout << s << endl;
	}
	else
	{
		cout << 2 << endl;
		cout << "a" << endl;
		cout << "b" << endl;
	}



	return 0;
}