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


#define INF 1000000000LL

int n, k;
int ans = INF;
int ans1 = 1;
vector<long long> v;


void get(int n1, int k1) {
    if (k1 == 0) {
        ans = ans1;
        return;
    }
    if (k1 == 1) {
        if (ans1 * (n1 + 1) / 2 < ans) {
            ans1 *= (n1 + 1) / 2;
            get(1, 0);
            ans1 /= (n1 + 1) / 2;
        }
        return;
    }
    for (int i = 0; i < (int)v.size(); i++) {
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
    int n1 = n;
    for (int i = 1; i <= n1; i++) {
        if (n1 % i == 0) {
            v.push_back(i);
        }
    }
    get(n, k);
    cout << ans << endl;
    return 0;
}
