#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)
#define int long long
#define pow asdf

using namespace std;

const int p = 100, q = 1000000000000070007;
int arr[20001], pow[200001];
int L, n;
string a;
set <char> need;

main() {
    cin >> L >> a;
    n = a.size();
    pow[0] = 1;
    For(i, 0, n) {
        arr[i + 1] = (arr[i] * p + a[i]) % q;
        need.insert(a[i]);
        pow[i + 1] = pow[i] * p % q;
    }
    For(i, 1, L + 1) {
        if (n % i == 0) {
            int ans1 = arr[n] - (arr[i] * pow[n - i] % q);
            if (ans1 < 0) ans1 += q;
            int ans2 = arr[n - i];
            if (ans1 == ans2) {
                cout << 1 << endl;
                For(q, 0, i) {
                    cout << a[q];
                }
                cout << endl;
                return 0;
            }
        }
    }
    if (need.size() < 3) {
        cout << need.size() << endl;
        if (need.find('a') != need.end()) cout << 'a' << endl;
        if (need.find('b') != need.end()) cout << 'b' << endl;
        if (need.find('c') != need.end()) cout << 'c' << endl;
    }
}

