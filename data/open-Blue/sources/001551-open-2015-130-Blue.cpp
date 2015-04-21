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
#define mod 1000000007

static int m1[20000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	int l;
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
    int n = s.length(), a, b, c;
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
    for (int i = 1; i <= l; ++i){
        a = 0;
        while (s.substr(0, i) == s.substr(a, i)){
            a += i;
        }
        for (int j = 1; j <= l; ++j){
            memset(m1, 0, sizeof(m1));
            m1[0] = 1;
            for (int k = 0; k < n; ++k)
                if (m1[k]){
                    if (s.substr(k, i) == s.substr(0, i))
                        m1[k + i] = 1;
                    if (s.substr(k, j) == s.substr(a, j))
                        m1[k + j] = 1;
                }
            if (m1[n]){
                cout << 2 << endl;
                cout << s.substr(0, i) << '\n' << s.substr(a, j) << endl;
                return 0;
            }
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
