#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <set>
using namespace std;

string s;

int l, size;

set <string> st, used;

vector <string> ans;

/*void gen(int l, string s)
{
	if(l == 0)
		st.insert(s);
	gen(l - 1, s + "a");
	gen(l - 1, s + "b");
	gen(l - 1, s + "c");
}*/

void solve(int ind, int cnt)
{
	if(ind == size)
	{
		if(used.size() < ans.size())
		{
			ans.clear();
			for(set <string>::iterator it = used.begin(); it != used.end(); it++)
			{
				ans.push_back(*it);
			}
		}
		return;
	}
	string str = "";
	for(int i = ind; i < min(ind + l, size); i++)
	{
		str.push_back(s[i]);
		if(used.count(str))
			solve(i + 1, cnt);
		else
		{
			used.insert(str);
			solve(i + 1, cnt + 1);
			used.erase(str);
		}
	}
}

void out()
{
	int size = ans.size();
	cout << size << "\n";
	for(int i = 0; i < size; i++)
		cout << ans[i] << "\n";
}

int main()
{
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	cin >> l >> s;
	size = s.size();
	ans.push_back("a");
	ans.push_back("b");
	ans.push_back("c");
	//gen(l, "");
	solve(0, 0);
	out();
	return 0;
}