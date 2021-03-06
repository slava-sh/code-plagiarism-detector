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

const int p = 2015, q = 2000000009;
int arr[200001], pow[200001];
int L, n;
string a;
set <char> need;

bool OK(int s, int j, int ans1) {
    if (s + j <= n) {
        int ans2 = arr[s + j] - (arr[s] * pow[j] % q);
        if (ans2 < 0) ans2 += q;
        return ans1 == ans2;
    }
    return false;
}

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
    if (L >= n) {
        cout << 1 << endl;
        cout << a << endl;
        return 0;
    }
    if (need.size() < 3) {
        cout << need.size() << endl;
        if (need.find('a') != need.end()) cout << 'a' << endl;
        if (need.find('b') != need.end()) cout << 'b' << endl;
        if (need.find('c') != need.end()) cout << 'c' << endl;
        return 0;
    }
    else {
        For(i, 1, L + 1) {
            int ans1 = arr[i];
            int start = i;
            while (true) {
           //     cout << start << endl;
                if (arr[start + i] - (arr[start] * pow[i] % q) == ans1) {
                    start += i;
                }
                else {
                    break;
                }
                //cout << start << endl;
            }
            For(j, 1, L + 1) {
                int s = start;
                int ans2 = arr[start + j] - (arr[start] * pow[j] % q);
                if (ans2 < 0) ans2 += q;
                start += j;
                while (true) {
                    //cout << '(' << start << ' ' << j << endl;
                    if (arr[start + i] - (arr[start] * pow[i] % q) == ans1) {
                        start += i;
                    }
                    else if (arr[start + j] - (arr[start] * pow[j] % q) == ans2) {
                        start += j;
                    }
                    else {
                        break;
                    }
                    //cout << '(' << start << ' ' << j << endl;
                }
                //cout << start << endl;
                if (start == n) {
                    cout << 2 << endl;
                    For(x, 0, i) {
                        cout << a[x];
                    }
                    cout << endl;
                    For(x, s, s + j) {
                        cout << a[x];
                    }
                    cout << endl;
                    return 0;
                }
                start = s;
            }
        }
    }
    cout << 3 << endl << 'a' << endl << 'b' << endl << 'c' << endl;
}

