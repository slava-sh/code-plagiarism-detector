#include <cstdio>
#include <iostream>
#include <string>

#define FNAME "inventory"
#define ull unsigned long long

const int P = 239017, maxn = 300001;
using namespace std;

int main()
{
	freopen (FNAME".in", "r", stdin);
	freopen (FNAME".out", "w", stdout);
	int n;
	scanf ("%d\n", &n);
	ull p[maxn];
	p[0] = 1;
	for (int i = 1; i < maxn; i++)
		p[i] = p[i - 1] * P;
	for (int i = 0; i < n; i++)
	{
		string s; 
		cin >> s;
		int len = s.length();
		string s1;    
		s1 = s;
		for (int i = 0; i < len; i++)
			s1[i] = s[len - i - 1];
		//cout << s << endl;
		//cout << s1 << endl;
		ull h, h1;
		h = s[0];
		for (int i = 1; i < len; i++)
			h += s[i] * p[i];
		h1 = s1[0];
		for (int i = 1; i < len; i++)
			h1 += s1[i] * p[i];
		int c = 0;
		while (h != h1 && c != len)
		{           
			h = (h - s[c] * p[c]) + s[c] * p[len + c];
			h1 = (h1 - s1[len - c - 1] * p[len - 1 + c]) * p[2] + s1[len - c - 1] * p[1 + c]; 
			//printf ("%c %c\n", s[c], s1[len - c - 1]);
			c++;			
		}
		if (c == len)
			printf ("-1\n");
		else
			printf ("%d\n", c);

	}
}