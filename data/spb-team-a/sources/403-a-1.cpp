#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("abcd.in", "r", stdin);
	freopen("abcd.out", "w", stdout);
	int t, per, vt, i;
	cin >> t;
	for (int j = 0; j < t; j++)
	{
		cin >> i;
		per = i / 100;
		vt = i % 100;
		if ((per*per + vt*vt) % 7 == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
