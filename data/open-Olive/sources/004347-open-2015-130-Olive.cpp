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

static int m1[15005], m2[15005][15005];

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	int n, cu = 0, res = 0, a, b, c, x = -2, y = -2;
	cin >> n;
	for (int i = 0; i < n; ++i)
        cin >> m1[i];
    for (int j = m1[0]; j <= n; ++j)
        ++m2[0][j];
    for (int i = 1; i < n; ++i){
        for (int j = 1; j <= n; ++j)
            m2[i][j] = m2[i - 1][j] + (j >= m1[i]);
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            a = 0;
            if (m1[j] < m1[i])
                ++a;
            else
                continue;
            a += 2 * (m2[j - 1][m1[i]] - m2[i][m1[i]]) - 2 * (m2[j - 1][m1[j]] - m2[i][m1[j]]);
            if (res < a){
                res = a;
                x = i;
                y = j;
            }
        }
    cout << x + 1 << ' ' << y + 1 << endl;
	//system("pause");
	return 0;
}
