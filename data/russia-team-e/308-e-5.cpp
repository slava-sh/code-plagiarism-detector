#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdio>
#include <cstdlib>
#define eps 1e-9
#define INF 1e+9
#define txt "numbers"

using namespace std;
int n, l;
int fl1, fl2;
string num;
struct gos
{
	int s;
	string x;
	string b[110];
} a[110];
bool comp(string a, string b, int z)
{
	for (int i = 0; i < b.size(); i++)
		if (a[i+z] != b[i])
			return 0;
	return 1;
}
void Print(int n, int k)
{
	int dl = a[n].x.size() + a[n].b[k].size();
	if (num[dl] == '0' || n == -1 || a[n].x[0] == '0' || a[n].b[k][0] == '0')
	{
		cout << "Incorrect\n";
		return;
	}
	cout << '+' << a[n].x << '(' << a[n].b[k] << ')';
	if (11 - dl == 7)
	{
		cout << num[4] << num[5] << num[6] << '-' << num[7] << num[8] << '-' << num[9] << num[10];
		cout << endl;
		return;
	}
	if (11 - dl == 6)
	{
		cout << num[5] << num[6] << '-' << num[7] << num[8] << '-' << num[9] << num[10];
		cout << endl;
		return;
	}
	if (11 - dl == 5)
	{
		cout << num[6] << num[7] << num[8] << '-' << num[9] << num[10];
		cout << endl;
		return;
	}
	if (11 - dl == 4)
	{
		cout << num[7] << num[8] << '-' << num[9] << num[10];
		cout << endl;
		return;
	}
	if (11 - dl == 3)
	{
		cout << num[8]  << num[9] << num[10];
		cout << endl;
		return;
	}
}
int main()
{
	freopen(txt".in", "r", stdin);
	freopen(txt".out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].s;
		for (int j = 0; j < a[i].s; j++)
			cin >> a[i].b[j];
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> num;
		if (num[0] == '0' || num.size() != 11)
		{
			cout << "Incorrect\n";
			continue;
		}
		fl1 = -1;
		fl2 = -1;
		for (int j = 0; j < n; j++)
		{
			if (comp(num, a[j].x, 0))
			{
				for (int k = 0; k < a[j].s; k++)
				{
					if(comp(num, a[j].b[k], a[j].x.size()))
					{
						if (num[a[j].x.size()+a[j].b[k].size()] == '0')
							break;
						fl1 = j;
						fl2 = k;
						break;
					}
				}
			}
		}
		Print(fl1, fl2);
	}
	return 0;
}