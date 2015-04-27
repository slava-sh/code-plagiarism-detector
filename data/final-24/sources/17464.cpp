#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <fstream>

#define FILE "in"

typedef long long ll;

using namespace std;

int main()
{
	ifstream in(FILE".in");
	ofstream out(FILE".out");

	ll lf;
	cin >> lf;
	string s;
	cin >> s;

	ll len = s.length();

	if(lf >= len)
	{
		cout << 1 << endl << s;
		return 0;
	}

	char cur = s[0];
	for(int i = 0; i < len; i++)
	{
		if(s[i] != cur)
		{
			cur = -1;
			break;
		}
	}

	if(cur != -1)
	{
		cout << 1 << endl << cur;
		return 0;
	}

	vector<ll> z(len);
	for(ll i = 1, l = 0, r = 0; i < len; i++)
	{
		if(i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < len && s[i + z[i]] == s[z[i]])
			z[i]++;
		if(i + z[i] - 1 > r)
		{
			l = i;
			r = i + z[i] - 1;
		}
	}

	string t = s;

	for(ll i = 0; i <= len; i++)
	{
		if(i < len / 2 + 1 && i + z[i] == len && s[i - 1] == s[len - 1] && s[i - 2] == s[len - 2])
		{
			t = s.substr(0, i);
			break;
		}
	}

	if(t.length() <= lf)
	{
		cout << 1 << endl << t;
	}
	else
	{
		cout << 2 << endl << 'a' << endl << 'b';
	}


	in.close();
	out.close();
	return 0;
}
