#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;
	if (l >= s.length())
	{
		cout << 1 << endl << s << endl;
		return 0;
	}
	bool oneletter = true;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] != s[i - 1]) oneletter = false;
	}
	if (oneletter)
	{
		cout << 1 << endl << s[0] << endl;
	}
	else
	{
		cout << 2 << endl << "a" << endl << "b" << endl;
	}
}