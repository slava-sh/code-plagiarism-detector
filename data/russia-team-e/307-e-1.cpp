#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define pb push_back
#define rs resize
#define inf 1e9

typedef vector <int> vi;
typedef pair <int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector <string> vs;
typedef vector <vs> vvs;

int main()
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int n;
	cin >> n;
	vs c(n);
	vvs a(n);
	int k;
	for (int i = 0; i < n; ++i)
	{
		cin >> c[i] >> k;
		a[i].rs(k);
		for (int j = 0; j < k; ++j)
			cin >> a[i][j];
	}
	int m;
	cin >> m;
	string s, ans1, ans2;
	for (; m > 0; m--)
	{
		cin >> s;
		ans1 = ans2 = "";
		for (int i = 0; i < n; ++i)
			if (s.substr(0, c[i].size()) == c[i])
				for (int j = 0; j < a[i].size(); j++)
					if (s.substr(0, a[i][j].size() + c[i].size()) == c[i] + a[i][j])
						ans2 = a[i][j], ans1 = c[i];
		if (ans1 == "" || s[ans1.size() + ans2.size()] == '0')
			cout << "Incorrect";
		else
		{
			
			cout << '+' << ans1 << '(' << ans2 << ')';
			s = s.substr(ans1.size() + ans2.size(), s.size() - ans1.size() - ans2.size());
			if (s.size() == 3)
				cout << s;
			if (s.size() == 4)
				cout << s[0] << s[1] << '-' << s[2] << s[3];
			if (s.size() == 5)
				cout << s[0] << s[1] << s[2] << '-' << s[3] << s[4];
			if (s.size() == 6)
				cout << s[0] << s[1] << '-' << s[2] << s[3] << '-' << s[4] << s[5];
			if (s.size() == 7)
				cout << s[0] << s[1] << s[2] << '-' << s[3] << s[4] << '-' << s[5] << s[6];
		}
		cout << endl;
	}
	return 0;
}