#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = (int)1e5 + 47;
const int INF = (int)1e9 + 47;

string s;
int L;

set <string> st;

void gen()
{
	int n = s.size();
	for(int i = 1; i <= L; i++)
	{
		for(int j = 0; j <= n - i; j++)
			st.insert(s.substr(j, i));
	}
}

bool check1(string t)
{
	int size = s.size(), tsize = t.size();
	if(size % tsize != 0)
		return false;
	for(int i = 0; i < size; i++)
	{
		if(s.substr(i, tsize) == t)
			i = i + (tsize - 1);
		else
			return false;
	}
	return true;
}

bool check2(string t1, string t2)
{
	if(t1.size() < t2.size())
		swap(t1, t2);
	int size = s.size(), ts1 = t1.size(), ts2 = t2.size();
	for(int i = 0; i < size; i++)
	{
		if(i + ts1 <= size && s.substr(i, ts1) == t1)
			i = i + (ts1 - 1);
		else if(i + ts2 <= size && s.substr(i, ts2) == t2)
			i = i + (ts2 - 1);
		else
			return false;
	}
	return true;
}

void find_ans()
{
	for(set <string>::iterator it = st.begin(); it != st.end(); it++)
	{
		if(check1(*it))
		{
			cout << 1 << endl;
			cout << *it;
			exit(0);
		}
	}
	for(set <string>::iterator it1 = st.begin(); it1 != st.end(); it1++)
	{
		for(set <string>::iterator it2 = st.begin(); it2 != st.end(); it2++)
		{
			if(*it1 == *it2)
				continue;
			else if(check2(*it1, *it2))
			{
				cout << 2 << endl;
				cout << *it1 << "\n" << *it2;
				exit(0);
			}
		}
	}
	cout << 3 << "\na\nb\nc"; 
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> L >> s;
	gen();
	find_ans();
	return 0;
}