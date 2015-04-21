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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int l;
	string s;
	cin >> l >> s;
	set <char> se;
	for (int i = 0; i < s.length(); ++i)
        se.insert(s[i]);
    cout << se.size() << endl;
    for (set <char>::iterator it = se.begin(); it != se.end(); ++it)
        cout << (*it) << '\n';
	//system("pause");
	return 0;
}
