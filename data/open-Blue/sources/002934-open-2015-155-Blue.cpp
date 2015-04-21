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
			while (len + id <= (int)s.length() && len + 1 <= (int)s1.length() && s1[len] == s[id + len])
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
	cout << 2 << endl;
	cout << "a\n";
	cout << "b\n";
}