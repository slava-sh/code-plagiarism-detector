#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int L;
	string s;
	cin >> L;
	cin >> s;
	bool have[300];
	have['a'] = have['b'] = have['c'] = 0;
	vector<string> v;
	for(int i = 0; i < s.size(); i++)
	{
		string s0;
		s0 = "";
		s0 = s0 + s[i];
		if(have[s[i]] == 0)
		v.push_back(s0);
		have[s[i]] = 1;
	}
	vector<string> res0;
	int res;
	if(L == s.size())
	{
		res = 1;
		res0.push_back(s);
	}
	else
	{
		res = v.size();
		res0 = v;
	}

	cout << res << endl;
	for(int i = 0; i < res0.size(); i++)
	{
		cout << res0[i] << endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}