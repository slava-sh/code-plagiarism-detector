#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 100500;
string s;
int l;

bool check(int dx)
{
	for (int i = 0; i < (int)s.size() - dx; i++)
	{
		if (s[i] != s[i + dx])
			return false;
	}
	return true;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	cin >> l;
	cin >> s;
	
	for (int i = 1; i <= l; i++)
	{
		if (check(i) && s.size() % i == 0)
		{
			cout << 1 << endl << s.substr(0, i);
			return 0;
		}
	}
	printf("2\na\nb");
	return 0;
}