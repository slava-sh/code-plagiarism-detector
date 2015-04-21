#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
bool checkUnique(string& s, string& s1, string&s2)
{
	vector<int>dp(s.length(), 0);
	for (int i = 0; i < s.length(); i++)
	{
		int tmp = i - s1.length() + 1;
		if (tmp >= 0 && s.substr(tmp, s1.length()) == s1)
		{
			int tmp = i - s1.length();
			if (tmp >= 0)
			{
				dp[i] += dp[tmp];
			}
			else
			{
				dp[i]++;
			}
		}
		tmp = i - s2.length() + 1;
		if (tmp >= 0 && s.substr(tmp, s2.length()) == s2)
		{
			int tmp = i - s1.length();
			if (tmp >= 0)
			{
				dp[i] += dp[tmp];
			}
			else
			{
				dp[i]++;
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
	string emp;
	for (int i = 0; i < l; i++)
	{
		cand += s[i];
		vector<string>tmp;
		tmp.push_back(cand);
		if (checkUnique(s, cand,emp))
		{
			cout << 1 << endl;
			cout << cand << endl;
			return 0;
		}
	}
	for (int l1 = 0; l1 < s.length(); l1++)
	{
		string c1;
		for (int len1 = 1; len1 <= l && l1 + len1 - 1<s.length(); len1++)
		{
			c1 += s[l1 + len1 - 1];
			for (int l2 = l1; l2 < s.length(); l2++)
			{
				string c2;
				for (int len2 = 1; len2 <= l && l2+len2-1<s.length(); len2++)
				{
					c2 += s[l2 + len2 - 1];
					vector<string>tmp;
					tmp.push_back(c1);
					tmp.push_back(c2);
					if (checkUnique(s, c1,c2))
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