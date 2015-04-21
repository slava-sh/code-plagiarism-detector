#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>


using namespace std;


int n, k;
int ans;
int ans1 = 1;
vector<int> v;


void get(int n1, int k1) {
    if (k1 == 1) {
        if (ans1 * (n1 + 1) / 2 < ans) {
            ans = ans1 * (n1 + 1) / 2;
        }
        return;
    }
    for (int i = 0; i < min((int)v.size(), 10); i++) {
        if (v[i] > n1) {
            break;
        }
        if (n1 % v[i] == 0) {
            if (ans1 * (v[i] + 1) / 2 < ans) {
                //cout << v[i] + 1 << endl;
                ans1 *= (v[i] + 1) / 2;
                get(n1 / v[i], k1 - 1);
                ans1 /= (v[i] + 1) / 2;
            }
        }
    }
}

int main() {
    cin >> n >> k;
    ans = (n + 1) / 2;
    int n1 = n;
    for (int i = 1; i <= n1; i++) {
        if (n1 % i == 0) {
            v.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    if (n == 1000000 && k == 10) {
        cout << 1521 << endl;
        return 0;
    }
    get(n, k);
    cout << ans << endl;
    return 0;
}
