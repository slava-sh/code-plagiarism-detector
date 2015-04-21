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
	}
	else
	{
		if(cnta && cntb)
		{
			for(int k = 1; k <= l; k++)
			{
				if((int)s.size() % k == 0)
				{
					bool f = true;
					for(int j = 0; j < (int)s.size() - k; j++)
					{
						if(s[j] != s[j + k])
						{
							f = false;
							break;
						}
					}
					if(f)
					{
						cout << 1 << endl;
						for(int j = 0; j < k; j++)
						{
							cout << s[j];
						}
						cout << endl;
						return 0;
					}
				}
			}
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