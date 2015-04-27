// ¹1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <map>

using namespace std;

int l;
string s;

bool a[3];
int ans;

bool check1(int k){
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != s[i % k])
			return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf ("%d", &l);

	cin >> s;

	for (int i = 0; i < s.size(); ++i)
		a[s[i] - 'a'] = true;

	for (int i = 0; i < 3; ++i)
		if (a[i] == true)
			++ans;
	if (s.size() <= l)
	{
		printf ("1\n");
		cout << s;
		return 0;
	}
	for (int i = s.size() / 2; s.size() / i <= l; --i)
	{
		if (s.size() % i == 0 && check1(s.size() / i))
		{
			string g;
			for (int j = 0; j < s.size() / i; ++j)
				g += s[j];

			cout << "1\n";
			cout << g;
			return 0;
		}
	}
	
	
	printf ("%d\n", ans);
	for (int i = 0; i < 3; ++i)
		if (a[i] == true)
			printf("%c\n", 'a' + i);
	
	return 0;
}


