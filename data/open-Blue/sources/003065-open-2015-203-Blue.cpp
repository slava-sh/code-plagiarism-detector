#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	int L;
	string s;
	cin >> L;
	cin >> s;
	int N = s.length();
	if (L >= N)
	{
		cout << 1 << endl;
		return 0;
	}
	string now_str = "";
	for (int i = 0; i < L; i++)
	{
		now_str += s[i];
		if (N % (i + 1) == 0)
		{
			bool d = false;
			for (int q = 0; q < N; q += (i + 1))
			{
				if (s.substr(q, (i + 1)) != now_str)
				{
					d = true;
					break;
				}
			}
			if (!d)
			{
				cout << 1 << endl << now_str << endl;
				return 0;
			}
		}
	}
	cout << 2 << endl << 'a' << endl << 'b' << endl;
	return 0;
}