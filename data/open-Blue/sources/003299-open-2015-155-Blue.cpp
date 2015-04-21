#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	string s1 = "";
	int n = (int)s.length();
	for (int i1 = 0; i1 < min((int)s.length(), l); ++i1)
	{
		s1 += s[i1];
		int id = i1 + 1;
		while (id < n)
		{
			int len = 0;
			while (len + id < (int)s.length() && len + 1 <= (int)s1.length() && s1[len] == s[id + len])
			{
				++len;
			}
			if (len == (int)s1.length())
				id += len;
			else
				break;
		}
		if (id == n)
		{
			cout << 1 << endl;
			cout << s1 << endl;
			return 0;
		}
	}
	bool f = true;
	for (int i = 0; i < n; ++i)
		if (s[i] == 'c')
			f = false;
	if (f)
	{
		cout << 2 << endl;
		cout << "a\n";
		cout << "b\n";
		return 0;
	}
	s1 = "";
	string s2 = "";
	for (int i1 = 0; i1 < min((int)s.length(), l); ++i1)
	{
		s1 += s[i1];
		s2 = "";
		for (int i2 = i1 + 1; i2 < (int)s.length() && i2 - i1 <= l; ++i2)
		{
			s2 += s[i2];
			int id = i2 + 1;
			while (id < n)
			{
				int len1 = 0;
				while (len1 + id < (int)s.length() && len1 + 1 <= (int)s1.length() && s1[len1] == s[id + len1])
				{
					++len1;
				}
				int len2 = 0;
				while (len2 + id < (int)s.length() && len2 + 1 <= (int)s2.length() && s2[len2] == s[id + len2])
				{
					++len2;
				}
				if (len1 == (int)s1.length())
					id += len1;
				else if (len2 == (int)s2.length())
					id += len2;
				else
					break;
			}
			if (id == n)
			{
				cout << 2 << endl;
				cout << s1 << endl;
				cout << s2 << endl;
				return 0;
			}
		}
	}
	cout << 3 << endl;
	cout << "a\n";
	cout << "b\n";
	cout << "c\n";
}