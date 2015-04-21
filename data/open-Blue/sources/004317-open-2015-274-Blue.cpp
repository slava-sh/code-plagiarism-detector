#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

string S, answer1, answer2;

bool check(int l1, int l2, string p1, string p2, int index)
{
	// cout << index << " " << p1 << " " << p2 << endl;
	int n = (int) S.size();
	if (index == n)
	{
		answer1 = p1;
		answer2 = p2;
		return true;
	}
	else
	{
		bool good = false;
		if (index + l1 <= n && S.substr(index, l1) == p1)
			good |= check(l1, l2, p1, p2, index + l1);
		if (p2 != "")
		{
			// cout << "?" << endl;
			if (index + l2 <= n && S.substr(index, l2) == p2)
				good |= check(l1, l2, p1, p2, index + l2);
		}
		else
		{
			if (index + l2 <= n)
				good |= check(l1, l2, p1, S.substr(index, l2), index + l2);
			// cout << "!" << endl;
		}
		return good;	
	}
}

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");
	int L, a = 0, b = 0, c = 0;
	cin >> L >> S;
	if (L >= (int)S.size())
		cout << 1 << endl << S << endl;
	else
	{
		for (int i = 0; i < (int)S.size(); ++i)
			if (S[i] == 'a')
				a += 1;
			else if (S[i] == 'b')
				b += 1;
			else
				c += 1;
		if (c == 0)
		{
			if (b == 0)
				cout << "1\na\n";
			else if (a == 0)
				cout << "1\nb\n";
			else
			{
				int n = (int)S.size();
				bool found = false;
				for (int l = 1; l <= L; ++l)
				{
					if (n % l != 0)
						continue;
					bool good = true;
					for (int j = 0; j < n; j += l)
					{
						if (S.substr(j, l) != S.substr(0, l))
						{
							good = false;
							break;
						}
					}
					if (good)
					{
						found = true;
						cout << 1 << endl;
						cout << S.substr(0, l) << endl;
						break;
					}
				}
				if (!found)
					cout << "2\na\nb\n";
			}
		}
		else
		{
			int n = (int)S.size();
			bool found = false;
			for (int l = 1; l <= L; ++l)
			{
				if (n % l != 0)
					continue;
				bool good = true;
				for (int j = 0; j < n; j += l)
				{
					if (S.substr(j, l) != S.substr(0, l))
					{
						good = false;
						break;
					}
				}
				if (good)
				{
					found = true;
					cout << 1 << endl;
					cout << S.substr(0, l) << endl;
					break;
				}
			}
			if (!found)
			{
				found = false;
				for (int l1 = 1; l1 <= L; ++l1)
				{
					for (int l2 = 1; l2 <= L; ++l2)
					{
						if (check(l1, l2, S.substr(0, l1), "", 0))
						{
							found = true;
							cout << 2 << endl << answer1 << endl << answer2 << endl;
							break;
						}
					}
					if (found)
						break;
				}
				if (!found)
					cout << "3\na\nb\nc\n";
			}
		}
	}
}