#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int

int L;

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

bool need(string s0, string &ans)
{
	vector<int> z;
	z.resize(s0.size(), 0);
	z_func(s0, z);
	//string ans = "";
	ans = "";
	for(int i = 0; i < s0.size(); i++)
	{
		if(z[i] == s0.size() - i)
			if(z[i] % i == 0)
				if(i < L)
			{
				for(int j = 0; j < i; j++)
					ans = ans + s0[j];
				return 1;
			}
	}
	return 0;
}
string mod(string s0, string del)
{
	string s1 = del + '~' + s0;
	vector<int> z;
	z.resize(s1.size(), 0);
	z_func(s1, z);
	vector<bool> bad;
	int i = del.size() + 1;
	while(i < s1.size())
	{
		if(z[i] >= del.size())
		{
			for(int j = 0; j < del.size() - 1; j++)
			{
				bad.push_back(1);
				i++;
			}
			bad.push_back(i);
		}else
			bad.push_back(0);
		i++;
	}
	string ret;
	for(int i = 0; i < s0.size(); i++)
	{
		if(bad[i] == 0)
			ret.push_back(s0[i]);
	}
	return ret;
}

int need2(string s0, string &a, string &b)
{
	string del = "";
	for(int i = 0; i < L; i++)
	{
		del += s0[i];

		string sd = mod(s0, del);
		//cout << s0 << " " << del << " " << sd << endl;
		if(need(sd, a))
		{
			b = del;
			return 1;
		}
	}
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	string s;
	
	cin >> L;
	cin >> s;
	L = min(L, (int)s.size());

	vector<int> z;
	z.resize(s.size(), 0);
	z_func(s, z);

	int res = 0;
	vector<string> res0;
	for(int i = 0; i <= min(L, (int)s.size() - 1); i++)
	{
		if(z[i] == s.size() - i)
			if(z[i] % i == 0)
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
	if(L >= s.size())
	{
		res = 1;
		res0.push_back(s);
	}
	else
	{
		res = v.size();
		res0 = v;
	}

	if(res == 3)
	{
		string a, b;
		bool YES = need2(s, a, b);
		if(YES)
		{
			res = 2;
			res0.clear();
			res0.push_back(a);
			res0.push_back(b);
		}
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