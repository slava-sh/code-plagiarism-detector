#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int

void z_func(string s, vector<int> &a)
{
	int bL = 0;
	int bR = 0;
	a[0] = 0;
	for(int i = 1; i < s.size(); i++)
	{
		a[i] = 0;
		if(bR >= i)
		{
			a[i] = min(a[i - bL], bR - i + 1);
		}
		if(i + a[i] >= s.size())
			continue;
		while(s[i + a[i]] == s[a[i]])
		{
			a[i]++;
			if(i + a[i] >= s.size())
				break;
		}
		if(a[i] > bR)
		{
			bL = i;
			bR = i + a[i] - 1;
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int L;
	string s;
	
	cin >> L;
	cin >> s;

	vector<int> z;
	z.resize(s.size(), 0);
	z_func(s, z);

int res = 0;
vector<string> res0;
	for(int i = 0; i <= L; i++)
	{
		if(z[i] == s.size() - i)
		{
			res = 1;
			string s0 = "";
			for(int j = 0; j < i; j++)
				s0 = s0 + s[j];
			res0.push_back(s0);

			break;
		}
	}
	
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
	
	
	if(res == 0)
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