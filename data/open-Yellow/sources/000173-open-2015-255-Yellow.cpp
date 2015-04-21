#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int
#define C 100005
#define inf 1000000000000

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N;
	lint t[C];
	cin >> N;

	int bad = 0;
	lint cur = inf;
	for(int i = 1; i <= N; i++)
	{
		cin >> t[i];
		if(t[i] != cur)
		{
			bad++;
			cur = t[i];
		}
	}
	t[0] = t[N + 1] = inf;
	int Q;
	cin >> Q;
	for(int i = 0; i < Q; i++)
	{
		int p;
		lint c;
		cin >> p >> c;
		if(t[p - 1] == t[p + 1])
		{
			if(t[p] == t[p - 1])
			{
				if(c != t[p])
					bad += 2;
			}else
			{
				if(c == t[p - 1])
					bad -= 2;
			}
		}else{
			if(t[p] != t[p - 1] && t[p] != t[p + 1])
			{
				if(c == t[p - 1] || c == t[p + 1])
				{
					bad--;
				}
			}else if(t[p] == t[p - 1] || t[p] == t[p + 1])
			{
				if(!(c == t[p - 1] || c == t[p + 1]))
				{
					bad++;
				}
			}
		}
		t[p] = c;
		cout << bad << endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}