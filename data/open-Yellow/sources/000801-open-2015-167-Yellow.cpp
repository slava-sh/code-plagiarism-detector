#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <vector>
#include <string>
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

int t[N];

int side (int p, int x, int c){
        if (t[p] == c)
            return 0;
        if (t[p] != t[x] && c != t[x])
            return 0;
        if (t[p] != t[x] && c == t[x])
            return -1;
        if (t[p] == t[x] && c != t[x])
            return 1;
}

int main()
{
    int n, e = 1, q, p, c;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i < n; i++)
        if (t[i] != t[i - 1])
            e++;
    cin >> q;
    if (n == 1){
        for (int i = 0; i < q; i++)
            cout << "1\n";
        return 0;
    }
    for (int ii = 0; ii < q; ii++){
        scanf("%d%d", &p, &c);
        p--;
        if (p == 0){
            e += side(p, p + 1, c);
            t[p] = c;
            cout << e << endl;
            continue;
        }
        if (p == n - 1){
            e += side(p, p - 1, c);
            t[p] = c;
            cout << e << endl;
            continue;
        }
        e += side(p, p + 1, c) + side(p, p - 1, c);
        cout << e << endl;
        t[p] = c;
    }
    return 0;
}
