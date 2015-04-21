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
	int cnta = 0;
	int cntb = 0;
	for(int i = 0; i < (int)s.size(); i++)
	{
		if(s[i] == 'a')
		{
			cnta++;
		}
		else
		{
			cntb++;
		}
	}
	if((int)s.size() <= l)
	{
		cout << 1 << endl;
		cout << s << endl;
		return -1;
	}
	else
	{
		if(cnta && cntb)
		{
			cout << 2 << endl;
			cout << "a" << endl;
			cout << "b" << endl;
			return 0;
		}
		if(cnta)
		{
			cout << 1 << endl;
			cout << "a" << endl;
		}
		else
		{
			cout << 1 << endl;
			cout << "b" << endl;
		}
	}



	return 0;
}