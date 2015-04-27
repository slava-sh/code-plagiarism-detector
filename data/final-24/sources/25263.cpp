//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <memory.h>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>

#define pb push_back
#define mp make_pair
#define ms(a) memset((a),0,sizeof((a)))
#define msx(a,x) memset((a),(x),sizeof((a)))
#define ll long long
#define INF 1000000009
#define PI 3.14159265
#define EPS 0.00000001

using namespace std;

string s;

int mn=9999,l;

vector <string> ans;

void rec(set <string> h, int p)
{
	int i;

	if ((int)h.size()>=mn)
		return;

	if (p==s.size() && h.size()<mn)
	{
		mn=h.size();
		ans.clear();
			
		for (set <string>::iterator it=h.begin(); it!=h.end(); it++)
			ans.pb(*it);

		return;
	}

	string t;

	for (i=p; i<min(p+l,(int)s.size()); i++)
		t.pb(s[i]);

	for (i=min(p+l,(int)s.size())-1; i>=0; i--)
	{
		if (t.size()==0)
			break;
		if (!h.count(t))
		{
			h.insert(t);
			rec(h,i+1);
			h.erase(t);
		}
		else
			rec(h,i+1);

		t.pop_back();
	}

	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w", stdout);

	cin >> l;

	set <string> h;

	string t;

	cin >> s;

	rec(h,0);

	cout << mn << endl;

	for (int i=0; i<mn; i++)
		cout << ans[i] << endl;

	return 0;
}

