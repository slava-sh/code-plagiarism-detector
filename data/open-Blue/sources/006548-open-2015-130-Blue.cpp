#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
#define mp make_pair
#define ll long long
#define mod 1000000009

static ll m1[20000], m2[20000];

bool chk(int l, int r, int l1, int r1){
	if (r - l != r1 - l1)
		return 0;
	if ((m1[r + 1] - m1[l] + mod) % mod == (m1[r1 + 1] - m1[l1] + mod) % mod)
		return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	ll l;
	string s;
	cin >> l >> s;
	if (l > s.length())
        l = s.length();
	set <char> se;
	for (int i = 0; i < s.length(); ++i)
        se.insert(s[i]);
    if (se.size() == 1){
        cout << se.size() << endl;
        for (set <char>::iterator it = se.begin(); it != se.end(); ++it)
            cout << (*it) << '\n';
        return 0;
    }
    ll n = s.length(), a, b, c;
    for (int i = 1; i <= l; ++i) if (s.length() % i == 0){
        a = 1;
        for (int j = 0; j < s.length(); j += i)
            if (s.substr(j, i) != s.substr(0, i)){
                a = 0;
                break;
            }
        if (a){
            cout << 1 << '\n' << s.substr(0, i) << endl;
            return 0;
        }
    }
    if (se.size() == 2){
        cout << se.size() << endl;
        for (set <char>::iterator it = se.begin(); it != se.end(); ++it)
            cout << (*it) << '\n';
        return 0;
    }
	for (int i = 1; i <= n; ++i)
		m1[i] = (m1[i - 1] * 5 + s[i - 1] - 'a') % mod;
	a = 1;
	for (int i = n; i >= 0; --i){
		m1[i] *= a;
		a *= 5;
		a %= mod;
	}
    if (l <= 72)for (int i = 1; i <= l; ++i){
        a = 0;
        while (s.substr(0, i) == s.substr(a, i)){
            a += i;
        }
        for (int j = 1; j <= l; ++j){
            memset(m1, 0, sizeof(m1));
            m1[0] = 1;
            for (int k = 0; k < n; ++k)
                if (m1[k]){
                    if (chk(k, i, 0, i))
                        m1[k + i] = 1;
                    if (chk(k, j, a, j))
                        m1[k + j] = 1;
                }
            if (m1[n]){
                cout << 2 << endl;
                cout << s.substr(0, i) << '\n' << s.substr(a, j) << endl;
                return 0;
            }
        }
    }
	string s1;
	set <string> se1;
	if (l * n <= 200000000) for (int i = 1; i <= l; ++i){
		s1.clear();
		se1.clear();
		for (int j = 0; j < n; ++j)
			if (s.substr(j, i) == s.substr(0, i)){
				if (!s1.empty())
					se1.insert(s1);
				s1.clear();
				j += i - 1;
				if (se1.size() > 1)
					break;
			}
			else
				s1.push_back(s[j]);
		if (s1.size())
			se1.insert(s1);
		if (se1.size() == 1 && (*se1.begin()).size() <= l){
			cout << 2 << endl << s.substr(0, i) << endl << (*se1.begin()) << endl;
			return 0;
		}
	}
    if (se.size() == 3){
        cout << se.size() << endl;
        for (set <char>::iterator it = se.begin(); it != se.end(); ++it)
            cout << (*it) << '\n';
    }
	//system("pause");
	return 0;
}