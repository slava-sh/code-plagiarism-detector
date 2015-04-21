#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> divisors;
map< pair<int, int>, int> table;

void factorize(int n) {
    divisors.clear();
    int i = 1;
    while (i * i < n) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n / i);
        }
        i++;
    }
    if (i * i == n) divisors.push_back(i);
    //sort(divisors.begin(), divisors.end());
}

/*int f(int n, int k) {
    if (n == 1 || k == 1) return (n + 1) >> 1;
    int i;
    for (i = 2; i * i <= n && n % i; i++);
    if (n % i) return (n + 1) >> 1;
    return (i + 1) / 2 * f(n / i, k - 1);
}*/

int f2(int n, int k) {
    if (table.find(make_pair(n, k)) != table.end()) return table[make_pair(n, k)];
    if (n == 1 || k == 1) return (n + 1) >> 1;
    int result = (n + 1) >> 1;
    for (auto d: divisors) {
        if (n % d == 0) {
            result = min(result, (d + 1) / 2 * f2(n / d, k - 1));
        }
    }
    table[make_pair(n, k)] = result;
    return result;
}

main() {
    for (int j = 1; j <= 10; j++) {
        for (int i = 1; i < 1e4; i++) {
            factorize(i);
            if (divisors.size() == 1) {
                for (int t = 1; t <= 10; t++) {
                    table[make_pair(i, t)] = (i + 1) >> 1;
                }
            }
            f2(i, j);
        }
    }

    int n, k;
    cin >> n >> k;

    factorize(n);
    cout << f2(n, k) << endl;

    return 0;
}
