#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define ld long double
#define pii pair <int, int>

using namespace std;

const int N = (int)5e5 + 7;
const ll INF = (ll)1e9 + 7;
const ld EPS = 1e-9;

int a[N];

int main(){
    int n, a1, a2, sum = 0, x, y, d, ma = -1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        sum += abs(a[i] - i);
    }
    if (sum == 0)
        return cout << "-1 -1", 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            a1 = abs(a[i] - i) + abs(a[j] - j);
            a2 = abs(a[i] - j) + abs(a[j] - i);
            d = a1 - a2;
            if (d > ma)
                ma = d, x = i + 1, y = j + 1;
        }
    cout << x << " " << y;
    return 0;
}
