#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int ans = 1000000007;
	int l;
	cin >> l;
	string s;
	cin >> s;
	vector<string>ansd;
	for (int mask = 0; mask <= (1 << s.length()) - 1; mask++)
	{
		bool ok = true;
		vector<bool>cur;
		int tmp = mask;
		for (int i = 1; i <= s.length(); i++)
		{
			if (tmp % 2 == 1)
			{
				cur.push_back(true);
			}
			else
			{
				cur.push_back(false);
			}
		}
		string curd;
		set<string>dict;
		for (int i = 0; i < s.length(); i++)
		{
			curd += s[i];
			if (cur[i] == true || i == s.length() - 1)
			{
				if (curd.length()>l) ok = false;
				dict.insert(curd);
				curd = "";
			}
		}
		if (ok && dict.size() < ans)
		{
			ans = dict.size();
			ansd.clear();
			for (set<string>::iterator it = dict.begin(); it != dict.end(); it++)
			{
				ansd.push_back((*it));
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < ansd.size(); i++)
	{
		cout << ansd[i] << endl;
	}
	cin >> l;
}