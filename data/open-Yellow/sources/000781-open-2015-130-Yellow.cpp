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

static int m1[200000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	int n, a, b, c, q, x, y;
	cin >> n;
	for (int i = 0; i < n; ++i)
        cin >> m1[i];
    set <pair <int, int> > se;
    set <pair <int, int> >::iterator it, it1;
    for (int i = 0; i < n; ++i){
        a = i;
        while (a + 1 < n && m1[a + 1] == m1[a])
            ++a;
        se.insert(mp(a + 2, i + 1));
        i = a;
    }
    cin >> q;
    for (int i = 0; i < q; ++i){
        cin >> a >> b;
        m1[a - 1] = b;
        it = se.upper_bound(mp(a + 1, 0));
        b = (*it).second, c = (*it).first;
        se.erase(mp(c, b));
        if (a != b) se.insert(mp(a, b));
        se.insert(mp(a + 1, a));
        if (c != a + 1)se.insert(mp(c, a + 1));
        it = se.upper_bound(mp(a + 1, 0));
        it1 = it;
        if (it != se.begin()) --it1;
        if (it != se.begin() && m1[(*it).second - 1] == m1[(*it1).second - 1]){
            x = (*it1).second;
            y = (*it).first;
            se.erase(it);
            se.erase(it1);
            se.insert(mp(y, x));
        }
        it = se.upper_bound(mp(a + 2, 0));
		if (it != se.end()){
			it1 = it;
			if (it != se.begin()) --it1;
			if (it != se.begin() && m1[(*it).second - 1] == m1[(*it1).second - 1]){
				x = (*it1).second;
				y = (*it).first;
				se.erase(it);
				se.erase(it1);
				se.insert(mp(y, x));
			}
		}
        cout << se.size() << '\n';
    }
	//system("pause");
	return 0;
}
