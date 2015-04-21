#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
bool checkUnique(string& s, vector<string>& dict)
{
	vector<int>dp(s.length(), 0);
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 0; j < dict.size(); j++)
		{
			int t = i - dict[j].length() + 1;
			if (t >= 0 && s.substr(t, dict[j].length()) == dict[j])
			{
				int w = i - dict[j].length();
				if (w >= 0)
				{
					dp[i] += dp[w];
				}
				else
				{
					dp[i]++;
				}
			}
		}
	}
	return dp[s.length() - 1] == 1;
}
int main()
{
	int l;
	cin >> l;
	string s;
	cin >> s;	
	string cand;
	for (int i = 0; i < l; i++)
	{
		cand += s[i];
		vector<string>tmp;
		tmp.push_back(cand);
		if (checkUnique(s, tmp))
		{
			cout << 1 << endl;
			cout << cand << endl;
			return 0;
		}
	}
	for (int l1 = 0; l1 < s.length(); l1++)
	{
		string c1;
		for (int len1 = 1; len1 <= l; len1++)
		{
			c1 += s[l1 + len1 - 1];
			for (int l2 = 0; l2 < s.length(); l2++)
			{
				string c2;
				for (int len2 = 1; len2 <= l; len2++)
				{
					c2 += s[l2 + len2 - 1];
					vector<string>tmp;
					tmp.push_back(c1);
					tmp.push_back(c2);
					if (checkUnique(s, tmp))
					{
						cout << 2 << endl;
						cout << c1 << endl;
						cout << c2 << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << 3 << endl;
	cout << "a\nb\nc\n" << endl;
}