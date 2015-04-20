#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include<sstream>
#include<iostream>

using namespace std;


map < pair < int, int> , int > mam;
int c[int(1e3)];

void foo ( int x)
{

	//cout << "x = " << x << endl;
	stringstream r;
	string s;
	r << x;
	r >> s;
	if ( (int)s.size() == 3)
	{
		cout << s << endl;
		return;
	}
	if ( (int)s.size() == 4)
	{
		cout << s[0] << s[1] << "-" << s[2] << s[3]  << endl;
		return;
	}
	if ( (int)s.size() == 5)
	{
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4]  << endl;
		return;
	}

	if ( (int)s.size() == 6)
	{
		cout << s[0] << s[1] << "-" <<s[2] <<  s[3] << "-" << s[4] << s[5] << endl;
		return;
	}

	if ( (int)s.size() == 7)
	{
		cout << s[0] << s[1] << s[2] << "-" << s[3] << s[4] << "-" << s[5] << s[6] << endl;
		return;
	}

	

	printf("\n");
}

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n, k;
	scanf("%d", &n);
	for ( int ii = 0; ii < n; ii++)
	{
		scanf("%d%d", &c[ii], &k);
		for ( int i = 0; i < k; i++)
		{
			int x;
			scanf("%d", &x);
			mam[make_pair(c[ii], x)] = 1;
		}
	}
	int m;
	string s;
	scanf("%d", &m);
	for ( int pp = 0; pp < m; pp++)
	{
		long long x;
		scanf("%I64d", &x);
		if ( x < (long long)(1e10))
		{
			printf("Incorrect\n");
			continue;
		}
		stringstream r;
		r << x;
		r >> s;
		//cout << "s =" << s << endl;
		int a = 0;
		int b = 0;
		int fl = 0;
		for (int i = 1; i <= 3; i++)
		{
			a = 0;
		  	for (int k = 1; k <= i; k++)
		   		a = a*10 + s[k - 1] - '0';
		 	for (int j = 3; j <= 6; j++)
		  	{
		  		b = 0;
		    	for (int k = (i + 1); k <= j + i; k++)
		    	{
		      		b = b*10 + s[k - 1] - '0';
		   		}
		   		if ( s[i] != '0' && s[i + j] != '0' && mam[make_pair(a, b)] == 1 && fl == 0)
				{
					//cout <<"a" << a << " " << b << endl;
				
					int x = 0;
					for ( int pos = i + j; pos < (int)s.size(); pos++)
					{
						x = x * 10 + s[pos] - '0';
						//cout << "!!!" << x << " " << s[pos] - '0'<< endl;
					}
					printf("+%d(%d)", a, b);
					foo(x);
					fl = 1;
				}
			}
		}
		if ( fl == 0)
			printf("Incorrect\n");
		

	}
	return 0;
}