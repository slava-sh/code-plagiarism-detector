#pragma comment(linker, "/STACK:10000000000000")


#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#define problem "names"
#define sort stable_sort
#define ll long long
#define INFll 1e18 + 7
#define mp make_pair
#define pb push_back
using namespace std;

struct pupil
{
	string x[3];
};
pupil a[1111];
int n;
set <string> all, names;
bool cmp(pupil a, pupil b)
{
	return (a.x[0] < b.x[0]);
}
int main()
{
	ifstream cin(problem".in");
	ofstream cout(problem".out");
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> a[i].x[j];
			if (j < 2)
			{
				if (all.find(a[i].x[j]) != all.end())
					names.insert(a[i].x[j]);
				all.insert(a[i].x[j]);
			}
		}
	}

//	for (set <string> ::iterator i = names.begin(); i != names.end(); i++)
	//	cout << *i << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (names.find(a[i].x[j]) != names.end())
			{
				if (!j)
				{
					swap(a[i].x[0], a[i].x[2]);
					swap(a[i].x[1], a[i].x[2]);
				}
			}
		}
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++, cout << "\n")
		for (int j = 0; j < 3; j++, cout << " ")
			cout << a[i].x[j];
	return 0;
}