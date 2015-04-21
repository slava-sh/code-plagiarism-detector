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

static int m1[5000];

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "-w", stdout);
	int n, cu = 0, res = 0, a, b, c, x = -2, y = -2;
	cin >> n;
	for (int i = 0; i < n; ++i)
        cin >> m1[i];
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (m1[j] < m1[i])
                ++cu;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j){
            a = 0;
            if (m1[j] < m1[i])
                ++a;
            else
                --a;
            for (int k = i + 1; k < j; ++k){
                if (m1[k] < m1[i])
                    ++a;
                else
                    --a;
                if (m1[k] > m1[j])
                    ++a;
                else
                    --a;
            }
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
