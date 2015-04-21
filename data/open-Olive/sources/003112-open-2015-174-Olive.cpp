#include <bits/stdc++.h>

using namespace std;

int N;
int *tree;

void init() {
    for (int i = 0; i < N; i++) {
        tree[i] = 0;
    }
}

void inc(int p) {
    for (int i = p; i < N; i |= i + 1) {
        tree[i] += 1;
    }
}

int sum(int p) {
    int result = 0;
    for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
        result += tree[i];
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> N;
    tree = new int[N];

    vector<int> height(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> height[i];
        height[i]--;
    }

    int result = -1e9;
    int a, b;
    for (int i = 0; i < N; i++) {
        init();
        for (int j = i + 1; j < N; j++) {
            int tmp = height[i] < height[j] ? -1: 1;
            tmp += 2 * (sum(height[i]) - sum(height[j]));
            if (tmp > result) {
                result = tmp;
                a = i + 1; b = j + 1;
            }
            inc(height[j]);
        }
    }

    if (result <= 0) {
        cout << -1 << ' ' << -1 << endl;
    } else {
        cout << a << ' ' << b << endl;
    }
}
