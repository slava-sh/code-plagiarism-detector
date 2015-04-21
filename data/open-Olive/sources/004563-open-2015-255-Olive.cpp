#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define lint long long int
#define inf 1000000000

int n;
vector<int> v;

int abs0(int x)
{
	if(x < 0)
		return -x;
	return x;
}

int g(int a, int b)
{
	return abs0(abs0(a - b) - abs0(v[a] - v[b])) - abs0(a - b);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	int a, b;
	a = -2;
	b = -2;
	int d = -1;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			if(v[i] > v[j])
			{
				int g0 = g(i, j);
				if(g0 < d || d == -1)
				{
					a = i;
					b = j;
					d = g0;
				}
			}
		}
	a++;
	b++;

	cout << a << " " << b << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}