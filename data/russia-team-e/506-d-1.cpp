#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("fence.in");
ofstream fout("fence.out");

const int MAXN = 100000;
int n, k;
vector<int> a;

bool check(int x){
    if (a[0] < x) {
        return false;
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += max(a[i] - sum, x);
    }
    if (sum <= k) {
        return true;
    }
    return false;
}

int bin(int l, int r) {
    if (l == r) {
        return l - 1;
    }
    int m = (l + r) / 2;
    if (check(m)) {
        bin(m + 1, r);
    }
    else {
        bin(l, m);
    }
}

int main() {
    fin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
    }
    sort(a.begin(), a.end());
    fout << bin(0, k);
    return 0;
}
